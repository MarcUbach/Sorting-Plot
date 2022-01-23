#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <vector>
#include <string>

class InputHandler
{
public:

    /**
     * Parse the console arguments passed by the user.
     */
    void ParseInput(int argc, char* argv[]);

    /**
     * Function to check that all console arguments are correct after they have been parsed.
     */
    void CheckCorrectArguments();

    /**
     * Correct usage example to show when an exception is thrown.
     */
    static void ShowUsage();

    [[nodiscard]] std::vector<std::string>& GetAlgorithmsToSort();

    [[nodiscard]] int GetMaxNumOfValuesToSort() const;

private:

    /**
     * Check if the given integer is a positive number.
     */
    void IsFirstInputValidInteger() const;

    /**
     * Check that the given number of algorithms is not over the maximum amount.
     */
    void IsNumberOfAlgorithmsCorrect() const;

    /**
     * Check that the algorithms passed in are found inside the possibilities vector.
     */
    void AreAlgorithmsCorrect() const;

    /**
     * Check that there are no repeated algorithms passed.
     */
    void AreAlgorithmsRepeated() const;

    // Value of items to sort for the final sorting iteration.
    int m_MaxNumOfValuesToSort;
    // Algorithms that will be processed for sorting.
    std::vector<std::string> m_AlgorithmsFromInput;
};

#endif // INPUT_HANDLER_H