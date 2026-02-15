cmake_minimum_required(VERSION 3.30)
project(Axioma VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(Axioma)

target_sources(Axioma
    PRIVATE
        src/Axioma/Vector3.ixx
)

target_include_directories(Axioma
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
