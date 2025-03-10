cmake_minimum_required(VERSION 3.10)
project(PRBVisualizer)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

include_directories(src)

add_executable(PRBVisualizer main.cpp src/Application.cpp src/EventManager.cpp src/PRB.cpp src/ResourceElement.cpp src/ChannelManager.cpp )

target_link_libraries(PRBVisualizer sfml-system sfml-window sfml-graphics sfml-network sfml-audio)
