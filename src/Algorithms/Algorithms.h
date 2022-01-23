#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>

// Sorting methods
void BubbleSort(std::vector<int>& p_Vector);
void InsertionSort(std::vector<int>& p_Vector);
void SelectionSort(std::vector<int>& p_Vector);
void StdSort(std::vector<int>& p_Vector);
void ShellSort(std::vector<int>& p_Vector);
void QuickSort(std::vector<int>& p_Vector);

// Helper methods
void QuickSortRange(std::vector<int>& p_Vector, int p_LowValue, int p_HighValue);
int Partition(std::vector<int>& p_Vector, int p_LowValue, int p_HighValue);

inline void swap(int p_First, int p_Second)
{
    int temp = p_First;
    p_First = p_Second;
    p_Second = temp;
}

#endif // ALGORITHMS_H
