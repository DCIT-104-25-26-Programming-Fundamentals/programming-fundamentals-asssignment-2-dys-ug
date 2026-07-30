// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;


int calculateSum(int number_list[], int number_count)
{
    int total_value = 0;

    for (int number_position = 0; number_position < number_count; number_position++)
    {
        total_value = total_value + number_list[number_position];
    }

    return total_value;
}


double calculateAverage(int number_list[], int number_count)
{
    int total_value = calculateSum(number_list, number_count);

    double average_value = static_cast<double>(total_value) / number_count;

    return average_value;
}


int findMaximum(int number_list[], int number_count)
{
    int maximum_value = number_list[0];

    for (int number_position = 1; number_position < number_count; number_position++)
    {
        if (number_list[number_position] > maximum_value)
        {
            maximum_value = number_list[number_position];
        }
    }

    return maximum_value;
}


int findMinimum(int number_list[], int number_count)
{
    int minimum_value = number_list[0];

    for (int number_position = 1; number_position < number_count; number_position++)
    {
        if (number_list[number_position] < minimum_value)
        {
            minimum_value = number_list[number_position];
        }
    }

    return minimum_value;
}


int main()
{
    int number_count;

    cout << "How many numbers? ";
    cin >> number_count;

    if (number_count <= 0)
    {
        cout << "Error: The number must be a positive integer." << endl;
        return 0;
    }

    int* entered_numbers = new int[number_count];

    for (int number_position = 0; number_position < number_count; number_position++)
    {
        cout << "Enter number " << number_position + 1 << ": ";
        cin >> entered_numbers[number_position];
    }

    int total_result = calculateSum(entered_numbers, number_count);
    double average_result = calculateAverage(entered_numbers, number_count);
    int maximum_result = findMaximum(entered_numbers, number_count);
    int minimum_result = findMinimum(entered_numbers, number_count);

    cout << endl;
    cout << "Results:" << endl;
    cout << "Sum:     " << total_result << endl;
    cout << "Average: " << average_result << endl;
    cout << "Maximum: " << maximum_result << endl;
    cout << "Minimum: " << minimum_result << endl;

    delete[] entered_numbers;

    return 0;
}
