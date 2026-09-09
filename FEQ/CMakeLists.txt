cmake_minimum_required(VERSION 3.20)
project(FEQNumerics VERSION 0.0.1 LANGUAGES CXX)

option(FEQ_SANITIZERS "Check authored C++ for invalid memory and undefined behavior" OFF)

add_library(feq_numerics STATIC src/md5.cpp src/profile_matrix.cpp src/section_interpolation.cpp src/table_interpolation.cpp)
target_include_directories(feq_numerics PUBLIC include)
target_compile_features(feq_numerics PUBLIC cxx_std_20)
set_target_properties(feq_numerics PROPERTIES CXX_EXTENSIONS OFF)

function(feq_checks target)
    if(MSVC)
        target_compile_options(${target} PRIVATE /W4 /WX /permissive- /fp:strict)
    else()
        target_compile_options(${target} PRIVATE -Wall -Wextra -Werror -pedantic-errors
            -fstrict-aliasing -fno-fast-math -ffp-contract=off)
        if(FEQ_SANITIZERS)
            target_compile_options(${target} PRIVATE -fsanitize=address,undefined -fno-omit-frame-pointer)
            target_link_options(${target} PRIVATE -fsanitize=address,undefined)
        endif()
    endif()
endfunction()
feq_checks(feq_numerics)

include(CTest)
if(BUILD_TESTING)
    find_package(Python3 COMPONENTS Interpreter REQUIRED)
    add_test(NAME explicit_cpp_style COMMAND ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/tools/check_cpp_style.py)
    add_executable(feq_storage_test tests/storage_test.cpp)
    target_link_libraries(feq_storage_test PRIVATE feq_numerics)
    feq_checks(feq_storage_test)
    add_test(NAME storage COMMAND feq_storage_test)

    add_executable(feq_md5_test tests/md5_test.cpp)
    target_link_libraries(feq_md5_test PRIVATE feq_numerics)
    feq_checks(feq_md5_test)
    add_test(NAME md5 COMMAND feq_md5_test)

    add_executable(feq_profile_probe tools/profile_probe.cpp)
    target_link_libraries(feq_profile_probe PRIVATE feq_numerics)
    feq_checks(feq_profile_probe)
    add_test(NAME profile_original_bytes COMMAND ${Python3_EXECUTABLE}
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/check_profile_fixture.py $<TARGET_FILE:feq_profile_probe>)
    add_test(NAME profile_model_original_bytes COMMAND ${Python3_EXECUTABLE}
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/check_profile_fixture.py $<TARGET_FILE:feq_profile_probe>
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/reference/profile_models)

    add_executable(feq_section_probe tools/section_probe.cpp)
    target_link_libraries(feq_section_probe PRIVATE feq_numerics)
    feq_checks(feq_section_probe)
    add_test(NAME section_original_bytes COMMAND ${Python3_EXECUTABLE}
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/check_section_fixture.py $<TARGET_FILE:feq_section_probe>)
    add_test(NAME section_first_moment_original_bytes COMMAND ${Python3_EXECUTABLE}
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/check_section_fixture.py $<TARGET_FILE:feq_section_probe> --first-moment)
    add_executable(feq_table_probe tools/table_probe.cpp)
    target_link_libraries(feq_table_probe PRIVATE feq_numerics)
    feq_checks(feq_table_probe)
    add_test(NAME function_table_original_bytes COMMAND ${Python3_EXECUTABLE}
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/check_table_fixture.py $<TARGET_FILE:feq_table_probe>)
endif()
