#pragma once
#include "legacy/project_io.hpp"
#include "plot.hpp"
#include <SDL3/SDL.h>
#include <functional>
#include <future>
#include <optional>
#include <string>
#include <vector>
namespace legacy::desktop {
class Application {
public:
  explicit Application(SDL_Window *window, ImFont *monospace = nullptr);
  void render();
  void open(const std::filesystem::path &path);
  void request_open(const std::filesystem::path &path);
  void request_quit();
  bool finished() const { return quit_; }
  void open_example();
  void smoke_test();

private:
  SDL_Window *window_{};
  ImFont *monospace_{};
  champ::Json draft_baseline_;
  std::string table_name_ = "TRANSECTCTL", table_baseline_;
  bool dialog_pending_{};
  champ::Json draft_state() const;
  bool has_drafts() const;
  bool apply_drafts();
  std::optional<champ::Project> project_;
  std::filesystem::path path_;
  std::string selected_, status_ = "Ready", error_, new_id_, profile_paste_,
                         deck_, raw_table_, report_text_;
  champ::Scenario scenario_{champ::Scenario::annual_1_percent};
  int point_selection_{-1};
  int page_{}, profile_kind_{}, erosion_pick_{}, result_kind_{},
      import_choice_{};
  bool dirty_{}, quit_{}, show_tables_{}, show_about_{}, show_import_{},
      import_metres_{};
  std::vector<champ::Json> undo_, redo_;
  std::optional<champ::Json> field_edit_;
  std::vector<champ::TransectPoint> points_;
  champ::Parameters parameters_;
  champ::ErosionSettings erosion_;
  std::optional<champ::ErosionResult> erosion_preview_;
  std::vector<champ::Json> runup_rows_;
  std::vector<champ::WhafisCard> cards_;
  std::vector<champ::ProfileImport> imports_;
  struct Calculation { champ::Project project; std::string error; };
  std::future<Calculation> worker_;
  std::string worker_label_;
  std::function<void()> after_discard_;
  bool discard_popup_{};
  PlotState plot_;
  std::string export_text_;
  void reload();
  void mutate(const std::string &label, const std::function<void()> &action);
  void guarded(const std::function<void()> &action);
  void remember();
  void undo(bool redo = false);
  void new_project();
  void ask_discard(std::function<void()> action);
  void dialog(int operation, const std::string &suggested = {});
  void save(bool save_as = false);
  void poll();
  void menu();
  void welcome();
  void sidebar();
  void overview();
  void transect_page();
  void erosion_page();
  void whafis_page();
  void runup_page();
  void results_page();
  void tables_page();
  void help_page();
  void modals();
  void launch(const std::string &label,
              const std::function<void(champ::Project &)> &action);
  std::vector<PlotSeries> profile_series(bool draft = false) const;
  void export_plot(bool dxf);
  void edit_metadata(champ::Json &row, const char *field, const char *label);
  bool float_input(const char *label, float &value,
                   const char *format = "%.7g");
};
} // namespace legacy::desktop
