cmake_minimum_required(VERSION 3.15)
project(pea1)

set(CMAKE_CXX_STANDARD 14)

if (CMAKE_BUILD_TYPE MATCHES RELEASE)
    set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
endif (CMAKE_BUILD_TYPE MATCHES RELEASE)

add_executable(pea1 main.cpp TSP.cpp TSP.h BruteForce.cpp BruteForce.h Algorithm.cpp Algorithm.h UI.cpp UI.h BranchAndBound.cpp BranchAndBound.h Test.cpp Test.h)