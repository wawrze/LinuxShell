cmake_minimum_required(VERSION 3.13)
project(shell C)

set(CMAKE_C_STANDARD 99)

add_executable(shell shell.c)
add_executable(read reader.c)
add_executable(history history.c)
add_executable(commands commands.c)
add_executable(executor executor.c)
add_executable(signals signals.c)
add_executable(time time.c)
