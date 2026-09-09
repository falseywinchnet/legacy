#include "application.hpp"
#include "imgui.h"
#include "imgui_impl_sdl3.h"
#include "imgui_impl_sdlrenderer3.h"
#include "paths.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <cstdio>
#include <exception>
#include <filesystem>
#include <string>

int main(int argc, char **argv) {
  bool smoke = false;
  std::string screenshot, open_path;
  for (int i = 1; i < argc; ++i) {
    std::string arg = argv[i];
    if (arg == "--smoke-test")
      smoke = true;
    else if (arg == "--screenshot" && i + 1 < argc)
      screenshot = argv[++i];
    else
      open_path = arg;
  }
  if (!SDL_Init(SDL_INIT_VIDEO)) {
    std::fprintf(stderr, "%s\n", SDL_GetError());
    return 1;
  }
  SDL_Window *window =
      SDL_CreateWindow("Legacy Coastal", 1280, 900,
                       SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIGH_PIXEL_DENSITY);
  if (!window) {
    std::fprintf(stderr, "%s\n", SDL_GetError());
    SDL_Quit();
    return 1;
  }
  SDL_SetWindowMinimumSize(window, 900, 650);
  SDL_Renderer *renderer = SDL_CreateRenderer(window, nullptr);
  if (!renderer)
    renderer = SDL_CreateRenderer(window, "software");
  if (!renderer) {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Legacy Coastal",
                             SDL_GetError(), window);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
  }
  SDL_SetRenderVSync(renderer, 1);
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  auto &io = ImGui::GetIO();
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
  io.IniFilename = nullptr;
  const auto font_path =
      legacy::desktop::utf8_path(SDL_GetBasePath()) / "fonts/Inter.ttf";
  ImFont *font = io.Fonts->AddFontFromFileTTF(
      legacy::desktop::utf8_text(font_path).c_str(), 17);
  if (font)
    io.FontDefault = font;
  ImFont *monospace = io.Fonts->AddFontDefault();
  ImGui::StyleColorsLight();
  auto &style = ImGui::GetStyle();
  style.WindowPadding = {18, 16};
  style.FramePadding = {10, 7};
  style.ItemSpacing = {10, 9};
  style.WindowRounding = 0;
  style.ChildRounding = 8;
  style.FrameRounding = 5;
  style.GrabRounding = 5;
  style.ScrollbarRounding = 8;
  style.WindowBorderSize = 0;
  style.Colors[ImGuiCol_WindowBg] = {.965f, .973f, .98f, 1};
  style.Colors[ImGuiCol_ChildBg] = {1, 1, 1, 1};
  style.Colors[ImGuiCol_Text] = {.14f, .20f, .27f, 1};
  style.Colors[ImGuiCol_Button] = {.84f, .91f, .94f, 1};
  style.Colors[ImGuiCol_ButtonHovered] = {.68f, .84f, .90f, 1};
  style.Colors[ImGuiCol_ButtonActive] = {.51f, .74f, .84f, 1};
  style.Colors[ImGuiCol_Header] = {.79f, .89f, .93f, 1};
  style.Colors[ImGuiCol_FrameBg] = {.94f, .96f, .98f, 1};
  style.Colors[ImGuiCol_Border] = {.83f, .87f, .90f, 1};
  const float scale = SDL_GetWindowDisplayScale(window);
  style.FontSizeBase = 17;
  style.FontScaleDpi = scale;
  ImGui_ImplSDL3_InitForSDLRenderer(window, renderer);
  ImGui_ImplSDLRenderer3_Init(renderer);
  int result = 0;
  try {
    legacy::desktop::Application app(window, monospace);
    if (smoke)
      app.smoke_test();
    else if (!open_path.empty())
      app.open(legacy::desktop::utf8_path(open_path));
    int frames = 0;
    while (!app.finished()) {
      SDL_Event event;
      while (SDL_PollEvent(&event)) {
        ImGui_ImplSDL3_ProcessEvent(&event);
        if (event.type == SDL_EVENT_QUIT ||
            event.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED)
          app.request_quit();
        if (event.type == SDL_EVENT_DROP_FILE && event.drop.data)
          app.request_open(legacy::desktop::utf8_path(event.drop.data));
      }
      ImGui_ImplSDLRenderer3_NewFrame();
      ImGui_ImplSDL3_NewFrame();
      ImGui::NewFrame();
      app.render();
      ImGui::Render();
      SDL_SetRenderScale(renderer, io.DisplayFramebufferScale.x,
                         io.DisplayFramebufferScale.y);
      SDL_SetRenderDrawColor(renderer, 246, 248, 250, 255);
      SDL_RenderClear(renderer);
      ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), renderer);
      if (++frames == 5 && !screenshot.empty()) {
        if (auto *surface = SDL_RenderReadPixels(renderer, nullptr)) {
          if (!SDL_SaveBMP(surface, screenshot.c_str()))
            throw std::runtime_error(SDL_GetError());
          SDL_DestroySurface(surface);
        } else
          throw std::runtime_error(SDL_GetError());
      }
      SDL_RenderPresent(renderer);
      if (smoke && frames >= 5)
        break;
      SDL_Delay(8);
    }
  } catch (const std::exception &e) {
    std::fprintf(stderr, "%s\n", e.what());
    if (!smoke)
      SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Legacy Coastal", e.what(),
                               window);
    result = 1;
  }
  ImGui_ImplSDLRenderer3_Shutdown();
  ImGui_ImplSDL3_Shutdown();
  ImGui::DestroyContext();
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return result;
}
