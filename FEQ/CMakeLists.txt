cmake_minimum_required(VERSION 3.20)
project(FEQNumerics VERSION 0.0.1 LANGUAGES CXX)

option(FEQ_SANITIZERS "Check authored C++ for invalid memory and undefined behavior" OFF)

add_library(feq_numerics STATIC src/section_energy.cpp src/conduit_boundary.cpp src/weir_flow.cpp src/arch_perimeter.cpp src/trigonometry.cpp src/elevation_arguments.cpp src/section_properties.cpp src/section_flux.cpp src/power.cpp src/section_geometry.cpp src/decimal.cpp src/md5.cpp src/profile_matrix.cpp src/section_interpolation.cpp src/table_interpolation.cpp)
target_include_directories(feq_numerics PUBLIC include)
target_sources(feq_numerics PRIVATE src/root_solver.cpp src/culvert_loss.cpp src/steady_residual.cpp src/approach_residual.cpp)
target_sources(feq_numerics PRIVATE src/section_extension.cpp)
target_sources(feq_numerics PRIVATE src/gaussian_rule.cpp)
target_sources(feq_numerics PRIVATE src/section_sinuosity.cpp)
target_sources(feq_numerics PRIVATE src/gate_residual.cpp)
target_sources(feq_numerics PRIVATE src/power_spacing.cpp)
target_sources(feq_numerics PRIVATE src/full_barrel.cpp)
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
    add_library(feq_public_headers OBJECT tests/public_headers.cpp)
    target_link_libraries(feq_public_headers PRIVATE feq_numerics)
    feq_checks(feq_public_headers)
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
    add_test(NAME profile_control_original_bytes COMMAND ${Python3_EXECUTABLE}
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/check_profile_fixture.py $<TARGET_FILE:feq_profile_probe>
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/reference/profile_controls)

    add_executable(feq_section_probe tools/section_probe.cpp)
    target_link_libraries(feq_section_probe PRIVATE feq_numerics)
    feq_checks(feq_section_probe)
    add_test(NAME section_original_bytes COMMAND ${Python3_EXECUTABLE}
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/check_section_fixture.py $<TARGET_FILE:feq_section_probe>)
    add_test(NAME section_first_moment_original_bytes COMMAND ${Python3_EXECUTABLE}
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/check_section_fixture.py $<TARGET_FILE:feq_section_probe> --first-moment)
    add_test(NAME scalar_conveyance_original_bytes COMMAND ${Python3_EXECUTABLE}
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/check_gate_fixture.py $<TARGET_FILE:feq_section_probe> scalar_conveyance)
    add_executable(feq_geometry_probe tools/geometry_probe.cpp)
    target_link_libraries(feq_geometry_probe PRIVATE feq_numerics)
    feq_checks(feq_geometry_probe)
    add_test(NAME geometry_original_bytes COMMAND ${Python3_EXECUTABLE}
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/check_geometry_fixture.py $<TARGET_FILE:feq_geometry_probe>)

    add_executable(feq_power_probe tools/power_probe.cpp)
    target_link_libraries(feq_power_probe PRIVATE feq_numerics)
    feq_checks(feq_power_probe)
    add_test(NAME power_original_bytes COMMAND ${Python3_EXECUTABLE}
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/check_power_fixture.py $<TARGET_FILE:feq_power_probe>)

    add_executable(feq_flux_probe tools/flux_probe.cpp)
    target_link_libraries(feq_flux_probe PRIVATE feq_numerics)
    feq_checks(feq_flux_probe)
    add_test(NAME flux_original_bytes COMMAND ${Python3_EXECUTABLE}
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/check_flux_fixture.py $<TARGET_FILE:feq_flux_probe>)

    add_executable(feq_properties_probe tools/properties_probe.cpp)
    target_link_libraries(feq_properties_probe PRIVATE feq_numerics)
    feq_checks(feq_properties_probe)
    add_test(NAME properties_original_bytes COMMAND ${Python3_EXECUTABLE}
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/check_properties_fixture.py $<TARGET_FILE:feq_properties_probe>)

    add_executable(feq_elevation_probe tools/elevation_probe.cpp)
    target_link_libraries(feq_elevation_probe PRIVATE feq_numerics)
    feq_checks(feq_elevation_probe)
    add_test(NAME elevation_original_bytes COMMAND ${Python3_EXECUTABLE}
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/check_elevation_fixture.py $<TARGET_FILE:feq_elevation_probe>)

    add_executable(feq_trigonometry_probe tools/trigonometry_probe.cpp)
    target_link_libraries(feq_trigonometry_probe PRIVATE feq_numerics)
    feq_checks(feq_trigonometry_probe)
    add_test(NAME trigonometry_original_bytes COMMAND ${Python3_EXECUTABLE}
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/check_trigonometry_fixture.py $<TARGET_FILE:feq_trigonometry_probe>)

    add_executable(feq_weir_probe tools/weir_probe.cpp)
    target_link_libraries(feq_weir_probe PRIVATE feq_numerics)
    feq_checks(feq_weir_probe)
    add_test(NAME weir_original_bytes COMMAND ${Python3_EXECUTABLE}
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/check_weir_fixture.py $<TARGET_FILE:feq_weir_probe>)

    add_executable(feq_energy_section_probe tools/energy_section_probe.cpp)
    target_link_libraries(feq_energy_section_probe PRIVATE feq_numerics)
    feq_checks(feq_energy_section_probe)
    add_test(NAME energy_section_original_bytes COMMAND ${Python3_EXECUTABLE}
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/check_energy_section_fixture.py $<TARGET_FILE:feq_energy_section_probe>)
    add_test(NAME critical_flow_original_bytes COMMAND ${Python3_EXECUTABLE}
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/check_critical_flow_fixture.py $<TARGET_FILE:feq_energy_section_probe>)

    add_executable(feq_root_probe tools/root_probe.cpp tools/root_compat.cpp)
    target_link_libraries(feq_root_probe PRIVATE feq_numerics)
    feq_checks(feq_root_probe)
    add_executable(feq_root_search_probe tools/root_search_probe.cpp tools/root_compat.cpp)
    target_link_libraries(feq_root_search_probe PRIVATE feq_numerics)
    feq_checks(feq_root_search_probe)
    foreach(method regfal fdroot)
        add_test(NAME root_search_${method}_original_bytes COMMAND ${Python3_EXECUTABLE}
            ${CMAKE_CURRENT_SOURCE_DIR}/tests/check_root_search_fixture.py $<TARGET_FILE:feq_root_search_probe> --${method})
        add_test(NAME root_search_${method}_adapter_original_bytes COMMAND ${Python3_EXECUTABLE}
            ${CMAKE_CURRENT_SOURCE_DIR}/tests/check_root_search_fixture.py $<TARGET_FILE:feq_root_search_probe> --${method} --adapter)
    endforeach()
    add_test(NAME root_original_bytes COMMAND ${Python3_EXECUTABLE}
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/check_root_fixture.py $<TARGET_FILE:feq_root_probe>)
    add_test(NAME root_adapter_original_bytes COMMAND ${Python3_EXECUTABLE}
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/check_root_fixture.py $<TARGET_FILE:feq_root_probe> --adapter)
    add_test(NAME steady_residual_original_bytes COMMAND ${Python3_EXECUTABLE}
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/check_steady_residual_fixture.py $<TARGET_FILE:feq_energy_section_probe>)
    add_test(NAME steady_profile_original_bytes COMMAND ${Python3_EXECUTABLE}
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/check_steady_profile_fixture.py $<TARGET_FILE:feq_energy_section_probe>)
    add_test(NAME normal_flow_residual_original_bytes COMMAND ${Python3_EXECUTABLE}
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/check_gate_fixture.py $<TARGET_FILE:feq_energy_section_probe> normal_flow_residual)
    add_test(NAME station_fraction_original_bytes COMMAND ${Python3_EXECUTABLE}
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/check_station_fraction_fixture.py $<TARGET_FILE:feq_section_probe>)
    add_executable(feq_slot_probe tools/slot_probe.cpp)
    target_link_libraries(feq_slot_probe PRIVATE feq_numerics)
    feq_checks(feq_slot_probe)
    add_test(NAME section_slot_original_bytes COMMAND ${Python3_EXECUTABLE}
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/check_slot_fixture.py $<TARGET_FILE:feq_slot_probe>)
    add_executable(feq_gaussian_rule_probe tools/gaussian_rule_probe.cpp)
    target_link_libraries(feq_gaussian_rule_probe PRIVATE feq_numerics)
    feq_checks(feq_gaussian_rule_probe)
    add_test(NAME gaussian_rule_original_bytes COMMAND ${Python3_EXECUTABLE}
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/check_gaussian_rule_fixture.py $<TARGET_FILE:feq_gaussian_rule_probe>)
    add_executable(feq_sinuosity_probe tools/sinuosity_probe.cpp tools/sinuosity_compat.cpp)
    target_link_libraries(feq_sinuosity_probe PRIVATE feq_numerics)
    feq_checks(feq_sinuosity_probe)
    add_test(NAME section_sinuosity_original_bytes COMMAND ${Python3_EXECUTABLE}
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/check_sinuosity_fixture.py $<TARGET_FILE:feq_sinuosity_probe>)
    add_test(NAME section_sinuosity_adapter_original_bytes COMMAND ${Python3_EXECUTABLE}
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/check_sinuosity_fixture.py $<TARGET_FILE:feq_sinuosity_probe> --adapter)
    add_test(NAME approach_residual_original_bytes COMMAND ${Python3_EXECUTABLE}
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/check_approach_residual_fixture.py $<TARGET_FILE:feq_energy_section_probe>)
    foreach(gate_fixture gate_residual gate_levels gate_free gate_orifice gate_state specific_energy power_spacing full_barrel)
        add_test(NAME ${gate_fixture}_original_bytes COMMAND ${Python3_EXECUTABLE}
            ${CMAKE_CURRENT_SOURCE_DIR}/tests/check_gate_fixture.py $<TARGET_FILE:feq_energy_section_probe> ${gate_fixture})
    endforeach()
    foreach(method regflt rgf rgf5)
        add_test(NAME root_${method}_original_bytes COMMAND ${Python3_EXECUTABLE}
            ${CMAKE_CURRENT_SOURCE_DIR}/tests/check_root_fixture.py $<TARGET_FILE:feq_root_probe> --${method})
        add_test(NAME root_${method}_adapter_original_bytes COMMAND ${Python3_EXECUTABLE}
            ${CMAKE_CURRENT_SOURCE_DIR}/tests/check_root_fixture.py $<TARGET_FILE:feq_root_probe> --${method} --adapter)
    endforeach()

    add_executable(feq_culvert_loss_probe tools/culvert_loss_probe.cpp)
    target_link_libraries(feq_culvert_loss_probe PRIVATE feq_numerics)
    feq_checks(feq_culvert_loss_probe)
    add_test(NAME type2_head_loss_original_bytes COMMAND ${Python3_EXECUTABLE}
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/check_gate_fixture.py $<TARGET_FILE:feq_culvert_loss_probe> type2_head_loss)
    add_test(NAME culvert_loss_original_bytes COMMAND ${Python3_EXECUTABLE}
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/check_culvert_loss_fixture.py $<TARGET_FILE:feq_culvert_loss_probe>)
    add_test(NAME culvert_coefficient_original_bytes COMMAND ${Python3_EXECUTABLE}
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/check_culvert_coefficient_fixture.py $<TARGET_FILE:feq_culvert_loss_probe>)

    add_executable(feq_conduit_probe tools/conduit_probe.cpp)
    target_link_libraries(feq_conduit_probe PRIVATE feq_numerics)
    feq_checks(feq_conduit_probe)
    add_test(NAME conduit_original_bytes COMMAND ${Python3_EXECUTABLE}
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/check_conduit_fixture.py $<TARGET_FILE:feq_conduit_probe>)

    add_executable(feq_arch_probe tools/arch_probe.cpp)
    target_link_libraries(feq_arch_probe PRIVATE feq_numerics)
    feq_checks(feq_arch_probe)
    add_test(NAME arch_original_bytes COMMAND ${Python3_EXECUTABLE}
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/check_arch_fixture.py $<TARGET_FILE:feq_arch_probe>)

    add_executable(feq_decimal_probe tools/decimal_probe.cpp)
    target_link_libraries(feq_decimal_probe PRIVATE feq_numerics)
    feq_checks(feq_decimal_probe)
    add_test(NAME decimal_original_bytes COMMAND ${Python3_EXECUTABLE}
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/check_decimal_fixture.py $<TARGET_FILE:feq_decimal_probe>)
    add_test(NAME list_real_original_bytes COMMAND ${Python3_EXECUTABLE}
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/check_list_real_fixture.py $<TARGET_FILE:feq_decimal_probe>)

    add_executable(feq_table_probe tools/table_probe.cpp)
    target_link_libraries(feq_table_probe PRIVATE feq_numerics)
    feq_checks(feq_table_probe)
    add_test(NAME function_table_original_bytes COMMAND ${Python3_EXECUTABLE}
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/check_table_fixture.py $<TARGET_FILE:feq_table_probe>)
endif()
