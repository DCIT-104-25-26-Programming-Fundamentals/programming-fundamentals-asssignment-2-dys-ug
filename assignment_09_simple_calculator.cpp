// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


double addNumbers(double first_number, double second_number)
{
    return first_number + second_number;
}


double subtractNumbers(double first_number, double second_number)
{
    return first_number - second_number;
}


double multiplyNumbers(double first_number, double second_number)
{
    return first_number * second_number;
}


double divideNumbers(double first_number, double second_number)
{
    return first_number / second_number;
}


int findModulus(int first_number, int second_number)
{
    return first_number % second_number;
}


double calculatePower(double first_number, double second_number)
{
    return pow(first_number, second_number);
}


void displayMenu()
{
    cout << endl;
    cout << "============================" << endl;
    cout << "     SIMPLE CALCULATOR" << endl;
    cout << "============================" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Modulus" << endl;
    cout << "6. Exponentiation" << endl;
    cout << "7. Quit" << endl;
}


int main()
{
    bool calculator_running = true;

    while (calculator_running == true)
    {
        displayMenu();

        int selected_operation;

        cout << "Select an operation (1-7): ";
        cin >> selected_operation;

        if (selected_operation == 7)
        {
            cout << "Goodbye!" << endl;
            calculator_running = false;
        }
        else if (selected_operation < 1 || selected_operation > 7)
        {
            cout << "Error: Please choose a number from 1 to 7." << endl;
        }
        else if (selected_operation == 5)
        {
            int first_number;
            int second_number;

            cout << "Enter first number : ";
            cin >> first_number;

            cout << "Enter second number: ";
            cin >> second_number;

            if (second_number == 0)
            {
                cout << "Error: Cannot calculate modulus by zero." << endl;
            }
            else
            {
                int calculation_result = findModulus(
                    first_number,
                    second_number
                );

                cout << "Result: "
                     << first_number
                     << " % "
                     << second_number
                     << " = "
                     << calculation_result
                     << endl;
            }
        }
        else
        {
            double first_number;
            double second_number;
            double calculation_result;

            cout << "Enter first number : ";
            cin >> first_number;

            cout << "Enter second number: ";
            cin >> second_number;

            cout << fixed << setprecision(2);

            if (selected_operation == 1)
            {
                calculation_result = addNumbers(
                    first_number,
                    second_number
                );

                cout << "Result: "
                     << first_number
                     << " + "
                     << second_number
                     << " = "
                     << calculation_result
                     << endl;
            }
            else if (selected_operation == 2)
            {
                calculation_result = subtractNumbers(
                    first_number,
                    second_number
                );

                cout << "Result: "
                     << first_number
                     << " - "
                     << second_number
                     << " = "
                     << calculation_result
                     << endl;
            }
            else if (selected_operation == 3)
            {
                calculation_result = multiplyNumbers(
                    first_number,
                    second_number
                );

                cout << "Result: "
                     << first_number
                     << " * "
                     << second_number
                     << " = "
                     << calculation_result
                     << endl;
            }
            else if (selected_operation == 4)
            {
                if (second_number == 0)
                {
                    cout << "Error: Cannot divide by zero." << endl;
                }
                else
                {
                    calculation_result = divideNumbers(
                        first_number,
                        second_number
                    );

                    cout << "Result: "
                         << first_number
                         << " / "
                         << second_number
                         << " = "
                         << calculation_result
                         << endl;
                }
            }
            else if (selected_operation == 6)
            {
                calculation_result = calculatePower(
                    first_number,
                    second_number
                );

                cout << "Result: "
                     << first_number
                     << " ^ "
                     << second_number
                     << " = "
                     << calculation_result
                     << endl;
            }
        }
    }

    return 0;
}
