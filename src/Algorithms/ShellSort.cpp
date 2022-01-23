#include "Algorithms.h"

void ShellSort(std::vector<int>& p_Vector)
{
    int gap = p_Vector.size() / 2;
    while(gap > 0)
    {
        for(int index = gap; index < p_Vector.size(); ++index)
        {
            for(int j = index; j >= gap; j -= gap)
            {
                if(p_Vector[j] < p_Vector[j - gap])
                {
                    swap(p_Vector[j], p_Vector[j - gap]);
                }
                else
                {
                    break;
                }
            }
        }
        gap = gap / 2;
    }
}
