cmake_minimum_required(VERSION 3.25)
project(CompTaskIV)

set(CMAKE_CXX_STANDARD 23)


add_executable(CompTaskIV main.cpp Integrator.cpp RPN.cpp Task4.2.cpp Task4.3.cpp MethodResult.h)
