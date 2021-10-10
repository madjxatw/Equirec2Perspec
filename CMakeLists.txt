cmake_minimum_required(VERSION 3.2)

project(Equirec2Perspec CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(GNUInstallDirs)

set(version 0.1.0)
set(PACKAGE_CONFIG_FILENAME "${PROJECT_NAME}Config.cmake")
set(PACKAGE_VERSION_FILENAME "${PROJECT_NAME}ConfigVersion.cmake")

find_package(OpenCV REQUIRED)

if(OpenCV_VERSION_MAJOR EQUAL 4)
  add_compile_definitions(OPENCV_VER_4)
endif()

add_library(${PROJECT_NAME} SHARED equirec2perspec.cpp equirec2perspec.h)

target_include_directories(${PROJECT_NAME}
  PUBLIC
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
  "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

target_link_libraries(${PROJECT_NAME} PRIVATE ${OpenCV_LIBS})

target_compile_options(${PROJECT_NAME} PRIVATE -O3)

set_target_properties(${PROJECT_NAME} PROPERTIES
  LIBRARY_OUTPUT_NAME equi2pers
)

install(
  TARGETS ${PROJECT_NAME}
  EXPORT ${PROJECT_NAME}Targets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/equirec2perspec
)

install(
  EXPORT ${PROJECT_NAME}Targets
  FILE ${PROJECT_NAME}Targets.cmake
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/equirec2perspec
)

# export target file to build-tree
export(
  EXPORT ${PROJECT_NAME}Targets
  FILE "${CMAKE_CURRENT_BINARY_DIR}/cmake/${PROJECT_NAME}Targets.cmake"
)

# install header files
install(
  FILES equirec2perspec.h
  DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/equirec2perspec"
)

# package config and version files
include(CMakePackageConfigHelpers)

configure_package_config_file(
  "${PACKAGE_CONFIG_FILENAME}.in"
  "${PROJECT_BINARY_DIR}/cmake/${PACKAGE_CONFIG_FILENAME}"
  INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/equirec2perspec"
)

set_property(TARGET ${PROJECT_NAME} PROPERTY VERSION ${version})
set_property(TARGET ${PROJECT_NAME} PROPERTY SOVERSION 0)
set_property(TARGET ${PROJECT_NAME} PROPERTY
  INTERFACE_${PROJECT_NAME}_MAJOR_VERSION 0)
set_property(TARGET ${PROJECT_NAME} APPEND PROPERTY
  COMPATIBLE_INTERFACE_STRING ${PROJECT_NAME}_MAJOR_VERSION
)

write_basic_package_version_file(
  "${PROJECT_BINARY_DIR}/cmake/${PACKAGE_VERSION_FILENAME}"
  VERSION "${version}"
  COMPATIBILITY AnyNewerVersion
)

install(
  FILES
    "${PROJECT_BINARY_DIR}/cmake/${PACKAGE_CONFIG_FILENAME}"
    "${PROJECT_BINARY_DIR}/cmake/${PACKAGE_VERSION_FILENAME}"
  DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/equirec2perspec"
)

# an example program
add_subdirectory(example)
