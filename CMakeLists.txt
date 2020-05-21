cmake_minimum_required(VERSION 3.17)

project(Simulation)

add_subdirectory(libs/SFML)
set(IMGUI_SFML_FIND_SFML OFF)
set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/libs/imgui)
add_subdirectory(libs/imgui-sfml)

include_directories(include
                    libs/SFML/include
                    libs/imgui
                    libs/imgui-sfml)
add_executable(Tomato_Example src/Tomato_Example.cpp
                              src/tomato_plant.cpp
                              src/greenhouse.cpp
                              src/water_reservoir.cpp
                              src/plant_base.cpp
                              src/lemon_plant.cpp
                              src/nutrients.cpp)

target_link_libraries(Tomato_Example sfml-graphics sfml-system ImGui-SFML::ImGui-SFML)