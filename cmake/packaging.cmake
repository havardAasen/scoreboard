set(CPACK_PACKAGE_CONTACT "Håvard F. Aasen <havard.f.aasen@pfft.no>")
set(CPACK_PACKAGE_DESCRIPTION "An application for keeping track of time and goals in matches,\nit's intended use case is as a scoreboard in sport arenas.")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set(CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_SOURCE_DIR}/README.md")
set(CPACK_STRIP_FILES TRUE)

set(CPACK_DEBIAN_PACKAGE_PRIORITY optional)
set(CPACK_DEBIAN_PACKAGE_SECTION misc)
set(CPACK_DEBIAN_PACKAGE_RELEASE 1)
set(CPACK_DEBIAN_FILE_NAME DEB-DEFAULT)
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS TRUE)

include(CPack)
