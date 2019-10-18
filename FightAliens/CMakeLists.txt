cmake_minimum_required(VERSION 3.7)

include_directories(./libs/SDL2/include)

include_directories(./libs/SDL2_image)

include_directories(./src/)

file(GLOB SOURCES "src/*.cpp")

link_directories("./libs/SDL2/libs")

link_directories("./libs/SDL2_image/libs")

#target_link_libraries(shooterBattle SDL2_iamge) 

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(shooterBattle)

add_executable(shooterBattle ${SOURCES})


target_link_libraries(shooterBattle SDL2)

target_link_libraries(shooterBattle SDL2_image)   
