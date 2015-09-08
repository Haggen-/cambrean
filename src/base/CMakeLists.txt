cmake_minimum_required(VERSION 3.0.2)
project(BaseGame)

set(SOURCE_FILES
        GameWorld.cpp
)

set(HEADER_FILES GameWorld.h
)

add_library(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})