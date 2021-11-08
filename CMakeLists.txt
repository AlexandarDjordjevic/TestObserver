cmake_minimum_required(VERSION 3.8)

project(Analytics)

set(this Analytics)

set(CMAKE_CXX_STANDARD 17)


set(source
    main.cpp
    source/Analytics.cpp
    source/Listener.cpp
)

add_executable(${this} ${source})

target_include_directories(${this} PUBLIC include)

