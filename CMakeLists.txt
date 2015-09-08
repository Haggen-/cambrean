cmake_minimum_required(VERSION 3.0.2)

set(PROJECT_NAME "TestProjekt")
project(${PROJECT_NAME})

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_BINARY_DIR "bin")

if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++11")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -g -O0")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O2")
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
    if (CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
endif()

add_subdirectory(src/engine)
add_subdirectory(src/base)

set(SOURCE_FILES
        src/main.cpp
)

set(HEADER_FILES src/main.h
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})

find_package(Lua REQUIRED)

find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW3 REQUIRED glfw3)

if(NOT ${LUA_FOUND})
    message(FATAL_ERROR "Could not find LUA dependency!")
endif()

if(NOT ${GLFW3_FOUND})
    message(FATAL_ERROR "Could not find dependency to GLFW3")
endif()

include_directories(${LUA_INCLUDE_DIR} ${GLFW3_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${LUA_LIBRARY} ${GLFW3_LIBRARIES} ${GLFW3_STATIC_LIBRARIES} CambreanEngine BaseGame)
