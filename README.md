[![Linux](https://github.com/MarcUbach/Sorting-Plot/actions/workflows/linux.yml/badge.svg)](https://github.com/MarcUbach/Sorting-Plot/actions/workflows/linux.yml)
[![Windows(VisualStudio 2019)](https://github.com/MarcUbach/Sorting-Plot/actions/workflows/windows.yml/badge.svg)](https://github.com/MarcUbach/Sorting-Plot/actions/workflows/windows.yml)
[![Windows(MinGW)](https://github.com/MarcUbach/Sorting-Plot/actions/workflows/mingw.yml/badge.svg)](https://github.com/MarcUbach/Sorting-Plot/actions/workflows/mingw.yml)

## Sorting Algorithms

Program that allows for run-time plotting of different sorting algorithms: bubble, insertion, selection, quicksort, shellsort and std::sort.
It also allows to easily visualize the efficiency between them.

The program works by creating a series of vector iterations from which to plot each algorithm. The program will receive a number input from the user, from which a linearly spaced vector will be created. This vector will determine each iteration from which to create the plot. 
(Example: If the user inputs 10.000, a vector with 10 iterations will be created {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10.000}

Each of these iterations will on itself create a random unsorted vector containing that number of items. 
The algorithms then act on the previously defined vectors while measuring each ones performance. The plotting is done by taking each iterations total sorting time.

## Dependencies
- Python3
- Numpy
- [Matplotlib-cpp](https://github.com/lava/matplotlib-cpp)
- [CMake](https://github.com/Kitware/CMake) >= 3.0 installed.
- C++17 compatible compiler

## Building
#### Getting numpy and matplotlib
```shell script
python3 -m pip install numpy
python3 -m pip install matplotlib
```
#### Compile and build for POSIX
```shell script
mkdir build 
cd build
cmake ..
cmake --build .
```
#### Compile and build for Windows (VisualStudio 2019)
```shell script
mkdir build
cd build
cmake .. -G "Visual Studio 16 2019" -A x64
cmake --build .
```
#### Compile and build for Windows (MinGW)
```shell script
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
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
 
## Screenshots
Output of: ```./sorter.exe bubble selection insertion 10000```

![Bubble-Selection-Insertion](https://user-images.githubusercontent.com/25902186/150685829-765ba7f5-d492-42dc-93c4-82122c78dd07.png)

Output of: ```./sorter.exe quick std 1000000```

![Quick-STD-1mill](https://user-images.githubusercontent.com/25902186/150685864-831f5c47-554f-4ee8-8ce0-56a280f46dcb.png)
