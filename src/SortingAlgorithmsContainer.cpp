#include <random>

#include "SortingAlgorithmsContainer.h"
#include "VectorUtils.h"

static const int START_VALUE = 0;
static const int NUMBER_VALUES = 11;

SortingAlgorithmsContainer::SortingAlgorithmsContainer(int p_Size)
{
    CreateLinearSpacedVector(m_LinearSpacedVector, START_VALUE, p_Size, NUMBER_VALUES);

    for(auto iterationVectorSize : m_LinearSpacedVector)
    {
        m_AllVectorIterationsToSort.push_back(CreateRandomVector(1, static_cast<int>(iterationVectorSize)));
    }
}

std::vector<double> SortingAlgorithmsContainer::GetLinearSpacedVector() const
{
    return m_LinearSpacedVector;
}

std::vector<std::vector<int>> SortingAlgorithmsContainer::GetAllVectorIterationsToSort() const
{
    return m_AllVectorIterationsToSort;
}

AlgorithmCallbackMap SortingAlgorithmsContainer::GetFunctionCallback() const
{
    return m_AlgorithmCallbackMap;
}
