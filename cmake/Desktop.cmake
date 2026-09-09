include(FetchContent)
set(SDL_SHARED OFF CACHE BOOL "" FORCE)
set(SDL_STATIC ON CACHE BOOL "" FORCE)
set(SDL_TEST_LIBRARY OFF CACHE BOOL "" FORCE)
set(SDL_TESTS OFF CACHE BOOL "" FORCE)
set(SDL_EXAMPLES OFF CACHE BOOL "" FORCE)
set(SDL_AUDIO OFF CACHE BOOL "" FORCE)
set(SDL_CAMERA OFF CACHE BOOL "" FORCE)
set(SDL_JOYSTICK OFF CACHE BOOL "" FORCE)
set(SDL_HAPTIC OFF CACHE BOOL "" FORCE)
set(SDL_SENSOR OFF CACHE BOOL "" FORCE)
set(SDL_INSTALL OFF CACHE BOOL "" FORCE)
FetchContent_Declare(SDL
  URL https://github.com/libsdl-org/SDL/releases/download/release-3.4.16/SDL3-3.4.16.tar.gz
  URL_HASH SHA256=7322236cd12090c3eb40b9728be4d49c76f66ad17d04369584d4ecad5cf77c68
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE)
FetchContent_Declare(imgui
  URL https://github.com/ocornut/imgui/archive/refs/tags/v1.92.9b.tar.gz
  URL_HASH SHA256=21d8a0a565e85dce943e375db00812c2f3f0ab21f3f0f7964e364a63422d7f99
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE)
FetchContent_MakeAvailable(SDL imgui)
add_library(legacy_imgui STATIC
  ${imgui_SOURCE_DIR}/imgui.cpp ${imgui_SOURCE_DIR}/imgui_draw.cpp
  ${imgui_SOURCE_DIR}/imgui_tables.cpp ${imgui_SOURCE_DIR}/imgui_widgets.cpp
  ${imgui_SOURCE_DIR}/misc/cpp/imgui_stdlib.cpp
  ${imgui_SOURCE_DIR}/backends/imgui_impl_sdl3.cpp
  ${imgui_SOURCE_DIR}/backends/imgui_impl_sdlrenderer3.cpp)
target_include_directories(legacy_imgui PUBLIC ${imgui_SOURCE_DIR}
  ${imgui_SOURCE_DIR}/backends ${imgui_SOURCE_DIR}/misc/cpp)
target_link_libraries(legacy_imgui PUBLIC SDL3::SDL3-static)
add_executable(legacy_coastal WIN32 MACOSX_BUNDLE src/desktop/main.cpp src/desktop/application.cpp src/desktop/plot.cpp)
target_link_libraries(legacy_coastal PRIVATE legacy_champ legacy_imgui)
if(WIN32)
  enable_language(RC)
  target_sources(legacy_coastal PRIVATE resources/coastal.rc)
  target_include_directories(legacy_coastal PRIVATE resources)
endif()
if(APPLE)
  target_sources(legacy_coastal PRIVATE resources/coastal.icns)
  set_source_files_properties(resources/coastal.icns PROPERTIES MACOSX_PACKAGE_LOCATION Resources)
endif()
set_target_properties(legacy_coastal PROPERTIES OUTPUT_NAME "Legacy Coastal"
  MACOSX_BUNDLE_BUNDLE_NAME "Legacy Coastal"
  MACOSX_BUNDLE_GUI_IDENTIFIER "org.rainstar.legacy-coastal"
  MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION}
  MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION})
if(APPLE)
  set_target_properties(legacy_coastal PROPERTIES MACOSX_BUNDLE_INFO_PLIST "${CMAKE_CURRENT_SOURCE_DIR}/resources/Info.plist.in")
endif()
if(APPLE)
  set(legacy_example_directory "$<TARGET_BUNDLE_CONTENT_DIR:legacy_coastal>/Resources/examples")
else()
  set(legacy_example_directory "$<TARGET_FILE_DIR:legacy_coastal>/examples")
endif()
add_custom_command(TARGET legacy_coastal POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/resources/examples "${legacy_example_directory}"
  COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/resources/fonts "${legacy_example_directory}/../fonts")
set(legacy_manual_sources
  CHAMP2.0_Manual.pdf RUNUP2.0_Manual.pdf WHAFIS3.0_Manual_1988.pdf WHAFIS4.0_Supplement_2007.pdf)
foreach(manual IN LISTS legacy_manual_sources)
  add_custom_command(TARGET legacy_coastal POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory "${legacy_example_directory}/../manuals"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "${CMAKE_CURRENT_SOURCE_DIR}/originals/manuals/${manual}" "${legacy_example_directory}/../manuals/${manual}")
endforeach()
if(APPLE)
  install(TARGETS legacy_coastal BUNDLE DESTINATION .)
  install(FILES README.md LICENSE NOTICE.md DESTINATION "Legacy Coastal.app/Contents/Resources")
else()
  install(TARGETS legacy_coastal RUNTIME DESTINATION .)
  install(DIRECTORY resources/examples resources/fonts DESTINATION .)
  foreach(manual IN LISTS legacy_manual_sources)
    install(FILES "originals/manuals/${manual}" DESTINATION manuals)
  endforeach()
  install(FILES README.md LICENSE NOTICE.md DESTINATION .)
endif()
if(APPLE)
  set(legacy_license_directory "Legacy Coastal.app/Contents/Resources/licenses")
else()
  set(legacy_license_directory licenses)
endif()
install(FILES ${sdl_SOURCE_DIR}/LICENSE.txt DESTINATION "${legacy_license_directory}" RENAME SDL.txt)
install(FILES ${imgui_SOURCE_DIR}/LICENSE.txt DESTINATION "${legacy_license_directory}" RENAME Dear-ImGui.txt)
install(FILES third_party/nlohmann/LICENSE.MIT DESTINATION "${legacy_license_directory}" RENAME JSON.txt)

if(APPLE)
  install(TARGETS runup whafis RUNTIME DESTINATION "Legacy Coastal.app/Contents/MacOS")
else()
  install(TARGETS runup whafis RUNTIME DESTINATION tools)
endif()
set(CPACK_PACKAGE_NAME "Legacy-Coastal")
set(CPACK_PACKAGE_VENDOR "Rainstar")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Coastal profiles, dune erosion, WHAFIS, and RUNUP")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
if(APPLE)
  set(CPACK_GENERATOR "DragNDrop;ZIP")
  if("arm64" IN_LIST CMAKE_OSX_ARCHITECTURES AND "x86_64" IN_LIST CMAKE_OSX_ARCHITECTURES)
    set(CPACK_SYSTEM_NAME "macOS-universal")
  else()
    set(CPACK_SYSTEM_NAME "macOS-${CMAKE_SYSTEM_PROCESSOR}")
  endif()
  set(CPACK_DMG_VOLUME_NAME "Legacy Coastal")
elseif(WIN32)
  set(CPACK_GENERATOR ZIP)
  set(CPACK_SYSTEM_NAME "Windows-x64")
else()
  set(CPACK_GENERATOR TGZ)
  set(CPACK_SYSTEM_NAME "Linux-${CMAKE_SYSTEM_PROCESSOR}")
  install(PROGRAMS "resources/Start Legacy Coastal.sh" DESTINATION .)
endif()
if(APPLE)
  add_custom_command(TARGET legacy_coastal POST_BUILD
    COMMAND codesign --force --deep --sign - "$<TARGET_BUNDLE_DIR:legacy_coastal>")
  install(CODE [[
    execute_process(COMMAND codesign --force --deep --sign -
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/Legacy Coastal.app"
      RESULT_VARIABLE signing_result)
    if(NOT signing_result EQUAL 0)
      message(FATAL_ERROR "Could not sign the installed application bundle.")
    endif()
  ]])
endif()
include(CPack)
