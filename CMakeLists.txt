cmake_minimum_required(VERSION 3.12)
project(DocDB)

set(CMAKE_CXX_STANDARD 14)

add_executable(DocDB main.cpp WSDON/WSDONParser.cpp WSDON/WSDONParser.h)