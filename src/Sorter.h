#ifndef SORTER_H
#define SORTER_H

#include <map>
#include <memory>

#include "SortingAlgorithmsContainer.h"
#include <functional>

class InputHandler;
class SortingAlgorithmsContainer;

class Sorter
{
  public:
    explicit Sorter(InputHandler& p_InputHandler);

    /**
     * Sort each vector iteration per algorithm.
     */
    void SortAndBenchmark();

    /**
     * Plot the resulting values (ms) that it took the m_AlgorithmsToSort to sort the vector.
     */
    void Plot();

  private:
    /**
     * Measures the time used per vector sorting iteration of each algorithm.
     * @param p_Algorithm Specific algorithm to benchmark.
     * @param p_NumberVector specific iteration vector containing the elements to sort.
     * @param p_Times vector containing the time used per sorting iteration.
     */
    void Measure(const std::string& p_Algorithm, std::vector<int> p_NumberVector, std::vector<long long>& p_Times);

    // Container for the sorting algorithms to plot.
    std::unique_ptr<SortingAlgorithmsContainer> m_SortingAlgorithmsContainer;

    // Algorithms to sort by name.
    std::vector<std::string> m_AlgorithmsToSort;
    // Container that stores each iteration sorting duration per algorithm.
    std::map<std::string, std::vector<long long>> m_AlgorithmTimesMap;
    // Algorithm function callback.
    AlgorithmCallbackMap m_AlgorithmCallbackMap;
};

#endif // SORTER_H