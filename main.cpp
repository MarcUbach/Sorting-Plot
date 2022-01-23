#include <iostream>

#include "Sorter.h"
#include "InputHandler.h"

int main(int argc, char* argv[])
{
    InputHandler inputHandler;

    try
    {
        inputHandler.ParseInput(argc, argv);
        inputHandler.CheckCorrectArguments();
    }
    catch (const std::exception& exc)
    {
        std::cerr << exc.what() << std::endl;
        InputHandler::ShowUsage();
        return EXIT_FAILURE;
    }

    Sorter sorter(inputHandler);

    sorter.SortAndBenchmark();
    sorter.Plot();

    return EXIT_SUCCESS;
}