include(GNUInstallDirs)

if(DEFINED CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    message(
        STATUS
        "CMAKE_INSTALL_PREFIX is not set\n"
        "Default value: ${CMAKE_INSTALL_PREFIX}\n"
        "Will set it to ${CMAKE_SOURCE_DIR}/install"
    )
    set(CMAKE_INSTALL_PREFIX
        "${CMAKE_SOURCE_DIR}/install"
        CACHE PATH "Where the binary will be installed to" FORCE
    )
else()
    message(
        STATUS
        "CMAKE_INSTALL_PREFIX was already set\n"
        "Current value: ${CMAKE_INSTALL_PREFIX}"
    )
endif()

install(TARGETS ${PROJECT_NAME}
    EXPORT "${PROJECT_NAME}"
    COMPONENT ${PROJECT_NAME}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
install(FILES 
    "${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}.desktop" 
    DESTINATION /usr/share/applications
)
install(FILES 
    "${CMAKE_CURRENT_SOURCE_DIR}/res/icons/${PROJECT_NAME}.png" 
    DESTINATION /usr/share/icons/hicolor/512x512/apps
)

