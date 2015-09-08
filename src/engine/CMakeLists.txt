cmake_minimum_required(VERSION 3.0.2)
project(CambreanEngine)

set(SOURCE_FILES
        Renderer.cpp Block.cpp
)

set(HEADER_FILES Renderer.h Block.h
)

add_library(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})