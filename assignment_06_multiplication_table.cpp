// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 6
// =============================================================================
//
// TASK: Multiplication Table Generator
//
// Write a C++ program that generates multiplication tables using loops
// and functions.
//
// -----------------------------------------------------------------------------
// PART A — Single Table
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Print the multiplication table for that number from 1 to 12.
//
// Expected output (if user enters 5):
//
//   Multiplication Table for 5:
//   5  x  1  =  5
//   5  x  2  =  10
//   5  x  3  =  15
//   ...
//   5  x  12 =  60
//
// -----------------------------------------------------------------------------
// PART B — Bonus: Tables from 1 to N
// -----------------------------------------------------------------------------
// - Ask the user to enter a number N.
// - Print the full multiplication table for every number from 1 to N.
// - Add a separator line (e.g. "---") between each table.
//
// Expected output (if user enters 3):
//
//   Multiplication Table for 1:
//   1  x  1  =  1
//   ...
//   1  x  12 =  12
//   ---------------------------
//   Multiplication Table for 2:
//   2  x  1  =  2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - N must be a positive integer. If the user enters an invalid value,
//   print an error message and stop.
// - Each part must be in its own function (see scaffold below).
// - Complete Part A before attempting Part B.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;


void printSingleTable(int selected_number)
{
    cout << endl;
    cout << "Multiplication Table for " << selected_number << ":" << endl;

    for (int multiplier_number = 1; multiplier_number <= 12; multiplier_number++)
    {
        int multiplication_result = selected_number * multiplier_number;

        cout << selected_number
             << " x "
             << multiplier_number
             << " = "
             << multiplication_result
             << endl;
    }
}


void printMultipleTables(int last_table_number)
{
    for (int current_table_number = 1;
         current_table_number <= last_table_number;
         current_table_number++)
    {
        cout << endl;
        cout << "Multiplication Table for "
             << current_table_number
             << ":"
             << endl;

        for (int multiplier_number = 1;
             multiplier_number <= 12;
             multiplier_number++)
        {
            int multiplication_result =
                current_table_number * multiplier_number;

            cout << current_table_number
                 << " x "
                 << multiplier_number
                 << " = "
                 << multiplication_result
                 << endl;
        }

        cout << "---------------------------" << endl;
    }
}


int main()
{
    int selected_option;

    cout << "================================" << endl;
    cout << "  MULTIPLICATION TABLE GENERATOR" << endl;
    cout << "================================" << endl;
    cout << "1. Print one multiplication table" << endl;
    cout << "2. Print multiplication tables from 1 to N" << endl;
    cout << "Choose an option (1-2): ";

    cin >> selected_option;

    if (selected_option == 1)
    {
        int selected_number;

        cout << "Enter a number: ";
        cin >> selected_number;

        printSingleTable(selected_number);
    }
    else if (selected_option == 2)
    {
        int last_table_number;

        cout << "Enter a positive number: ";
        cin >> last_table_number;

        if (last_table_number <= 0)
        {
            cout << "Error: The number must be a positive integer." << endl;
            return 0;
        }

        printMultipleTables(last_table_number);
    }
    else
    {
        cout << "Error: Please choose option 1 or 2." << endl;
    }

    return 0;
}

