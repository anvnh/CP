cmake_minimum_required(VERSION 3.31)
project(CP)

set(CMAKE_CXX_STANDARD 11)

add_executable(CP main.cpp
        ICPC/2025/Central/A.cpp
        ICPC/2025/Central/D.cpp
        ICPC/2025/Central/M.cpp
        ICPC/2025/Central/J.cpp
        ICPC/2025/Central/L.cpp
        ICPC/2025/TestNorthern/A.cpp
        ICPC/2025/Northen/I.cpp
        ICPC/2025/Northen/C.cpp
        ICPC/2025/Northen/B.cpp)
