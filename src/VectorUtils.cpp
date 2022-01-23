#include <vector>
#include <numeric>
#include <random>
#include <algorithm>

#include "VectorUtils.h"

std::vector<int> CreateRandomVector(std::size_t p_StartValue, std::size_t p_EndValue)
{
    std::vector<int> nums(p_EndValue - p_StartValue + 1);
    std::iota(nums.begin(), nums.end(), p_StartValue);

    std::random_device rnd_device;
    std::shuffle(nums.begin(), nums.end(), rnd_device);

    return nums;
}

void CreateLinearSpacedVector(std::vector<double>& p_Vector, int p_StartValue, int p_EndValue, std::size_t p_NumberOfValues)
{
    double h = (p_EndValue - p_StartValue) / static_cast<double>(p_NumberOfValues - 1);
    p_Vector.resize(p_NumberOfValues);
    std::vector<double>::iterator iter;
    double val;
    for (iter = p_Vector.begin(), val = p_StartValue; iter != p_Vector.end(); ++iter, val += h) {
        *iter = val;
    }
}