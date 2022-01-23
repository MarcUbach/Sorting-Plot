#include <chrono>

#include "InputHandler.h"
#include "Sorter.h"

#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

typedef std::chrono::steady_clock theClock;

Sorter::Sorter(InputHandler& p_InputHandler)
{
    m_AlgorithmsToSort = p_InputHandler.GetAlgorithmsToSort();

    m_SortingAlgorithmsContainer =
        std::make_unique<SortingAlgorithmsContainer>(p_InputHandler.GetMaxNumOfValuesToSort());

    m_AlgorithmCallbackMap = m_SortingAlgorithmsContainer->GetFunctionCallback();
}

void Sorter::SortAndBenchmark()
{
    std::vector<long long> times;

    for (const auto& algorithm : m_AlgorithmsToSort)
    {
        std::cout << "Algorithm: " << algorithm << std::endl;

        for (const auto& numberVector : m_SortingAlgorithmsContainer->GetAllVectorIterationsToSort())
        {
            Measure(algorithm, numberVector, times);
        }

        m_AlgorithmTimesMap.emplace(algorithm, times);
        times.clear();
    }
}

void Sorter::Measure(const std::string& p_Algorithm, std::vector<int> p_NumberVector, std::vector<long long>& p_Times)
{
    std::cout << "Size of Vector:: " << p_NumberVector.size() << '\n';

    auto start = theClock::now();

    m_AlgorithmCallbackMap[p_Algorithm](p_NumberVector); // Function m_AlgorithmCallbackMap explanation

    auto end = theClock::now();

    auto timeTaken = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    std::cout << "It took " << timeTaken << " ms to sort." << '\n';
    p_Times.push_back(timeTaken);
    std::cout << "======================" << '\n';
}

void Sorter::Plot()
{
    for (const auto& _algorithm : m_AlgorithmsToSort)
    {
        plt::named_plot(_algorithm, m_SortingAlgorithmsContainer->GetLinearSpacedVector(),
                        m_AlgorithmTimesMap.at(_algorithm));
    }
    plt::grid(true);
    plt::title("Sorting Algorithms");
    plt::xlabel("Size of vector");
    plt::ylabel("Time (ms)");
    plt::legend();
    plt::show();
}