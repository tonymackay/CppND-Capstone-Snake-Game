cmake_minimum_required(VERSION 3.7)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++17 -pthread")

project(SnakeGame)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2TTF REQUIRED)

include_directories(
  src
  ${SDL2_INCLUDE_DIRS}
  ${SDL2TTF_INCLUDE_DIR}
)

add_executable(
  ${PROJECT_NAME} 
  src/main.cpp 
  src/game.cpp
  src/game_object.cpp
  src/snake.cpp
  src/scene.cpp
  src/food.cpp
  src/score.cpp
  src/sdl_w.cpp
)

#string(STRIP ${SDL2_LIBRARY} SDL2_LIBRARY)

target_link_libraries(
  ${PROJECT_NAME} 
  ${SDL2_LIBRARIES}
  ${SDL2TTF_LIBRARY}
)

configure_file(fonts/Verdana.ttf Verdana.ttf COPYONLY)
