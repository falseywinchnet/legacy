cmake_minimum_required(VERSION 3.20)
project(LegacyCoastal VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(legacy_runup src/runup/math.cpp)
target_include_directories(legacy_runup PUBLIC include)
if(MSVC)
  target_compile_options(legacy_runup PRIVATE /W4 /fp:strict)
else()
  target_compile_options(legacy_runup PRIVATE -Wall -Wextra -Wpedantic -ffp-contract=off)
endif()

include(CTest)
if(BUILD_TESTING)
  add_executable(runup_math_probe tests/runup_math_probe.cpp)
  target_link_libraries(runup_math_probe PRIVATE legacy_runup)
endif()

if(BUILD_TESTING)
  find_package(Python3 COMPONENTS Interpreter REQUIRED)
  foreach(routine RINT SWLINT LOGLIN LOGLOG)
    add_test(NAME runup_${routine}_original
      COMMAND ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/tests/check_routine_reference.py
        $<TARGET_FILE:runup_math_probe> ${routine}
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/reference/runup/routines)
  endforeach()
endif()
