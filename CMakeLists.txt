cmake_minimum_required(VERSION 3.22)
project(cpu_tasks_planner)

set(CMAKE_CXX_STANDARD 17)
set(SRC src/instruction.cpp src/scheduler.cpp)

add_executable(cpu_tasks_planner src/main.cpp ${SRC})

target_include_directories(cpu_tasks_planner PUBLIC include)
