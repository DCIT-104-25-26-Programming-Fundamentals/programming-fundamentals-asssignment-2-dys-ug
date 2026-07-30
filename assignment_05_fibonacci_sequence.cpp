// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// Write a C++ program with TWO parts, each implemented as a function.
//
// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
// - Ask the user how many terms (N) to display.
// - Print the first N numbers of the Fibonacci sequence on one line.
//
// Example:
//   How many terms? 7
//   Fibonacci sequence: 0 1 1 2 3 5 8
//
// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Determine whether that number is a Fibonacci number.
// - Print an appropriate message.
//
// Example:
//   Enter a number to check: 13
//   13 is a Fibonacci number.
//
//   Enter a number to check: 20
//   20 is NOT a Fibonacci number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use a loop (not recursion) to generate the sequence in both parts.
// - N must be a positive integer. If it is not, print an error message.
// - Each part must be implemented in its own function (see scaffold below).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;


void printFibonacci(int number_of_terms)
{
    if (number_of_terms <= 0)
    {
        cout << "Error: Number of terms must be positive." << endl;
        return;
    }

    int first_number = 0;
    int second_number = 1;

    cout << "Fibonacci sequence: ";

    for (int term_position = 1; term_position <= number_of_terms; term_position++)
    {
        cout << first_number << " ";

        int next_number = first_number + second_number;

        first_number = second_number;
        second_number = next_number;
    }

    cout << endl;
}


bool isFibonacci(int number_to_check)
{
    if (number_to_check < 0)
    {
        return false;
    }

    int first_number = 0;
    int second_number = 1;

    while (first_number < number_to_check)
    {
        int next_number = first_number + second_number;

        first_number = second_number;
        second_number = next_number;
    }

    if (first_number == number_to_check)
    {
        return true;
    }
    else
    {
        return false;
    }
}


int main()
{
    int number_of_terms;

    cout << "How many terms? ";
    cin >> number_of_terms;

    printFibonacci(number_of_terms);

    int number_to_check;

    cout << "Enter a number to check: ";
    cin >> number_to_check;

    bool fibonacci_result = isFibonacci(number_to_check);

    if (fibonacci_result == true)
    {
        cout << number_to_check << " is a Fibonacci number." << endl;
    }
    else
    {
        cout << number_to_check << " is NOT a Fibonacci number." << endl;
    }

    return 0;
}