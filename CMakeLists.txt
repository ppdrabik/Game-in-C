cmake_minimum_required(VERSION 3.29)
project(Game C)

include_directories(src)
include_directories(lib)

add_library(rectangle lib/rectangle.c)
add_library(sdl_init lib/sdl_init.c)
add_library(entity lib/entity.c)

add_executable (Game src/main.c lib/sdl_init.c  lib/entity.c)


set(CMAKE_PREFIX_PATH "C:/Users/ppdra/Desktop/Game")
find_package(SDL2 REQUIRED)
if (SDL2_FOUND)
    message(STATUS "SDL2 found")
endif()
find_package(SDL2_image REQUIRED)
if (SDL2_image_FOUND)
    message(STATUS "SDL2_image found")
endif()
include_directories(C:/Users/ppdra/Desktop/Game/SDL2-2.30.3/include)
include_directories(C:/Users/ppdra/Desktop/Game/SDL2_image-2.8.2/include)
target_link_libraries(Game SDL2::SDL2main SDL2::SDL2 SDL2_image::SDL2_image rectangle sdl_init entity)
