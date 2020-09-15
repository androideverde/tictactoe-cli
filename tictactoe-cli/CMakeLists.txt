cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)

# set the project name
project(tictactoe-cli)

# add the executable
add_executable(tictactoe-cli)

# add the sources
file(GLOB project_files "src/*.cpp" "include/*.h")
target_sources(tictactoe-cli PRIVATE ${project_files})

# add the includes
include_directories(include)
