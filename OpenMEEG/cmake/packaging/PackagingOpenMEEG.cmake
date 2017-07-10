
set(CPACK_PACKAGE_NAME "OpenMEEG")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "OpenMEEG Project")
set(CPACK_PACKAGE_DESCRIPTION "A C++ package for low-frequency bio-electromagnetism solving forward problems in the field of EEG and MEG.")
set(CPACK_PACKAGE_VENDOR "INRIA-ENPC")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})

set(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_LIST_DIR}/../../../README.rst")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_LIST_DIR}/../../../LICENSE.txt")

set(CPACK_PACKAGE_CONTACT "openmeeg-info@lists.gforge.inria.fr")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "OpenMEEG")
set(CPACK_SOURCE_STRIP_FILES "")

set(PACKAGE_ARCH_SHORT "Linux")
if(WIN32)
    SET(PACKAGE_ARCH_SHORT "Win64")
    if(NOT CMAKE_CL_64)
        set(PACKAGE_ARCH_SHORT "Win32")
    endif()
elseif(APPLE)
    set(PACKAGE_ARCH_SHORT "MacOSX")
endif()
