cmake_minimum_required(VERSION 3.13)
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

set(SOURCES
    src/Algorithms/BubbleSort.cpp
    src/Algorithms/InsertionSort.cpp
    src/Algorithms/SelectionSort.cpp
    src/Algorithms/QuickSort.cpp
    src/Algorithms/ShellSort.cpp
    src/Algorithms/StdSort.cpp
    src/VectorUtils.cpp
    src/InputHandler.cpp
    src/SortingAlgorithmsContainer.cpp
    src/Sorter.cpp
)

include_directories(SYSTEM lib/${matplotlib_cpp_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(sorter ${SOURCES} main.cpp)

# Link python and numpy
target_link_libraries(sorter
    PRIVATE
    ${PYTHON_LIBRARIES}
    Python3::NumPy
)