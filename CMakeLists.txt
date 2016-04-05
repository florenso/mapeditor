cmake_minimum_required(VERSION 3.5)

project(MapEditor)

include_directories(Realisation/MapEditorMaputils)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)


file(GLOB SOURCES "Realisation/MapEditor/Maputils/*.cpp")

add_executable(Main ${SOURCES})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

#set_property(TARGET Main APPEND_STRING PROPERTY LINK_FLAGS "-pthread")