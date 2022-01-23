cmake_minimum_required(VERSION 3.15)
project("Sorter" LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

# Guard against in-source builds
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    message(FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there. You may need to remove CMakeCache.txt.")
endif()

# Find python libraries
find_package(Python3 COMPONENTS Interpreter Development NumPy REQUIRED)
find_package(PythonLibs 3.0 REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

# Populate matplotlib repository
include(FetchContent)
FetchContent_Declare(
        matplotlib
        GIT_REPOSITORY https://github.com/lava/matplotlib-cpp.git
)
FetchContent_MakeAvailable(matplotlib)

set(SOURCES
        src/Algorithms/BubbleSort.cpp
        src/Algorithms/InsertionSort.cpp
        src/Algorithms/SelectionSort.cpp
        src/Algorithms/ShellSort.cpp
        src/Algorithms/QuickSort.cpp
        src/Algorithms/StdSort.cpp
        src/VectorUtils.cpp
        src/InputHandler.cpp
        src/SortingAlgorithmsContainer.cpp
        src/Sorter.cpp
)

include_directories(SYSTEM ${matplotlib_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/src)

add_executable(sorter ${SOURCES} main.cpp)

# Link python and numpy
target_link_libraries(sorter
        PRIVATE
        ${PYTHON_LIBRARIES}
        Python3::NumPy
)