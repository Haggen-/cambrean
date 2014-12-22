cmake_minimum_required(VERSION 3.0.2)
project(TestProjekt)

set(CMAKE_MODULE_PATH "/home/haggen/cmakeModules")

file(GLOB_RECURSE TestProjekt_SOURCES "src/*.cpp")
file(GLOB_RECURSE TestProjekt_HEADERS "src/*.h")

if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++11")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -g")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O2")
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
    if (CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(TestProjekt_INCLUDE_DIRS "")

foreach (_headerfile ${TestProjekt_HEADERS})
    get_filename_component(_dir ${_headerfile} PATH)
    list (APPEND TestProjekt_INCLUDE_DIRS ${_dir})
endforeach()

list(REMOVE_DUPLICATES TestProjekt_INCLUDE_DIRS)

set(SOURCE_FILES ${TestProjekt_SOURCES})
add_executable(TestProjekt ${SOURCE_FILES})

find_package(Lua REQUIRED)
find_package(OpenGL REQUIRED)


find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW3 REQUIRED glfw3)

if(NOT ${LUA_FOUND})
    message(FATAL_ERROR "Could not find LUA dependency!")
endif()

if(NOT ${OPENGL_FOUND})
    message(FATAL_ERROR "Could not find OpenGL dependency!")
endif()

message(STATUS "Found openGL")
message(STATUS ${OPENGL_INCLUDE_DIR})

include_directories(${LUA_INCLUDE_DIR} ${TestProjekt_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIR} ${GLFW3_INCLUDE_DIR})
target_link_libraries(TestProjekt ${LUA_LIBRARY} ${OPENGL_LIBRARY} ${GLFW3_LIBRARIES} ${GLFW3_STATIC_LIBRARIES})

set(CMAKE_BINARY_DIR "~/ClionProjects/TestProjekt/bin/")