cmake_minimum_required(VERSION 3.20)
project(LegacyCoastal VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(legacy_runup src/runup/math.cpp src/runup/curves.cpp src/runup/calculation.cpp
  src/runup/model.cpp src/runup/report.cpp)
target_include_directories(legacy_runup PUBLIC include)
if(MSVC)
  target_compile_options(legacy_runup PRIVATE /W4 /fp:strict)
else()
  target_compile_options(legacy_runup PRIVATE -Wall -Wextra -Wpedantic -ffp-contract=off)
endif()

add_executable(runup src/runup/main.cpp)
target_link_libraries(runup PRIVATE legacy_runup)

add_library(legacy_whafis src/whafis/support.cpp src/whafis/model.cpp
  src/whafis/whafis4.cpp src/whafis/fetch.cpp src/whafis/veg.cpp
  src/whafis/shbm.cpp src/whafis/hin.cpp src/whafis/avg.cpp
  src/whafis/readin.cpp src/whafis/app.cpp src/whafis/echo.cpp
  src/whafis/t.cpp src/whafis/wavg.cpp src/whafis/hm0.cpp
  src/whafis/lookup.cpp src/whafis/scane.cpp)
target_include_directories(legacy_whafis PUBLIC include)
if(MSVC)
  target_compile_options(legacy_whafis PRIVATE /fp:strict)
else()
  target_compile_options(legacy_whafis PRIVATE -ffp-contract=off -Wno-parentheses-equality)
endif()
add_executable(whafis src/whafis/main.cpp)
target_link_libraries(whafis PRIVATE legacy_whafis)

include(CTest)
if(BUILD_TESTING)
  add_executable(runup_math_probe tests/runup_math_probe.cpp)
  target_link_libraries(runup_math_probe PRIVATE legacy_runup)
  add_executable(runup_state_probe tests/runup_state_probe.cpp)
  target_link_libraries(runup_state_probe PRIVATE legacy_runup)
  add_executable(whafis_state_probe tests/whafis_state_probe.cpp)
  target_link_libraries(whafis_state_probe PRIVATE legacy_whafis)
  add_executable(whafis_math_probe tests/whafis_math_probe.cpp)
  target_link_libraries(whafis_math_probe PRIVATE legacy_whafis)
endif()

if(BUILD_TESTING)
  find_package(Python3 COMPONENTS Interpreter REQUIRED)
  add_test(NAME runup_complete_original_reports
    COMMAND ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/tests/check_runup_reference.py
      $<TARGET_FILE:runup> ${CMAKE_CURRENT_SOURCE_DIR})
  add_test(NAME whafis_complete_original_reports
    COMMAND ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/tests/check_whafis_reference.py
      $<TARGET_FILE:whafis> ${CMAKE_CURRENT_SOURCE_DIR})
  foreach(routine SHBM T HM0 HIN)
    add_test(NAME whafis_${routine}_original
      COMMAND ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/tests/check_whafis_routine.py
        $<TARGET_FILE:whafis_math_probe> ${routine} ${CMAKE_CURRENT_SOURCE_DIR})
  endforeach()
  foreach(routine LOOK RINT SWLINT LOGLIN LOGLOG DBPLOT)
    add_test(NAME runup_${routine}_original
      COMMAND ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/tests/check_routine_reference.py
        $<TARGET_FILE:runup_math_probe> ${routine}
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/reference/runup/routines)
  endforeach()
endif()
