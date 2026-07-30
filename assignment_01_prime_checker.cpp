// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 1
// =============================================================================
//
// TASK: Prime Number Checker
//
// Write a C++ program that checks whether a given number is prime.
//
// A prime number is a whole number greater than 1 that has no divisors
// other than 1 and itself (e.g., 2, 3, 5, 7, 11, 13 ...).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLES
// -----------------------------------------------------------------------------
//
//   Enter a number: 7
//   7 is a prime number.
//
//   Enter a number: 10
//   10 is NOT a prime number.
//
//   Enter a number: 1
//   1 is NOT a prime number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement the logic inside a function (see scaffold below).
// - Numbers less than 2 are NOT prime — handle this inside the function.
// - The main() function must call isPrime() and print the result.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;


bool isPrime(int user_number)
{
    if (user_number < 2)
    {
        return false;
    }

    for (int divisor_number = 2; divisor_number < user_number; divisor_number++)
    {
        if (user_number % divisor_number == 0)
        {
            return false;
        }
    }

    return true;
}


int main()
{
    int user_number;

    cout << "Enter a number: ";
    cin >> user_number;

    bool prime_result = isPrime(user_number);

    if (prime_result == true)
    {
        cout << user_number << " is a prime number." << endl;
    }
    else
    {
        cout << user_number << " is NOT a prime number." << endl;
    }

    return 0;
}