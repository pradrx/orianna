cmake_minimum_required(VERSION 3.10)

# Set the project name
project(Orianna)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directories
include_directories(include)

# Add source files
set(SOURCES
    src/main.cpp
    src/board.cpp
    src/game.cpp
)

# Add header files (optional, but can be useful for IDEs)
set(HEADERS
    include/board.hpp
    include/game.hpp
    include/lookup_tables.hpp
)

# Add the executable
add_executable(orianna ${SOURCES} ${HEADERS})
