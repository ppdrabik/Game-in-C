cmake_minimum_required(VERSION 3.29)
project(Game C)

include_directories(src)
include_directories(lib)
add_executable (main src/main.c)


set(CMAKE_PREFIX_PATH "C:/Users/ppdra/Desktop/Game")
find_package(SDL2 REQUIRED)
target_link_libraries(main SDL2::SDL2main SDL2::SDL2)


