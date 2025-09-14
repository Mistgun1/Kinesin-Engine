cmake_minimum_required(VERSION 3.22)
project(KINESIN_ENGINE C)

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib")
set(BIN_DIR "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(RESOURCES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/resources")
set(EXAMPLES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/examples")

find_package(OpenGL REQUIRED)
add_subdirectory(${LIB_DIR}/glfw)

message(STATUS "Adding GLFW library")

file(GLOB SOURCES src/*.c)
add_library(Render STATIC "${SOURCES}")

file(GLOB EXAMPLES ${EXAMPLES_DIR}/*.c)
foreach(EXAMPLE ${EXAMPLES})
    get_filename_component(EXAMPLE_NAME ${EXAMPLE} NAME_WE)
    message(STATUS "Adding example ${EXAMPLE_NAME}")
    add_executable(${EXAMPLE_NAME} ${EXAMPLE}) 
    target_include_directories(${EXAMPLE_NAME} PRIVATE ${GLFW_INCLUDE_DIRS} ${SRC_DIR})
    target_link_libraries(${EXAMPLE_NAME} PRIVATE ${GLFW_LIBRARIES} OpenGL::GL Render glfw)
endforeach()

