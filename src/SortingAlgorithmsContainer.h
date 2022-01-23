#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <map>
#include <functional>

#include "Algorithms/Algorithms.h"

typedef std::map<std::string, std::function<void(std::vector<int>&)>> AlgorithmCallbackMap;

class SortingAlgorithmsContainer
{
public:

    explicit SortingAlgorithmsContainer(int p_Size);

    [[nodiscard]] std::vector<double> GetLinearSpacedVector() const;

    [[nodiscard]] std::vector<std::vector<int>> GetAllVectorIterationsToSort() const;

    [[nodiscard]] AlgorithmCallbackMap GetFunctionCallback() const;

private:

    // Linearly spaced vector containing the number of items to sort in each iteration.
    std::vector<double> m_LinearSpacedVector;
    // Vector containing each complete unsorted vector iteration.
    std::vector<std::vector<int>> m_AllVectorIterationsToSort;
    // Algorithm callback map, mapping each algorithm name to its sorting function.
    AlgorithmCallbackMap m_AlgorithmCallbackMap =
    {
        { "bubble", BubbleSort },
        { "insertion", InsertionSort },
        { "selection", SelectionSort },
        { "std", StdSort },
        { "quick", QuickSort },
        { "shell", ShellSort }
    };
};

#endif //SORTING_ALGORITHMS_H