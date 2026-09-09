# CPack evaluates this separately for each selected generator.
if(CPACK_GENERATOR STREQUAL "DEB")
    set(CPACK_PACKAGING_INSTALL_PREFIX "/opt/feq-workbench")
elseif(CPACK_GENERATOR STREQUAL "TGZ")
    set(CPACK_PACKAGING_INSTALL_PREFIX "/")
endif()
