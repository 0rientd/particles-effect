cmake_minimum_required(VERSION 3.20)

project(particles LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SDL2 REQUIRED)

add_executable(particles
    src/main.cpp
    src/ui/particles.cpp
)

target_compile_options(particles PRIVATE
    -Wall
    -Wextra
)

target_include_directories(particles PRIVATE
    include
)

target_link_libraries(particles PRIVATE
    SDL2::SDL2
)

set_target_properties(particles PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

install(TARGETS particles DESTINATION bin)
