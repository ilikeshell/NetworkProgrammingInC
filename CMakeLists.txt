cmake_minimum_required(VERSION 3.17)
project(NetworkProgrammingInC C)

set(CMAKE_C_STANDARD 99)

add_executable(NetworkProgrammingInC source/make_socket.c)

add_executable(server_read source/server_read.c lib/common.h lib/read.c)

add_executable(client_send source/client_send.c lib/common.h lib/log.c)