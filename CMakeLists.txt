cmake_minimum_required(VERSION 3.8)
project(untitled6)

set(CMAKE_CXX_STANDARD 98)
SET( CMAKE_CXX_FLAGS "-pthread")

set(SOURCE_FILES main.cpp Server.cpp Server.h Game.cpp Game.h Command.h StartCommand.cpp StartCommand.h GameManager.cpp GameManager.h JoinCommand.cpp JoinCommand.h CommandsManager.cpp CommandsManager.h ListCommand.cpp ListCommand.h)
add_executable(untitled6 ${SOURCE_FILES})