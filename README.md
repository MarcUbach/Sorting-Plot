[![Build](https://github.com/MarcUbach/Sorting-Plot/actions/workflows/build.yml/badge.svg)](https://github.com/MarcUbach/Sorting-Plot/actions/workflows/build.yml)

## Sorting Algorithms

Program that allows for run-time plotting of different sorting algorithms: bubble, insertion, selection, quicksort, shellsort and std::sort.

It also allows to easily visualize the efficiency between them.

### TODO: Add explanation of how it works and some screenshots.

## Dependencies
- Python3
- Numpy
- [Matplotlib-cpp](https://github.com/lava/matplotlib-cpp)
- [CMake](https://github.com/Kitware/CMake) >= 3.14 installed.

## Building
### Building for POSIX
#### Getting numpy and matplotlib
```shell script
python3 -m pip install numpy
python3 -m pip install matplotlib
```
#### Compile and build
```shell script
mkdir build 
cd build
cmake ..
cmake --build .
```
## Running

The corresponding ```sorter.exe``` will be found inside the ```build``` folder.

Run:
```shell script
./sorter.exe [positiveInteger] [algorithm ...]
    [positiveInteger] Is a valid integer from which the program will iterate and create 
                      a linearly spaced amount of vectors to create the plot.
    [algorithm ...]   Space separated algorithms to plot, the possibilities are: 
                        - bubble 
                        - selection 
                        - insertion
                        - quick
                        - shell
                        - std
                        
    Example: ./sorter.exe 30000 insertion selection bubble
```
## TODO: Add Windows CMake generator