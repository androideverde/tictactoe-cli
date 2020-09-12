cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)

# set the project name
project(tictactoe-cli)

# add the executable
add_executable(tictactoe-cli)

# add the sources
target_sources(tictactoe-cli PRIVATE
src/CBoard.cpp
src/CGameManager.cpp
src/CPlayer.cpp
src/CRandomGenerator.cpp
src/CRenderer.cpp
src/CTicTacToe.cpp
src/main.cpp
src/TurnMaker.cpp
include/CBoard.h
include/CGameManager.h
include/CPlayer.h
include/CRandomGenerator.h
include/CRenderer.h
include/CTicTacToe.h
include/TurnMaker.h
)

# add the includes
include_directories(include)
