cmake_minimum_required(VERSION 3.10)
project(ENGINE C)

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib")
set(BIN_DIR "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(RESOURCES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/resources")
set(EXAMPLES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/examples")

find_package(PkgConfig REQUIRED)
pkg_check_modules(GLFW REQUIRED glfw3)
message(STATUS "Adding GLFW library")

#plg_check_modules(glad REQUIRED glad)

cmake_policy(SET CMP0072 NEW)
set(OpenGL_GL_PREFERENCE "GLVND")
find_package(OpenGL REQUIRED)

#add_subdirectory(${LIB_DIR}/glfw3)
#find_package(OpenGL REQUIRED)
#
file(GLOB SOURCES src/*.c)
add_executable(ENGINE ${SOURCES})
#
#target_include_directories(ENGINE PRIVATE ${GLFW_INCLUDE_DIRS})
#target_link_libraries(ENGINE PRIVATE ${GLFW_LIBRARIES} OpenGL::GL)

#foreach(EXAMPLE ${EXAMPLES})
#   	get_filename_component(EXAMPLE_NAME ${EXAMPLE} NAME_WE)
#   	message(STATUS "Adding example ${EXAMPLE_NAME}")
#    setup_executable(${EXAMPLES_DIR} ${EXAMPLE_NAME} MAIN)
#endforeach()

