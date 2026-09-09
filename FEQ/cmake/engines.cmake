# Native C++20 engines. No source translator, Fortran compiler, runtime download,
# Wine installation or research build directory is required.
include(${CMAKE_CURRENT_LIST_DIR}/feq-sources.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/fequtl-sources.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/runtime-sources.cmake)

function(feq_engine_checks target)
    target_compile_features(${target} PRIVATE cxx_std_20)
    set_target_properties(${target} PROPERTIES CXX_EXTENSIONS OFF)
    if(MSVC)
        # C-linkage adapters are C++ functions and may propagate checked errors.
        # /EHsc- explicitly clears MSVC's implicit extern-C-is-nothrow assumption.
        target_compile_options(${target} PRIVATE /permissive- /fp:strict /bigobj /EHsc-)
        target_compile_definitions(${target} PRIVATE _CRT_SECURE_NO_WARNINGS _CRT_NONSTDC_NO_DEPRECATE)
    else()
        target_compile_options(${target} PRIVATE -pedantic-errors -fstrict-aliasing
            -ffp-contract=off -fno-fast-math)
        if(FEQ_SANITIZERS)
            target_compile_options(${target} PRIVATE -fsanitize=address,undefined -fno-omit-frame-pointer)
            target_link_options(${target} PRIVATE -fsanitize=address,undefined)
        endif()
    endif()
endfunction()

add_library(feq_runtime STATIC ${FEQ_RUNTIME_SOURCES} engines/support/paths.cpp)
target_include_directories(feq_runtime PUBLIC engines/runtime)
target_compile_definitions(feq_runtime PRIVATE FEQ_RUNTIME_BUILD Skip_f2c_Undefs WANT_LEAD_0 UIOLEN_int)
if(WIN32)
    target_compile_definitions(feq_runtime PRIVATE MSDOS NO_ISATTY NO_TRUNCATE)
endif()
feq_engine_checks(feq_runtime)

set(FEQ_COMMON_ADAPTERS
    engines/support/platform.cpp tools/decimal_compat.cpp
    tools/energy_section_compat.cpp tools/section_compat.cpp tools/table_compat.cpp)
add_executable(feq ${FEQ_FEQ_SOURCES} ${FEQ_COMMON_ADAPTERS} tools/profile_compat.cpp)
add_executable(fequtl ${FEQ_FEQUTL_SOURCES} ${FEQ_COMMON_ADAPTERS}
    tools/elevation_compat.cpp tools/arch_compat.cpp tools/conduit_compat.cpp
    tools/sinuosity_compat.cpp tools/weir_compat.cpp tools/root_compat.cpp
    tools/ritter_compat.cpp tools/geometry_compat.cpp tools/flux_compat.cpp tools/properties_compat.cpp)
foreach(program feq fequtl)
    target_include_directories(${program} PRIVATE engines/${program})
    # The runtime calls the independently verified decimal functions supplied
    # by the adapter, so preserve archive ordering on one-pass linkers.
    target_link_libraries(${program} PRIVATE feq_runtime feq_numerics)
    feq_engine_checks(${program})
endforeach()

include(GNUInstallDirs)
if(MSVC)
    include(InstallRequiredSystemLibraries)
endif()
install(TARGETS feq fequtl RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
install(FILES LICENSE NOTICE.md engines/runtime/NOTICE.txt
    DESTINATION ${CMAKE_INSTALL_DATADIR}/feq/licenses)

if(BUILD_TESTING)
    find_package(Python3 COMPONENTS Interpreter REQUIRED)
    add_executable(feq_runtime_io_test tests/runtime_io_test.cpp tools/decimal_compat.cpp)
    target_link_libraries(feq_runtime_io_test PRIVATE feq_runtime feq_numerics)
    feq_checks(feq_runtime_io_test)
    add_test(NAME runtime_io_storage COMMAND feq_runtime_io_test)
    add_executable(feq_native_path_test tests/native_path_test.cpp engines/support/paths.cpp)
    target_include_directories(feq_native_path_test PRIVATE engines/runtime)
    target_compile_features(feq_native_path_test PRIVATE cxx_std_20)
    if(MSVC)
        # getenv is standard C++; this process does not mutate its environment.
        target_compile_definitions(feq_native_path_test PRIVATE _CRT_SECURE_NO_WARNINGS)
    endif()
    feq_checks(feq_native_path_test)
    add_test(NAME native_path_compatibility COMMAND feq_native_path_test)
    add_test(NAME complete_engine_examples COMMAND ${Python3_EXECUTABLE}
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/check_engine_examples.py
        --feq $<TARGET_FILE:feq> --fequtl $<TARGET_FILE:fequtl>
        --output ${CMAKE_CURRENT_BINARY_DIR}/example-verification)
    set_tests_properties(complete_engine_examples PROPERTIES TIMEOUT 180)
endif()
