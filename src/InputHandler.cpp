#include <algorithm>
#include <climits>
#include <iostream>
#include <sstream>

#include "InputHandler.h"

void InputHandler::ParseInput(int argc, char* argv[])
{
    std::vector<std::string> arguments(argv + 1, argv + argc);

    try
    {
        m_MaxNumOfValuesToSort = std::stoi(arguments.front());
    }
    catch (...)
    {
        throw std::invalid_argument("INPUT ERROR: First argument needs to be an integer.");
    }

    m_AlgorithmsFromInput.insert(m_AlgorithmsFromInput.end(), arguments.begin() + 1, arguments.end());
}

void InputHandler::CheckCorrectArguments()
{
    IsFirstInputValidInteger();
    IsNumberOfAlgorithmsCorrect();
    AreAlgorithmsCorrect();
    AreAlgorithmsRepeated();
}

void InputHandler::ShowUsage()
{
    std::cerr << "\nUsage: ./sorter.exe <positive integer> <algorithm ...>\n"
              << "\t<positive integer>\tA valid integer from which the program will iterate and create a\n"
                 "\t\t\t\tlinearly spaced amount of vectors to create the plot\n"
              << "\t<algorithm ...>\t\tSpace separated algorithms to plot, the possibilities are:\n"
                 "\t\t\t\tbubble selection insertion quick shell std\n"
              << "Example: ./sorter.exe 10000 selection insertion" << std::endl;
}

std::vector<std::string>& InputHandler::GetAlgorithmsToSort() { return m_AlgorithmsFromInput; }

int InputHandler::GetMaxNumOfValuesToSort() const { return m_MaxNumOfValuesToSort; }

void InputHandler::IsFirstInputValidInteger() const
{
    if (m_MaxNumOfValuesToSort <= 0)
    {
        throw std::invalid_argument("INPUT ERROR: Please input a positive integer as first argument.");
    }
    if (m_MaxNumOfValuesToSort > INT_MAX)
    {
        throw std::invalid_argument("INPUT ERROR: Please input a correct integer.");
    }
}

void InputHandler::IsNumberOfAlgorithmsCorrect() const
{
    auto numOfAlgorithms = m_AlgorithmsFromInput.size();
    int minArguments = 1;
    int maxArguments = 6;

    if (numOfAlgorithms < minArguments || numOfAlgorithms > maxArguments)
    {
        throw std::invalid_argument("INPUT ERROR: Number of arguments not correct");
    }
}

void InputHandler::AreAlgorithmsCorrect() const
{
    std::vector<std::string> possibleAlgorithms{"bubble", "selection", "std", "insertion", "quick", "shell"};

    for (const auto& algorithm : m_AlgorithmsFromInput)
    {
        if (std::find(possibleAlgorithms.cbegin(), possibleAlgorithms.cend(), algorithm) == possibleAlgorithms.end())
        {
            std::stringstream returnString;
            returnString << "INPUT ERROR: Wrong argument: " << algorithm;
            throw std::invalid_argument(returnString.str());
        }
    }
}

void InputHandler::AreAlgorithmsRepeated() const
{
    std::vector<std::string> vector = m_AlgorithmsFromInput;
    std::sort(vector.begin(), vector.end());

    bool hasNoDuplicates = std::adjacent_find(vector.begin(), vector.end()) == vector.end();

    if (!hasNoDuplicates)
    {
        throw std::invalid_argument("INPUT ERROR: Don't input repeated algorithms.");
    }
}