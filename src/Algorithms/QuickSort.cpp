#include "Algorithms.h"

void QuickSort(std::vector<int>& p_Vector)
{
    QuickSortRange(p_Vector, 0, static_cast<int>(p_Vector.size()) - 1);
}

void QuickSortRange(std::vector<int>& p_Vector, int p_LowValue, int p_HighValue)
{
    if (p_LowValue < p_HighValue)
    {
        int p = Partition(p_Vector, p_LowValue, p_HighValue);
        QuickSortRange(p_Vector, p_LowValue, p - 1);
        QuickSortRange(p_Vector, p + 1, p_HighValue);
    }
}

int Partition(std::vector<int>& p_Vector, int p_LowValue, int p_HighValue)
{
    int pivot = p_Vector[p_HighValue];
    int i     = p_LowValue;

    for (int j = p_LowValue; j < p_HighValue; ++j)
    {
        if (p_Vector[j] < pivot)
        {
            swap(p_Vector[i], p_Vector[j]);
            i++;
        }
    }
    std::swap(p_Vector[i], p_Vector[p_HighValue]);
    return i;
}