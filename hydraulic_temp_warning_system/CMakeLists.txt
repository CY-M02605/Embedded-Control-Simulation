cmake_minimum_required(VERSION 3.10)
project(hydraulic_temp_warning_system LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)

add_executable(hydraulic_temp_warning_system
    main.cc
    src/modules/hydraulic_temp_warning_module.cc
)

target_include_directories(hydraulic_temp_warning_system PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
