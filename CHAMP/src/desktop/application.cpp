#include "application.hpp"
#include "imgui_stdlib.h"
#include "paths.hpp"
#include <algorithm>
#include <chrono>
#include <cmath>
#include <deque>
#include <mutex>
#include <sstream>
#include <stdexcept>

namespace legacy::desktop {
using namespace champ;
namespace {
constexpr ImU32 surveyed_color = IM_COL32(104, 126, 151, 255),
                adjusted_color = IM_COL32(40, 109, 159, 255),
                eroded_color = IM_COL32(219, 127, 44, 255);
struct DialogRequest {
  int operation;
  std::string suggested;
};
struct DialogResult {
  int operation;
  std::filesystem::path path;
  std::string error;
};
std::mutex dialog_mutex;
std::deque<DialogResult> dialog_results;
void SDLCALL selected_file(void *userdata, const char *const *paths, int) {
  std::unique_ptr<DialogRequest> request(
      static_cast<DialogRequest *>(userdata));
  DialogResult result{request->operation, {}, {}};
  if (!paths)
    result.error = SDL_GetError();
  else if (paths[0])
    result.path = utf8_path(paths[0]);
  else
    result.operation = -1;
  std::lock_guard lock(dialog_mutex);
  dialog_results.push_back(std::move(result));
}
std::string clean_report(std::string s) {
  for (auto &c : s) {
    if (c == '\0')
      c = ' ';
    if (c == '\f')
      c = '\n';
  }
  return s;
}
void heading(const char *title, const char *detail = nullptr) {
  ImGui::TextUnformatted(title);
  if (detail) {
    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(.39f, .45f, .52f, 1));
    ImGui::TextWrapped("%s", detail);
    ImGui::PopStyleColor();
  }
  ImGui::Spacing();
}
std::string scenario_key(Scenario s) {
  return s == Scenario::annual_0_2_percent ? "500" : "100";
}
const Json *analysis_document(const Project &p, std::string_view id, Scenario s,
                              const char *engine) {
  auto t = p.documents.find(std::string(id));
  if (t == p.documents.end())
    return nullptr;
  auto scenario = t->find(scenario_key(s));
  if (scenario == t->end())
    return nullptr;
  auto e = scenario->find(engine);
  return e == scenario->end() ? nullptr : &*e;
}
std::vector<TransectPoint> wave_series(const Project &p, const std::string &id,
                                       Scenario s, const char *field) {
  std::vector<TransectPoint> points;
  for (const auto &r : p.rows(scenario_table("WHAFIS PART 2", s), id))
    points.push_back({numeric(r, "STATION"), numeric(r, field), ""});
  return points;
}
} // namespace
Application::Application(SDL_Window *window, ImFont *monospace)
    : window_(window), monospace_(monospace) {}

Application::Draft Application::draft_state() const {
  return {parameters_, points_, cards_, deck_, runup_rows_};
}
bool Application::has_drafts() const {
  if (!project_)
    return false;
  if (raw_table_ != table_baseline_)
    return true;
  if (!draft_baseline_ || selected_.empty())
    return false;
  const auto &b = *draft_baseline_;
  return parameters_ != b.parameters || points_ != b.points ||
         cards_ != b.cards || deck_ != b.deck || runup_rows_ != b.runup;
}
bool Application::apply_drafts() {
  if (!has_drafts())
    return true;
  try {
    auto candidate = *project_;
    const auto current = draft_state();
    const auto baseline = draft_baseline_.value_or(current);
    if ((current.parameters != baseline.parameters))
      candidate.set_parameters(selected_, scenario_, parameters_);
    if ((current.points != baseline.points))
      candidate.set_profile(selected_, static_cast<ProfileKind>(profile_kind_),
                            points_, scenario_);
    if ((current.cards != baseline.cards) && (current.deck != baseline.deck))
      throw std::invalid_argument(
          "The WHAFIS card table and full input deck both have edits. Apply "
          "one editor or reload the project before continuing.");
    if ((current.cards != baseline.cards)) {
      auto edited = cards_;
      for (std::size_t i = 0; i < edited.size(); ++i)
        if (i >= baseline.cards.size() || current.cards[i] != baseline.cards[i])
          edited[i].text.clear();
      candidate.set_whafis_cards(selected_, scenario_, edited);
    }
    if ((current.deck != baseline.deck))
      candidate.set_whafis_cards(selected_, scenario_,
                                 read_whafis_cards(deck_));
    if ((current.runup != baseline.runup)) {
      for (const auto &r : runup_rows_) {
        const auto rough = numeric(r, "ROUGHNESS COEFF", 1);
        if (!std::isfinite(rough) || rough < 0 || rough > 1)
          throw std::invalid_argument(
              "Roughness coefficients must be between 0 and 1.");
      }
      candidate.replace_rows(scenario_table("RUNUP", scenario_), selected_,
                             runup_rows_);
    }
    if (raw_table_ != table_baseline_) {
      auto rows = Json::parse(raw_table_);
      if (!rows.is_array())
        throw std::invalid_argument("Table rows must be a JSON array.");
      for (const auto &r : rows)
        if (!r.is_object())
          throw std::invalid_argument("Each row must be a JSON object.");
      auto data = candidate.serialize();
      data["tables"][table_name_]["rows"] = rows;
      candidate = Project::deserialize(data);
    }
    remember();
    *project_ = std::move(candidate);
    dirty_ = true;
    const auto controls = erosion_;
    reload();
    erosion_ = controls;
    status_ = "Edits applied";
    return true;
  } catch (const std::exception &e) {
    error_ = e.what();
    status_ = "Correct the pending edits before continuing";
    return false;
  }
}

void Application::guarded(const std::function<void()> &action) {
  try {
    action();
  } catch (const std::exception &e) {
    error_ = e.what();
    status_ = "Action needs attention";
  }
}
void Application::remember() {
  if (!project_)
    return;
  undo_.push_back(project_->serialize());
  if (undo_.size() > 40)
    undo_.erase(undo_.begin());
  redo_.clear();
}
void Application::mutate(const std::string &label,
                         const std::function<void()> &action) {
  if (!apply_drafts())
    return;
  guarded([&] {
    auto before = project_->serialize();
    try {
      action();
    } catch (...) {
      *project_ = Project::deserialize(before);
      throw;
    }
    if (project_->serialize() == before) {
      status_ = label;
      reload();
      return;
    }
    undo_.push_back(std::move(before));
    if (undo_.size() > 40)
      undo_.erase(undo_.begin());
    redo_.clear();
    dirty_ = true;
    status_ = label;
    reload();
  });
}
void Application::undo(bool redo) {
  if (!project_)
    return;
  if (has_drafts()) {
    reload();
    status_ = "Pending edits reverted";
    return;
  }
  auto &source = redo ? redo_ : undo_, &destination = redo ? undo_ : redo_;
  if (source.empty())
    return;
  destination.push_back(project_->serialize());
  *project_ = Project::deserialize(source.back());
  source.pop_back();
  dirty_ = true;
  status_ = redo ? "Redone" : "Undone";
  reload();
}
void Application::reload() {
  plot_.fitted = false;
  raw_table_.clear();
  table_baseline_.clear();
  draft_baseline_.reset();
  erosion_preview_.reset();
  point_selection_ = -1;
  if (!project_)
    return;
  auto ids = project_->transects();
  if (std::find(ids.begin(), ids.end(), selected_) == ids.end())
    selected_ = ids.empty() ? "" : ids.front();
  if (selected_.empty()) {
    points_.clear();
    cards_.clear();
    runup_rows_.clear();
    return;
  }
  parameters_ = project_->parameters(selected_, scenario_);
  points_ = project_->profile(
      selected_, static_cast<ProfileKind>(profile_kind_), scenario_);
  cards_ = project_->whafis_cards(selected_, scenario_);
  deck_ = write_whafis_input(textual(project_->metadata(), "TITLE") +
                                 " - Transect: " + selected_,
                             cards_, scenario_);
  runup_rows_ = project_->rows(scenario_table("RUNUP", scenario_), selected_);
  std::stable_sort(runup_rows_.begin(), runup_rows_.end(),
                   [](const auto &a, const auto &b) {
                     return numeric(a, "STATION_B") < numeric(b, "STATION_B");
                   });
  try {
    erosion_ = project_->erosion_settings(selected_, scenario_);
  } catch (const std::exception &) {
    erosion_ = {};
  }
  draft_baseline_ = draft_state();
}
void Application::open(const std::filesystem::path &path) {
  guarded([&] {
    auto p = Project::open(path);
    project_ = std::move(p);
    path_ = path;
    dirty_ = false;
    undo_.clear();
    redo_.clear();
    selected_.clear();
    profile_kind_ = 0;
    page_ = 0;
    status_ = "Opened " + utf8_text(path.filename());
    reload();
  });
}
void Application::open_example() {
  const auto base = utf8_path(SDL_GetBasePath());
  open(base / "examples/Coastal-Town.coastal");
  if (project_) {
    path_.clear();
    dirty_ = false;
    status_ = "Example project — save a copy to keep your changes";
  }
}
void Application::new_project() {
  project_ = Project::create();
  project_->add_transect("1");
  path_.clear();
  selected_ = "1";
  dirty_ = true;
  undo_.clear();
  redo_.clear();
  page_ = 0;
  status_ = "New project";
  reload();
}
void Application::ask_discard(std::function<void()> action) {
  if (dirty_ || has_drafts()) {
    after_discard_ = std::move(action);
    discard_popup_ = true;
  } else
    action();
}
void Application::request_open(const std::filesystem::path &path) {
  if (worker_.valid() || dialog_pending_)
    return;
  ask_discard([this, path] { open(path); });
}
void Application::request_quit() {
  if (worker_.valid() || dialog_pending_) {
    status_ = "Finish the current calculation or file dialog before closing.";
    return;
  }
  ask_discard([this] { quit_ = true; });
}
void Application::dialog(int operation, const std::string &suggested) {
  if (dialog_pending_)
    return;
  dialog_pending_ = true;
  static const SDL_DialogFileFilter project_filters[] = {
      {"Coastal projects", "coastal;mdb"}, {"All files", "*"}};
  static const SDL_DialogFileFilter profile_filters[] = {
      {"Profile data", "csv;tsv;txt;dxf"}, {"All files", "*"}};
  static const SDL_DialogFileFilter model_filters[] = {
      {"Model input", "dat;in;txt"}, {"All files", "*"}};
  auto *request = new DialogRequest{operation, suggested};
  if (operation == 1 || operation == 3)
    SDL_ShowSaveFileDialog(
        selected_file, request, window_, nullptr, 0,
        request->suggested.empty() ? nullptr : request->suggested.c_str());
  else
    SDL_ShowOpenFileDialog(selected_file, request, window_,
                           operation == 0   ? project_filters
                           : operation == 2 ? profile_filters
                                            : model_filters,
                           2, nullptr, false);
}
void Application::save(bool save_as) {
  if (!apply_drafts())
    return;
  if (!project_)
    return;
  const auto ext = path_.extension().string();
  if (save_as || path_.empty() || ext == ".mdb" || ext == ".MDB") {
    dialog(1, path_.empty()
                  ? "Coastal project.coastal"
                  : utf8_text(std::filesystem::path(path_).replace_extension(
                        ".coastal")));
    return;
  }
  guarded([&] {
    project_->save(path_);
    dirty_ = false;
    status_ = "Saved " + utf8_text(path_.filename());
    if (after_discard_) {
      auto next = std::move(after_discard_);
      after_discard_ = {};
      next();
    }
  });
}
void Application::poll() {
  std::deque<DialogResult> results;
  {
    std::lock_guard lock(dialog_mutex);
    results.swap(dialog_results);
  }
  for (const auto &r : results) {
    dialog_pending_ = false;
    SDL_RaiseWindow(window_);
    if (r.operation == -1) {
      after_discard_ = {};
      continue;
    }
    if (!r.error.empty()) {
      error_ = r.error;
      continue;
    }
    guarded([&] {
      if (r.operation == 0)
        ask_discard([this, path = r.path] { open(path); });
      else if (r.operation == 1) {
        auto destination = r.path;
        if (destination.extension().empty())
          destination += ".coastal";
        project_->save(destination);
        path_ = destination;
        dirty_ = false;
        status_ = "Project saved";
        if (after_discard_) {
          auto next = std::move(after_discard_);
          after_discard_ = {};
          next();
        }
      } else if (r.operation == 2) {
        imports_ = read_profiles(r.path);
        import_choice_ = 0;
        show_import_ = true;
      } else if (r.operation == 3) {
        write_text_file(r.path, export_text_);
        status_ = "Exported " + utf8_text(r.path.filename());
      } else if (r.operation == 4) {
        deck_ = read_text_file(r.path);
        status_ = "Imported WHAFIS deck — apply it before running";
      }
    });
  }
  if (worker_.valid() &&
      worker_.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
    guarded([&] {
      auto p = worker_.get();
      remember();
      *project_ = std::move(p.project);
      dirty_ = true;
      error_ = p.error;
      status_ = worker_label_ + (p.error.empty()
                                     ? " complete"
                                     : " needs attention — report retained");
      page_ = 5;
      reload();
    });
  }
}
void Application::run_engine(bool runup) {
  if (!project_ || selected_.empty())
    return;
  const auto id = selected_;
  const auto scenario = scenario_;
  result_kind_ = runup ? 1 : 0;
  launch(runup ? "RUNUP" : "WHAFIS", [=](Project &p) {
    if (runup)
      p.run_runup(id, scenario);
    else {
      auto report = p.run_whafis(id, scenario);
      if (!report.error.empty())
        throw std::runtime_error(report.error);
    }
  });
}
void Application::launch(const std::string &label,
                         const std::function<void(Project &)> &action) {
  if (worker_.valid() || !project_)
    return;
  if (!apply_drafts())
    return;
  auto copy = *project_;
  worker_label_ = label;
  status_ = "Calculating " + label + "…";
  worker_ = std::async(std::launch::async,
                       [copy = std::move(copy), action]() mutable {
                         std::string error;
                         try {
                           action(copy);
                         } catch (const std::exception &e) {
                           error = e.what();
                         }
                         return Calculation{std::move(copy), std::move(error)};
                       });
}
bool Application::float_input(const char *label, float &value,
                              const char *format) {
  ImGui::SetNextItemWidth(-1);
  return ImGui::InputFloat(label, &value, 0, 0, format);
}
void Application::edit_metadata(Json &row, const char *field,
                                const char *label) {
  auto value = textual(row, field);
  ImGui::TextUnformatted(label);
  ImGui::SetNextItemWidth(-1);
  const bool changed =
      ImGui::InputText((std::string("##") + field).c_str(), &value);
  if (ImGui::IsItemActivated())
    field_edit_ = project_->serialize();
  if (changed) {
    row[field] = value;
    dirty_ = true;
  }
  if (ImGui::IsItemDeactivatedAfterEdit() && field_edit_) {
    undo_.push_back(*field_edit_);
    redo_.clear();
    field_edit_.reset();
  }
}
void Application::menu() {
  if (!ImGui::BeginMenuBar())
    return;
  if (ImGui::BeginMenu("File")) {
    if (ImGui::MenuItem("New project", "Ctrl/Cmd+N"))
      ask_discard([this] { new_project(); });
    if (ImGui::MenuItem("Open project…", "Ctrl/Cmd+O"))
      dialog(0);
    if (ImGui::MenuItem("Open example"))
      ask_discard([this] { open_example(); });
    ImGui::Separator();
    if (ImGui::MenuItem("Save", "Ctrl/Cmd+S", false, bool(project_)))
      save();
    if (ImGui::MenuItem("Save as…", nullptr, false, bool(project_)))
      save(true);
    ImGui::Separator();
    if (ImGui::MenuItem("Close"))
      request_quit();
    ImGui::EndMenu();
  }
  if (ImGui::BeginMenu("Edit")) {
    if (ImGui::MenuItem("Undo", "Ctrl/Cmd+Z", false, !undo_.empty()))
      undo();
    if (ImGui::MenuItem("Redo", "Ctrl/Cmd+Shift+Z", false, !redo_.empty()))
      undo(true);
    ImGui::EndMenu();
  }
  if (ImGui::BeginMenu("Help")) {
    if (ImGui::MenuItem("Getting started"))
      page_ = 7;
    if (ImGui::MenuItem("About Legacy Coastal"))
      show_about_ = true;
    ImGui::EndMenu();
  }
  ImGui::EndMenuBar();
}
void Application::welcome() {
  ImGui::SetCursorPos({60, 100});
  ImGui::BeginGroup();
  ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(.1f, .25f, .35f, 1));
  ImGui::SetWindowFontScale(1.9f);
  ImGui::TextUnformatted("Legacy Coastal");
  ImGui::SetWindowFontScale(1);
  ImGui::PopStyleColor();
  ImGui::Spacing();
  ImGui::TextUnformatted("CHAMP • WHAFIS • RUNUP");
  ImGui::Spacing();
  ImGui::TextWrapped("Prepare coastal transects, assess dune erosion, and "
                     "calculate wave heights and runup.");
  ImGui::Dummy({0, 25});
  if (ImGui::Button("Open the example project", {330, 52}))
    open_example();
  ImGui::Dummy({0, 8});
  if (ImGui::Button("Open a project…", {330, 44}))
    dialog(0);
  ImGui::Dummy({0, 8});
  if (ImGui::Button("Create a new project", {330, 44}))
    new_project();
  ImGui::Dummy({0, 30});
  ImGui::TextDisabled(
      "Opens original CHAMP .mdb files and native .coastal projects.");
  ImGui::TextDisabled("Calculations run on your computer.");
  ImGui::EndGroup();
}
void Application::sidebar() {
  heading("LEGACY COASTAL");
  ImGui::TextWrapped("%s", textual(project_->metadata(), "TITLE").c_str());
  ImGui::Separator();
  ImGui::TextUnformatted("Transect");
  ImGui::SetNextItemWidth(-1);
  if (ImGui::BeginCombo("##transect", selected_.empty() ? "Choose a transect"
                                                        : selected_.c_str())) {
    for (const auto &id : project_->transects())
      if (ImGui::Selectable(id.c_str(), id == selected_)) {
        if (apply_drafts()) {
          selected_ = id;
          reload();
        }
      }
    ImGui::EndCombo();
  }
  if (ImGui::Button("Add", {58, 0})) {
    new_id_.clear();
    ImGui::OpenPopup("Add transect");
  }
  ImGui::SameLine();
  if (ImGui::Button("Copy", {58, 0}) && !selected_.empty()) {
    new_id_ = selected_ + " copy";
    ImGui::OpenPopup("Copy transect");
  }
  ImGui::SameLine();
  if (ImGui::Button("More", {58, 0}))
    ImGui::OpenPopup("Transect options");
  for (const auto name : {"Add transect", "Copy transect", "Rename transect"})
    if (ImGui::BeginPopup(name)) {
      ImGui::InputText("ID (15 characters)", &new_id_);
      if (ImGui::Button("Apply")) {
        const auto source = selected_, dest = new_id_;
        mutate(name, [&] {
          if (std::string(name) == "Add transect")
            project_->add_transect(dest);
          else if (std::string(name) == "Copy transect")
            project_->copy_transect(source, dest);
          else
            project_->rename_transect(source, dest);
          selected_ = dest;
        });
        ImGui::CloseCurrentPopup();
      }
      ImGui::EndPopup();
    }
  bool rename_requested = false;
  if (ImGui::BeginPopup("Transect options")) {
    if (ImGui::MenuItem("Rename")) {
      new_id_ = selected_;
      ImGui::CloseCurrentPopup();
      rename_requested = true;
    }
    if (ImGui::MenuItem("Delete transect")) {
      auto id = selected_;
      mutate("Deleted transect", [&] { project_->delete_transect(id); });
    }
    ImGui::EndPopup();
  }
  if (rename_requested)
    ImGui::OpenPopup("Rename transect");
  ImGui::Dummy({0, 15});
  ImGui::TextUnformatted("Annual chance");
  bool five = scenario_ == Scenario::annual_0_2_percent;
  if (ImGui::RadioButton("1% / 100-year", !five) && apply_drafts()) {
    scenario_ = Scenario::annual_1_percent;
    reload();
  }
  if (ImGui::RadioButton("0.2% / 500-year", five) && apply_drafts()) {
    scenario_ = Scenario::annual_0_2_percent;
    reload();
  }
  ImGui::Dummy({0, 12});
  ImGui::Separator();
  const char *pages[] = {"1  Project & parameters",
                         "2  Transect profile",
                         "3  Erosion treatment",
                         "4  WHAFIS wave heights",
                         "5  RUNUP",
                         "6  Results & exports",
                         "    Project tables",
                         "    Getting started"};
  for (int i = 0; i < 8; ++i)
    if (ImGui::Selectable(pages[i], page_ == i, 0, {0, 34}))
      page_ = i;
  ImGui::Dummy({0, 15});
  if (ImGui::Button("Save project", {-1, 36}))
    save();
  ImGui::TextDisabled("%s", dirty_ || has_drafts() ? "Unsaved changes"
                                                   : "Saved / unchanged");
}
void Application::overview() {
  heading("Project & transect parameters",
          "Set the project identity and the water/wave conditions for the "
          "selected scenario.");
  if (ImGui::BeginTable("metadata", 2, ImGuiTableFlags_SizingStretchSame)) {
    for (const auto &field : std::vector<std::pair<const char *, const char *>>{
             {"TITLE", "Project title"},
             {"ENGINEER NAME", "Modeler"},
             {"COMMUNITY NAME", "Community"},
             {"CLIENT NAME", "Client"},
             {"VDATUM", "Vertical datum"},
             {"PROJECTION", "Projection"}}) {
      ImGui::TableNextColumn();
      edit_metadata(project_->metadata(), field.first, field.second);
    }
    ImGui::EndTable();
  }
  if (selected_.empty()) {
    ImGui::TextWrapped("Add a transect to begin entering a profile.");
    return;
  }
  ImGui::SeparatorText("Transect");
  if (ImGui::BeginTable("detail", 2)) {
    ImGui::TableNextColumn();
    edit_metadata(project_->transect(selected_), "LOC_DES",
                  "Location / description");
    ImGui::TableNextColumn();
    edit_metadata(project_->transect(selected_), "SFLOOD", "Flooding source");
    ImGui::EndTable();
  }
  ImGui::SeparatorText(scenario_ == Scenario::annual_0_2_percent
                           ? "0.2% annual chance conditions"
                           : "1% annual chance conditions");
  if (ImGui::BeginTable("parameters", 3, ImGuiTableFlags_SizingStretchSame)) {
    const auto input = [&](const char *label, float &v) {
      ImGui::TableNextColumn();
      ImGui::TextUnformatted(label);
      float_input((std::string("##") + label).c_str(), v);
    };
    input("Stillwater elevation (ft)", parameters_.stillwater);
    input("Significant wave height (ft)", parameters_.significant_height);
    input("Peak wave period (s)", parameters_.peak_period);
    input("Wave setup (ft)", parameters_.wave_setup);
    input("10-year stillwater (ft)", parameters_.ten_year_stillwater);
    input("50-year stillwater (ft)", parameters_.fifty_year_stillwater);
    input("Fetch length (miles)", parameters_.fetch_miles);
    input("Inland wind (mph)", parameters_.wind_inland);
    input("Overwater wind (mph)", parameters_.wind_overwater);
    input("Vegetation wind (mph)", parameters_.wind_vegetation);
    input("Mean wave height (ft)", parameters_.mean_height);
    input("Mean period (s)", parameters_.mean_period);
    input("Wave spread (%)", parameters_.spread_percent);
    input("Last slope, H/V", parameters_.last_slope);
    ImGui::EndTable();
  }
  if (ImGui::Button("Derive mean waves")) {
    parameters_.mean_height =
        float(double(parameters_.significant_height) * .626);
    parameters_.mean_period = float(double(parameters_.peak_period) * .85);
  }
  ImGui::SameLine();
  ImGui::TextDisabled("Height × 0.626; period × 0.85");
  if (ImGui::Button("Apply parameters", {190, 36}))
    apply_drafts();
  ImGui::Spacing();
  ImGui::TextWrapped(
      "Model geometry and water levels use feet. Choose the vertical datum "
      "consistently for the profile and water levels. Both scenarios retain "
      "their own erosion and analysis results.");
}
std::vector<PlotSeries> Application::profile_series(bool draft) const {
  std::vector<PlotSeries> result;
  if (!project_ || selected_.empty())
    return result;
  for (int k = 0; k < 3; ++k) {
    auto points = draft && k == profile_kind_
                      ? points_
                      : project_->profile(
                            selected_, static_cast<ProfileKind>(k), scenario_);
    if (!points.empty())
      result.push_back({k == 0   ? "Surveyed"
                        : k == 1 ? "Adjusted"
                                 : "Eroded",
                        std::move(points),
                        k == 0   ? surveyed_color
                        : k == 1 ? adjusted_color
                                 : eroded_color,
                        k == profile_kind_});
  }
  return result;
}
std::vector<PlotSeries> Application::result_series() const {
  auto series = profile_series();
  if (result_kind_ == 0)
    series.push_back(
        {"Wave crest",
         wave_series(*project_, selected_, scenario_, "WAVE CREST ELEVATION"),
         IM_COL32(0, 152, 134, 255), false});
  else if (result_kind_ == 1) {
    const auto *document =
        analysis_document(*project_, selected_, scenario_, "runup");
    if (document && document->contains("two_percent_elevation") &&
        !series.empty()) {
      const auto &ground = series.back().points;
      if (ground.size() >= 2) {
        const auto level = numeric(*document, "two_percent_elevation");
        series.push_back({"2% runup elevation",
                          {{ground.front().station, level, ""},
                           {ground.back().station, level, ""}},
                          IM_COL32(0, 152, 134, 255),
                          false});
      }
    }
  }
  return series;
}
void Application::export_plot(bool dxf) {
  std::vector<ProfileImport> profiles;
  for (const auto &s : page_ == 5 ? result_series() : profile_series())
    profiles.push_back({s.label, s.points});
  export_text_ = dxf ? profiles_dxf(profiles)
                     : profiles_svg(textual(project_->metadata(), "TITLE") +
                                        " / Transect " + selected_,
                                    profiles);
  dialog(3, "Transect-" + selected_ + (dxf ? ".dxf" : ".svg"));
}
void Application::transect_page() {
  heading("Transect profile",
          "Stations increase from sea to land. Edit the table, import a "
          "profile, or paste station/elevation columns.");
  const char *kinds[] = {"Surveyed", "Adjusted", "Eroded"};
  int next_kind = profile_kind_;
  if (ImGui::Combo("Profile", &next_kind, kinds, 3) && apply_drafts()) {
    profile_kind_ = next_kind;
    reload();
  }
  if (ImGui::Button("Import CSV / DXF…"))
    dialog(2);
  ImGui::SameLine();
  if (ImGui::Button("Paste columns…"))
    ImGui::OpenPopup("Paste profile");
  ImGui::SameLine();
  if (ImGui::Button("Adjust shoreline"))
    mutate("Shoreline adjusted", [&] {
      project_->adjust(selected_);
      profile_kind_ = 1;
    });
  ImGui::SameLine();
  if (ImGui::Button("Fit plot"))
    plot_.fitted = false;
  plot("profile", plot_, profile_series(true), {0, 280},
       parameters_.stillwater);
  if (ImGui::BeginTable("profile_rows", 4,
                        ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg |
                            ImGuiTableFlags_ScrollY,
                        {0, 250})) {
    ImGui::TableSetupColumn("#", ImGuiTableColumnFlags_WidthFixed, 40);
    ImGui::TableSetupColumn("Station (ft)");
    ImGui::TableSetupColumn("Elevation (ft)");
    ImGui::TableSetupColumn("Source");
    ImGui::TableSetupScrollFreeze(0, 1);
    ImGui::TableHeadersRow();
    ImGuiListClipper clipper;
    clipper.Begin(int(points_.size()));
    while (clipper.Step())
      for (int i = clipper.DisplayStart; i < clipper.DisplayEnd; ++i) {
        ImGui::PushID(i);
        ImGui::TableNextRow();
        ImGui::TableNextColumn();
        if (ImGui::Selectable(std::to_string(i + 1).c_str(),
                              point_selection_ == i))
          point_selection_ = i;
        ImGui::TableNextColumn();
        float_input("##station", points_[i].station, "%.6g");
        ImGui::TableNextColumn();
        float_input("##elevation", points_[i].elevation, "%.6g");
        ImGui::TableNextColumn();
        ImGui::SetNextItemWidth(-1);
        ImGui::InputText("##source", &points_[i].source);
        ImGui::PopID();
      }
    ImGui::EndTable();
  }
  if (ImGui::Button("Insert point")) {
    std::size_t at =
        point_selection_ < 0
            ? points_.size()
            : std::min(std::size_t(point_selection_ + 1), points_.size());
    TransectPoint p{0, 0, "Entered"};
    if (at && at < points_.size()) {
      p.station = (points_[at - 1].station + points_[at].station) * .5f;
      p.elevation = (points_[at - 1].elevation + points_[at].elevation) * .5f;
    } else if (at) {
      p.station = points_.back().station + 100;
      p.elevation = points_.back().elevation;
    }
    points_.insert(points_.begin() + at, p);
    point_selection_ = int(at);
  }
  ImGui::SameLine();
  if (ImGui::Button("Remove selected") && point_selection_ >= 0 &&
      point_selection_ < int(points_.size())) {
    points_.erase(points_.begin() + point_selection_);
    point_selection_ = -1;
  }
  ImGui::SameLine();
  if (ImGui::Button("Apply profile"))
    apply_drafts();
  ImGui::SameLine();
  if (ImGui::Button("Export CSV…")) {
    export_text_ = profile_csv(points_);
    dialog(3, "Transect-" + selected_ + ".csv");
  }
  ImGui::SameLine();
  if (ImGui::Button("Export SVG…"))
    export_plot(false);
  ImGui::SameLine();
  if (ImGui::Button("Export DXF…"))
    export_plot(true);
  if (ImGui::BeginPopupModal("Paste profile", nullptr,
                             ImGuiWindowFlags_AlwaysAutoResize)) {
    ImGui::TextUnformatted(
        "Station, elevation, optional source. CSV, tabs, or spaces.");
    ImGui::InputTextMultiline("##paste", &profile_paste_, {600, 240});
    if (ImGui::Button("Read columns")) {
      guarded([&] {
        imports_ = parse_profile_text(profile_paste_);
        show_import_ = true;
      });
      ImGui::CloseCurrentPopup();
    }
    ImGui::SameLine();
    if (ImGui::Button("Cancel"))
      ImGui::CloseCurrentPopup();
    ImGui::EndPopup();
  }
}
void Application::erosion_page() {
  heading("Erosion treatment",
          "Select points on the adjusted profile. Preview the treatment, then "
          "save the eroded profile for wave analysis.");
  const auto ground =
      project_->profile(selected_, ProfileKind::adjusted, scenario_);
  if (ground.size() < 2) {
    ImGui::TextWrapped(
        "Adjust the surveyed transect on the Profile page first.");
    return;
  }
  const char *picks[] = {"Navigate", "Select peak", "Select toe", "Select face",
                         "Select seaward"};
  for (int i = 0; i < 5; ++i) {
    if (i)
      ImGui::SameLine();
    if (ImGui::RadioButton(picks[i], erosion_pick_ == i))
      erosion_pick_ = i;
  }
  auto series = profile_series();
  if (erosion_preview_)
    series.push_back({"Preview", erosion_preview_->profile,
                      IM_COL32(0, 155, 139, 255), true});
  if (auto chosen = plot("erosion", plot_, series, {0, 360},
                         project_->parameters(selected_, scenario_).stillwater,
                         erosion_pick_ != 0)) {
    if (erosion_pick_ == 1)
      erosion_.peak_station = chosen->station;
    else if (erosion_pick_ == 2)
      erosion_.toe_station = chosen->station;
    else if (erosion_pick_ == 3)
      erosion_.face_station = chosen->station;
    else if (erosion_pick_ == 4)
      erosion_.seaward = *chosen;
    erosion_preview_.reset();
    status_ = "Point selected — preview to calculate the treatment";
  }
  if (ImGui::BeginTable("erosion_controls", 4)) {
    const auto input = [&](const char *label, float &v) {
      ImGui::TableNextColumn();
      ImGui::TextUnformatted(label);
      float_input((std::string("##") + label).c_str(), v);
    };
    input("Peak station", erosion_.peak_station);
    input("Toe station", erosion_.toe_station);
    input("Face station", erosion_.face_station);
    input("Seaward station", erosion_.seaward.station);
    input("Face slope H/V", erosion_.face_slope);
    input("Approach slope H/V", erosion_.approach_slope);
    input("Seaward slope H/V", erosion_.seaward_slope);
    input("Removal slope H/V", erosion_.removal_slope);
    ImGui::EndTable();
  }
  if (ImGui::Button("Preview treatment", {180, 36}))
    guarded([&] {
      erosion_preview_ =
          assess_erosion(ground, project_->parameters(selected_, scenario_),
                         erosion_, scenario_);
    });
  ImGui::SameLine();
  if (ImGui::Button("Save eroded profile", {190, 36}))
    mutate("Eroded profile saved",
           [&] { project_->erode(selected_, scenario_, erosion_); });
  ImGui::SameLine();
  if (ImGui::Button("Clear treatment"))
    mutate("Erosion cleared",
           [&] { project_->clear_erosion(selected_, scenario_); });
  ImGui::SameLine();
  if (ImGui::Button("Fit plot"))
    plot_.fitted = false;
  if (erosion_preview_) {
    const auto &e = *erosion_preview_;
    ImGui::SeparatorText(e.retreat ? "DUNE RETREAT" : "DUNE REMOVAL");
    ImGui::Text("Reservoir: %.2f ft²    Critical area: %.0f ft²",
                e.reservoir_area, e.critical_area);
    ImGui::Text(
        "Eroded: %.2f ft²    Above stillwater: %.2f ft²    Deposited: %.2f ft²",
        e.eroded_area, e.eroded_above_stillwater, e.deposited_area);
    if (e.retreat)
      ImGui::TextWrapped(
          "Move the face until erosion above stillwater approaches the "
          "critical area. Move the seaward point until the deposited area "
          "approaches the total eroded area.");
  } else {
    auto stored =
        project_->rows(scenario_table("GEOMETRY", scenario_), selected_);
    if (!stored.empty())
      ImGui::Text("Saved treatment: %s    Reservoir %.0f ft²",
                  textual(stored.front(), "EROSION_STATUS").c_str(),
                  numeric(stored.front(), "RESERVOIR_AREA"));
  }
}
void Application::whafis_page() {
  heading("WHAFIS wave heights",
          "Prepare from the erosion/adjusted profile, assign obstruction "
          "cards, then run the wave-height model.");
  if (ImGui::Button("Populate from profile"))
    mutate("WHAFIS cards prepared",
           [&] { project_->populate_whafis(selected_, scenario_); });
  ImGui::SameLine();
  if (ImGui::Button("Import input…"))
    dialog(4);
  ImGui::SameLine();
  if (ImGui::Button("Run WHAFIS", {155, 36}))
    run_engine(false);
  ImGui::TextWrapped(
      "IE = initial conditions; IF/OF = inland/overwater fetch; DU = dune; BU "
      "= buildings; VE = trees; VH/MG = vegetation; AS = additional surge; ET "
      "= end. CM and PS retain comments.");
  if (ImGui::BeginTable("cards", 12,
                        ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg |
                            ImGuiTableFlags_ScrollX | ImGuiTableFlags_ScrollY,
                        {0, 330})) {
    ImGui::TableSetupColumn("#", ImGuiTableColumnFlags_WidthFixed, 35);
    ImGui::TableSetupColumn("Card", ImGuiTableColumnFlags_WidthFixed, 60);
    for (int i = 0; i < 10; ++i)
      ImGui::TableSetupColumn(("Field " + std::to_string(i + 1)).c_str(),
                              ImGuiTableColumnFlags_WidthFixed, 90);
    ImGui::TableSetupScrollFreeze(2, 1);
    ImGui::TableHeadersRow();
    for (std::size_t i = 0; i < cards_.size(); ++i) {
      ImGui::PushID(int(i));
      auto &c = cards_[i];
      ImGui::TableNextRow();
      ImGui::TableNextColumn();
      if (ImGui::Selectable(std::to_string(i + 1).c_str(),
                            card_selection_ == int(i)))
        card_selection_ = int(i);
      ImGui::TableNextColumn();
      ImGui::SetNextItemWidth(-1);
      ImGui::InputText("##code", &c.kind);
      for (int f = 0; f < 10; ++f) {
        ImGui::TableNextColumn();
        ImGui::SetNextItemWidth(-1);
        ImGui::InputText(("##" + std::to_string(f)).c_str(), &c.fields[f]);
      }
      ImGui::PopID();
    }
    ImGui::EndTable();
  }
  if (ImGui::Button("Insert card")) {
    auto at = std::find_if(cards_.begin(), cards_.end(),
                           [](const auto &c) { return c.kind == "ET"; });
    if (card_selection_ >= 0 && card_selection_ < int(cards_.size()))
      at = cards_.begin() + card_selection_;
    cards_.insert(at, {"IF", {}, {}});
  }
  ImGui::SameLine();
  if (ImGui::Button("Remove selected") && card_selection_ >= 0 &&
      card_selection_ < int(cards_.size())) {
    cards_.erase(cards_.begin() + card_selection_);
    card_selection_ = -1;
  }
  ImGui::SameLine();
  if (ImGui::Button("Apply card table")) {
    deck_ = draft_baseline_->deck;
    if (apply_drafts())
      reload();
  }
  ImGui::SameLine();
  if (ImGui::Button("Export input…")) {
    export_text_ = write_whafis_input(textual(project_->metadata(), "TITLE") +
                                          " - Transect: " + selected_,
                                      cards_, scenario_);
    dialog(3, "w" + selected_ + ".dat");
  }
  if (ImGui::CollapsingHeader("Full input deck / comments / marsh cards")) {
    ImGui::TextWrapped("This editor retains fixed-column records. Apply the "
                       "deck to transfer it into the project.");
    ImGui::PushFont(monospace_, 17);
    ImGui::InputTextMultiline("##deck", &deck_, {-1, 230},
                              ImGuiInputTextFlags_AllowTabInput);
    ImGui::PopFont();
    if (ImGui::Button("Apply input deck")) {
      cards_ = project_->whafis_cards(selected_, scenario_);
      if (apply_drafts())
        reload();
    }
  }
  if (ImGui::CollapsingHeader("Card field guide")) {
    ImGui::TextWrapped(
        "All standard cards begin with end station and end elevation, except "
        "IE (start station/elevation). IE fields 3–10: fetch miles, 10-year "
        "surge, total stillwater, controlling wave height, wave period, inland "
        "wind, overwater wind, vegetation wind. IF/OF fields 3–4: replacement "
        "10-year and total surge. BU fields 3–4: row count and open-space "
        "fraction. VH fields 3–8: region 1, weight, region 2, plant-type "
        "count, replacement 10-year surge, replacement total surge. Each VH "
        "card requires its following MG records. Use the full input editor for "
        "marsh codes and exact legacy decks.");
  }
}
void Application::runup_page() {
  heading("RUNUP", "Choose 2 to 20 points, set surface roughness, and run the "
                   "nine-wave combination from the transect parameters.");
  if (ImGui::Button("Populate from profile"))
    mutate("RUNUP selection prepared",
           [&] { project_->populate_runup(selected_, scenario_); });
  ImGui::SameLine();
  if (ImGui::Button("Run RUNUP", {155, 36}))
    run_engine(true);
  std::size_t included = 0;
  std::vector<TransectPoint> selected;
  for (const auto &r : runup_rows_)
    if (numeric(r, "REMOVESTATUS") == 0) {
      ++included;
      selected.push_back(
          {numeric(r, "STATION_B"), numeric(r, "ELEVATION_B"), ""});
    }
  auto series = profile_series();
  series.push_back(
      {"RUNUP selection", selected, IM_COL32(0, 154, 138, 255), true});
  plot("runup_profile", plot_, series, {0, 250}, parameters_.stillwater);
  ImGui::Text("%zu selected points / maximum 20", included);
  if (ImGui::BeginTable("runup_points", 5,
                        ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg |
                            ImGuiTableFlags_ScrollY,
                        {0, 270})) {
    ImGui::TableSetupColumn("Use", ImGuiTableColumnFlags_WidthFixed, 45);
    ImGui::TableSetupColumn("Station (ft)");
    ImGui::TableSetupColumn("Elevation (ft)");
    ImGui::TableSetupColumn("Roughness");
    ImGui::TableSetupColumn("Surface");
    ImGui::TableSetupScrollFreeze(0, 1);
    ImGui::TableHeadersRow();
    for (std::size_t i = 0; i < runup_rows_.size(); ++i) {
      auto &r = runup_rows_[i];
      ImGui::PushID(int(i));
      ImGui::TableNextRow();
      ImGui::TableNextColumn();
      bool use = numeric(r, "REMOVESTATUS") == 0;
      if (ImGui::Checkbox("##use", &use))
        r["REMOVESTATUS"] = !use;
      ImGui::TableNextColumn();
      ImGui::Text("%.6g", numeric(r, "STATION_B"));
      ImGui::TableNextColumn();
      ImGui::Text("%.6g", numeric(r, "ELEVATION_B"));
      ImGui::TableNextColumn();
      float rough = numeric(r, "ROUGHNESS COEFF", 1);
      if (float_input("##rough", rough, "%.3f"))
        r["ROUGHNESS COEFF"] = rough;
      ImGui::TableNextColumn();
      auto description = textual(r, "SURFACE DESCRIPTION");
      ImGui::SetNextItemWidth(-1);
      if (ImGui::BeginCombo("##surface", description.c_str())) {
        const std::pair<const char *, float> surfaces[] = {
            {"SMOOTH", 1},
            {"TIGHT PAVING", .95f},
            {"TURF", .9f},
            {"LOOSE PAVING", .85f},
            {"STEPS", .8f},
            {"COARSE GRAVEL / GABIONS", .7f},
            {"ROUNDED STONES", .65f},
            {"ARMOR UNITS", .5f}};
        for (const auto &[name, value] : surfaces)
          if (ImGui::Selectable(name, description == name)) {
            r["SURFACE DESCRIPTION"] = name;
            r["ROUGHNESS COEFF"] = value;
          }
        ImGui::EndCombo();
      }
      ImGui::PopID();
    }
    ImGui::EndTable();
  }
  if (ImGui::Button("Apply selection / roughness"))
    apply_drafts();
  ImGui::SameLine();
  if (ImGui::Button("Export input…"))
    guarded([&] {
      export_text_ =
          write_runup_input(project_->runup_profile(selected_, scenario_));
      dialog(3, "r" + selected_ + ".dat");
    });
  ImGui::Text("Mean height %.3f ft × mean period %.3f s; spread ±%.1f%%; last "
              "slope H/V %.3f",
              parameters_.mean_height, parameters_.mean_period,
              parameters_.spread_percent, parameters_.last_slope);
  ImGui::TextWrapped(
      "The original CHAMP setup evaluates low, mean, and high "
      "height against low, mean, and high period. The mean "
      "result is multiplied by 2.23 for the 2%% runup estimate.");
}
void Application::results_page() {
  heading(
      "Results & exports",
      "Review the saved results for this transect and annual-chance scenario.");
  const char *kinds[] = {"WHAFIS wave heights", "RUNUP", "Profiles"};
  if (ImGui::Combo("Analysis", &result_kind_, kinds, 3))
    plot_.fitted = false;
  const char *engine = result_kind_ == 0 ? "whafis" : "runup";
  const Json *document =
      analysis_document(*project_, selected_, scenario_, engine);
  if (document && !textual(*document, "error").empty())
    ImGui::TextWrapped("Calculation incomplete: %s",
                       textual(*document, "error").c_str());
  if (result_kind_ == 0) {
    plot("waves", plot_, result_series(), {0, 340}, parameters_.stillwater);
  } else if (result_kind_ == 1) {
    if (document) {
      ImGui::Text(
          "Average runup %.3f ft     2%% runup %.3f ft     Elevation %.3f ft",
          numeric(*document, "average_runup"),
          numeric(*document, "two_percent_runup"),
          numeric(*document, "two_percent_elevation"));
    } else
      ImGui::Text("Imported average runup: %.3f ft",
                  numeric(project_->transect(selected_),
                          scenario_ == Scenario::annual_0_2_percent
                              ? "AVERAGERUNUP500"
                              : "AVERAGERUNUP"));
    plot("runup_result", plot_, result_series(), {0, 280},
         parameters_.stillwater);
  } else {
    plot("all_profiles", plot_, profile_series(), {0, 430},
         parameters_.stillwater);
    if (ImGui::Button("Export SVG…"))
      export_plot(false);
    ImGui::SameLine();
    if (ImGui::Button("Export DXF…"))
      export_plot(true);
    return;
  }
  auto rows = project_->rows(
      scenario_table(result_kind_ == 0 ? "WHAFIS PART 2" : "RUNUP OUTPUT",
                     scenario_),
      selected_);
  if (ImGui::Button("Export results CSV…")) {
    export_text_ = table_csv(rows);
    dialog(3, engine + std::string("-") + selected_ + ".csv");
  }
  ImGui::SameLine();
  if (ImGui::Button("Export original-format report…") && document) {
    export_text_ = textual(*document, "report");
    dialog(3, engine + std::string("-") + selected_ + ".out");
  }
  ImGui::SameLine();
  if (ImGui::Button("Fit plot"))
    plot_.fitted = false;
  ImGui::SameLine();
  if (ImGui::Button("SVG…"))
    export_plot(false);
  ImGui::SameLine();
  if (ImGui::Button("DXF…"))
    export_plot(true);
  if (!rows.empty()) {
    std::vector<std::string> fields;
    for (auto it = rows.front().begin(); it != rows.front().end(); ++it)
      if (it.key() != "trans_id")
        fields.push_back(it.key());
    if (ImGui::BeginTable("results", int(fields.size()),
                          ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg |
                              ImGuiTableFlags_ScrollX | ImGuiTableFlags_ScrollY,
                          {0, 220})) {
      for (const auto &f : fields)
        ImGui::TableSetupColumn(f.c_str(), ImGuiTableColumnFlags_WidthFixed,
                                145);
      ImGui::TableSetupScrollFreeze(0, 1);
      ImGui::TableHeadersRow();
      ImGuiListClipper clip;
      clip.Begin(int(rows.size()));
      while (clip.Step())
        for (int i = clip.DisplayStart; i < clip.DisplayEnd; ++i) {
          ImGui::TableNextRow();
          for (const auto &f : fields) {
            ImGui::TableNextColumn();
            if (rows[i].contains(f) && rows[i].at(f).is_number())
              ImGui::Text("%.3f", rows[i].at(f).get<double>());
            else
              ImGui::TextUnformatted(textual(rows[i], f).c_str());
          }
        }
      ImGui::EndTable();
    }
  }
  if (document && ImGui::CollapsingHeader("Original-format report")) {
    report_text_ = clean_report(textual(*document, "report"));
    ImGui::PushFont(monospace_, 17);
    ImGui::InputTextMultiline("##report", &report_text_, {-1, 350},
                              ImGuiInputTextFlags_ReadOnly |
                                  ImGuiInputTextFlags_AllowTabInput);
    ImGui::PopFont();
  }
  if (!document)
    ImGui::TextWrapped("This project contains imported result tables. Run the "
                       "analysis to create a new original-format report.");
}
void Application::tables_page() {
  heading("Project tables",
          "Original table names, fields, and values are retained. Export any "
          "table, or edit its JSON rows for advanced project data.");
  auto &name = table_name_;
  ImGui::SetNextItemWidth(320);
  if (ImGui::BeginCombo("Table", name.c_str())) {
    for (const auto &[n, t] : project_->tables)
      if (ImGui::Selectable(n.c_str(), n == name)) {
        if (apply_drafts()) {
          name = n;
          raw_table_.clear();
          table_baseline_.clear();
        }
      }
    ImGui::EndCombo();
  }
  if (!project_->tables.contains(name))
    return;
  auto table = project_->tables.at(name);
  if (raw_table_.empty())
    table_baseline_ = raw_table_ = Json(table.rows).dump(2);
  ImGui::Text("%zu rows / all transects", table.rows.size());
  ImGui::PushFont(monospace_, 17);
  ImGui::InputTextMultiline("##table", &raw_table_, {-1, 500},
                            ImGuiInputTextFlags_AllowTabInput);
  ImGui::PopFont();
  if (ImGui::Button("Apply table rows"))
    apply_drafts();
  ImGui::SameLine();
  if (ImGui::Button("Export table CSV…")) {
    export_text_ = table_csv(table.rows);
    dialog(3, name + ".csv");
  }
  ImGui::SameLine();
  if (ImGui::Button("Reload table"))
    table_baseline_ = raw_table_ = Json(table.rows).dump(2);
}
void Application::help_page() {
  heading("Getting started");
  ImGui::TextWrapped("Open the example project for a complete coastal study "
                     "with four transects. Each transect already includes "
                     "geometry and historical analysis data. Choose a transect "
                     "in the left panel, then use the numbered pages.");
  ImGui::SeparatorText("A new study");
  const char *steps[] = {
      "1. Project & parameters: enter the study title, datum, and water/wave "
      "conditions. Derive the mean waves, then apply parameters.",
      "2. Transect profile: import CSV/DXF or paste station/elevation columns. "
      "Coordinates use feet. Apply the profile and adjust its shoreline.",
      "3. Erosion treatment: select the dune peak and toe. For retreat, select "
      "the face and seaward point. Preview, balance the areas, and save. Skip "
      "erosion when the adjusted profile already represents the intended "
      "analysis terrain.",
      "4. WHAFIS: populate the profile, assign the obstruction/vegetation "
      "cards, apply the cards, and run. Imported legacy decks can be edited in "
      "the full input editor.",
      "5. RUNUP: populate the profile, choose 2–20 stations, set roughness, "
      "apply the selection, and run.",
      "6. Results: inspect wave crests and tables, then export CSV, SVG, DXF, "
      "or original-format reports. Save the project to retain inputs and "
      "results."};
  for (const auto *step : steps) {
    ImGui::BulletText("%s", step);
    ImGui::Spacing();
  }
  ImGui::SeparatorText("Working with profiles");
  ImGui::TextWrapped(
      "Stations increase landward. Scroll over a plot to zoom; drag with the "
      "right mouse button to pan. Use Fit plot to restore the full view. CSV "
      "columns are station,elevation,source. A header is optional. DXF imports "
      "use X as station and Y as elevation; select the desired polyline when "
      "the drawing contains more than one.");
  ImGui::SeparatorText("Projects and scenarios");
  ImGui::TextWrapped(
      "Original .mdb projects open directly. Save your work as .coastal, which "
      "retains the original tables and new reports. The 100-year and 500-year "
      "erosion and analysis data are separate. Parameter, profile, card, and "
      "selection edits are applied when saving, running, or switching "
      "transects. "
      "Erosion previews become project data when you save the eroded profile. "
      "Changing a profile or "
      "parameters does not recalculate old results: apply changes, prepare the "
      "affected engine, and run again.");
  ImGui::SeparatorText("Original manuals (included)");
  const std::pair<const char *, const char *> manuals[] = {
      {"CHAMP workflow", "CHAMP2.0_Manual.pdf"},
      {"RUNUP", "RUNUP2.0_Manual.pdf"},
      {"WHAFIS cards", "WHAFIS3.0_Manual_1988.pdf"},
      {"WHAFIS 4 supplement", "WHAFIS4.0_Supplement_2007.pdf"}};
  for (const auto &[label, filename] : manuals) {
    if (ImGui::Button(label)) {
      const auto path = utf8_path(SDL_GetBasePath()) / "manuals" / filename;
      if (!SDL_OpenURL(file_url(path).c_str()))
        error_ = SDL_GetError();
    }
    ImGui::SameLine();
  }
  ImGui::NewLine();
  ImGui::SeparatorText("Keyboard shortcuts");
  ImGui::TextWrapped(
      "Ctrl/Cmd + 1–8 opens a page; Ctrl/Cmd + Enter runs the current "
      "engine; Ctrl/Cmd + S saves; Ctrl/Cmd + Shift + S saves a copy. "
      "Tab and the arrow keys navigate controls. Ctrl/Cmd + Z reverses an "
      "edit.");
  ImGui::SeparatorText("Credits");
  ImGui::TextUnformatted(
      "Work: Astra   •   Sponsor: Rainstar   •   Foundation: Hashem");
  ImGui::TextWrapped(
      "The new implementation is MIT licensed. Original FEMA materials and "
      "third-party components retain their notices. Dear ImGui and SDL provide "
      "the desktop interface. The numerical engines run as native C++ on this "
      "computer.");
}
void Application::modals() {
  if (!error_.empty())
    ImGui::OpenPopup("Action needs attention");
  if (ImGui::BeginPopupModal("Action needs attention", nullptr,
                             ImGuiWindowFlags_AlwaysAutoResize)) {
    ImGui::PushTextWrapPos(ImGui::GetCursorPosX() + 550);
    ImGui::TextUnformatted(error_.c_str());
    ImGui::PopTextWrapPos();
    if (ImGui::Button("OK", {100, 0})) {
      error_.clear();
      ImGui::CloseCurrentPopup();
    }
    ImGui::EndPopup();
  }
  if (discard_popup_) {
    ImGui::OpenPopup("Unsaved project");
    discard_popup_ = false;
  }
  if (ImGui::BeginPopupModal("Unsaved project", nullptr,
                             ImGuiWindowFlags_AlwaysAutoResize)) {
    ImGui::TextUnformatted("Save your project before continuing?");
    if (ImGui::Button("Save", {110, 0})) {
      ImGui::CloseCurrentPopup();
      save();
    }
    ImGui::SameLine();
    if (ImGui::Button("Discard", {110, 0})) {
      auto next = std::move(after_discard_);
      after_discard_ = {};
      dirty_ = false;
      ImGui::CloseCurrentPopup();
      if (next)
        next();
    }
    ImGui::SameLine();
    if (ImGui::Button("Cancel", {110, 0})) {
      after_discard_ = {};
      ImGui::CloseCurrentPopup();
    }
    ImGui::EndPopup();
  }
  if (show_import_) {
    ImGui::OpenPopup("Import profile");
    show_import_ = false;
  }
  if (ImGui::BeginPopupModal("Import profile", nullptr,
                             ImGuiWindowFlags_AlwaysAutoResize)) {
    ImGui::TextUnformatted(
        "Choose the station/elevation profile to load into the table.");
    if (ImGui::BeginCombo(
            "Polyline",
            imports_.empty() ? "" : imports_[import_choice_].name.c_str())) {
      for (std::size_t i = 0; i < imports_.size(); ++i)
        if (ImGui::Selectable(imports_[i].name.c_str(),
                              i == std::size_t(import_choice_)))
          import_choice_ = int(i);
      ImGui::EndCombo();
    }
    if (!imports_.empty())
      ImGui::Text("%zu points", imports_[import_choice_].points.size());
    ImGui::Checkbox("Source coordinates are metres (convert to feet)",
                    &import_metres_);
    if (ImGui::Button("Load profile") && !imports_.empty()) {
      points_ = imports_[import_choice_].points;
      if (import_metres_)
        for (auto &p : points_) {
          p.station = double(p.station) / .3048;
          p.elevation = double(p.elevation) / .3048;
        }
      plot_.fitted = false;
      status_ = "Profile loaded — apply it to save it in the project";
      page_ = 1;
      ImGui::CloseCurrentPopup();
    }
    ImGui::SameLine();
    if (ImGui::Button("Cancel"))
      ImGui::CloseCurrentPopup();
    ImGui::EndPopup();
  }
  if (show_about_) {
    ImGui::OpenPopup("About Legacy Coastal");
    show_about_ = false;
  }
  if (ImGui::BeginPopupModal("About Legacy Coastal", nullptr,
                             ImGuiWindowFlags_AlwaysAutoResize)) {
    ImGui::TextUnformatted("Legacy Coastal 0.1.0");
    ImGui::TextUnformatted("CHAMP • WHAFIS • RUNUP");
    ImGui::Separator();
    ImGui::TextUnformatted(
        "Work: Astra\nSponsor: Rainstar\nFoundation: Hashem\nMIT License");
    if (ImGui::Button("Close", {120, 0}))
      ImGui::CloseCurrentPopup();
    ImGui::EndPopup();
  }
}
void Application::render() {
  poll();
  const auto &io = ImGui::GetIO();
  if (!worker_.valid() && !dialog_pending_ &&
      !ImGui::IsPopupOpen(nullptr, ImGuiPopupFlags_AnyPopupId) &&
      (io.KeyCtrl || io.KeySuper)) {
    for (int i = 0; i < 8; ++i)
      if (ImGui::IsKeyPressed(static_cast<ImGuiKey>(ImGuiKey_1 + i)))
        page_ = i;
    if (ImGui::IsKeyPressed(ImGuiKey_Enter))
      run_engine(page_ == 4 || (page_ == 5 && result_kind_ == 1));
    if (ImGui::IsKeyPressed(ImGuiKey_S))
      save(io.KeyShift);
    if (ImGui::IsKeyPressed(ImGuiKey_O))
      dialog(0);
    if (ImGui::IsKeyPressed(ImGuiKey_N))
      ask_discard([this] { new_project(); });
    if (ImGui::IsKeyPressed(ImGuiKey_Z))
      undo(io.KeyShift);
  }
  auto *viewport = ImGui::GetMainViewport();
  ImGui::SetNextWindowPos(viewport->WorkPos);
  ImGui::SetNextWindowSize(viewport->WorkSize);
  ImGui::Begin("Legacy Coastal", nullptr,
               ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove |
                   ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_MenuBar);
  ImGui::BeginDisabled(worker_.valid() || dialog_pending_);
  menu();
  if (!project_)
    welcome();
  else {
    ImGui::BeginChild("sidebar", {220, -30}, ImGuiChildFlags_Borders);
    sidebar();
    ImGui::EndChild();
    ImGui::SameLine();
    ImGui::BeginChild("content", {0, -30},
                      ImGuiChildFlags_AlwaysUseWindowPadding);
    if (page_ == 0)
      overview();
    else if (page_ == 7)
      help_page();
    else if (selected_.empty())
      ImGui::TextUnformatted("Add a transect to continue.");
    else {
      if (page_ == 1)
        transect_page();
      else if (page_ == 2)
        erosion_page();
      else if (page_ == 3)
        whafis_page();
      else if (page_ == 4)
        runup_page();
      else if (page_ == 5)
        results_page();
      else if (page_ == 6)
        tables_page();
    }
    ImGui::EndChild();
  }
  ImGui::EndDisabled();
  if (project_) {
    ImGui::Separator();
    ImGui::TextUnformatted(status_.c_str());
  }
  modals();
  ImGui::End();
}
void Application::smoke_test() {
  open_example();
  if (!project_)
    throw std::runtime_error(error_);
  parameters_.spread_percent = 6;
  points_.front().source = "Desktop save test";
  if (!apply_drafts() ||
      project_->parameters(selected_, scenario_).spread_percent != 6 ||
      project_->profile(selected_, ProfileKind::surveyed).front().source !=
          "Desktop save test")
    throw std::runtime_error("Desktop pending edits were not applied.");
  undo();
  if (parameters_.spread_percent != 5 || has_drafts())
    throw std::runtime_error("Desktop undo did not restore the example.");
  auto p = *project_;
  auto r = p.run_runup("1", Scenario::annual_1_percent);
  auto w = p.run_whafis("1", Scenario::annual_1_percent);
  if (!w.error.empty() || r.result.waves.size() != 9)
    throw std::runtime_error("Desktop example calculation failed.");
  const auto saved =
      std::filesystem::temp_directory_path() /
      ("legacy-desktop-" + std::to_string(SDL_GetTicksNS()) + ".coastal");
  p.save(saved);
  auto reopened = Project::open(saved);
  std::filesystem::remove(saved);
  if (reopened.serialize() != p.serialize())
    throw std::runtime_error("Desktop project save/reopen lost analysis data.");
  project_ = std::move(reopened);
  page_ = 5;
  result_kind_ = 0;
  reload();
}
} // namespace legacy::desktop
