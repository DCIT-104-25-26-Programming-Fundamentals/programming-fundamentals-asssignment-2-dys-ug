// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


const int maximum_size = 10;


void enterMatrix(
    int matrix_values[maximum_size][maximum_size],
    int number_of_rows,
    int number_of_columns,
    string matrix_name
)
{
    cout << endl;
    cout << "Enter values for Matrix " << matrix_name << ":" << endl;

    for (int row_position = 0; row_position < number_of_rows; row_position++)
    {
        for (int column_position = 0; column_position < number_of_columns; column_position++)
        {
            cout << "Enter element [" << row_position << "]["
                 << column_position << "]: ";

            cin >> matrix_values[row_position][column_position];
        }
    }
}


void displayMatrix(
    int matrix_values[maximum_size][maximum_size],
    int number_of_rows,
    int number_of_columns
)
{
    for (int row_position = 0; row_position < number_of_rows; row_position++)
    {
        for (int column_position = 0; column_position < number_of_columns; column_position++)
        {
            cout << setw(6)
                 << matrix_values[row_position][column_position];
        }

        cout << endl;
    }
}


void transposeMatrix(
    int original_matrix[maximum_size][maximum_size],
    int transposed_matrix[maximum_size][maximum_size],
    int number_of_rows,
    int number_of_columns
)
{
    for (int row_position = 0; row_position < number_of_rows; row_position++)
    {
        for (int column_position = 0; column_position < number_of_columns; column_position++)
        {
            transposed_matrix[column_position][row_position]
                = original_matrix[row_position][column_position];
        }
    }
}


void addMatrices(
    int first_matrix[maximum_size][maximum_size],
    int second_matrix[maximum_size][maximum_size],
    int added_matrix[maximum_size][maximum_size],
    int number_of_rows,
    int number_of_columns
)
{
    for (int row_position = 0; row_position < number_of_rows; row_position++)
    {
        for (int column_position = 0; column_position < number_of_columns; column_position++)
        {
            added_matrix[row_position][column_position]
                = first_matrix[row_position][column_position]
                + second_matrix[row_position][column_position];
        }
    }
}


void multiplyMatrices(
    int first_matrix[maximum_size][maximum_size],
    int second_matrix[maximum_size][maximum_size],
    int multiplied_matrix[maximum_size][maximum_size],
    int first_matrix_rows,
    int first_matrix_columns,
    int second_matrix_columns
)
{
    for (int row_position = 0; row_position < first_matrix_rows; row_position++)
    {
        for (int column_position = 0; column_position < second_matrix_columns; column_position++)
        {
            multiplied_matrix[row_position][column_position] = 0;

            for (int common_position = 0;
                 common_position < first_matrix_columns;
                 common_position++)
            {
                multiplied_matrix[row_position][column_position]
                    = multiplied_matrix[row_position][column_position]
                    + first_matrix[row_position][common_position]
                    * second_matrix[common_position][column_position];
            }
        }
    }
}


bool dimensionsAreValid(int number_of_rows, int number_of_columns)
{
    if (
        number_of_rows < 1 ||
        number_of_rows > maximum_size ||
        number_of_columns < 1 ||
        number_of_columns > maximum_size
    )
    {
        return false;
    }

    return true;
}


int main()
{
    int first_matrix[maximum_size][maximum_size];
    int second_matrix[maximum_size][maximum_size];
    int result_matrix[maximum_size][maximum_size];

    int selected_operation;

    cout << "================================" << endl;
    cout << "       MATRIX OPERATIONS" << endl;
    cout << "================================" << endl;
    cout << "1. Transpose a matrix" << endl;
    cout << "2. Add two matrices" << endl;
    cout << "3. Multiply two matrices" << endl;
    cout << "Choose an operation (1-3): ";

    cin >> selected_operation;


    if (selected_operation == 1)
    {
        int number_of_rows;
        int number_of_columns;

        cout << "Enter number of rows: ";
        cin >> number_of_rows;

        cout << "Enter number of columns: ";
        cin >> number_of_columns;

        if (!dimensionsAreValid(number_of_rows, number_of_columns))
        {
            cout << "Error: Rows and columns must be between 1 and 10."
                 << endl;

            return 0;
        }

        enterMatrix(
            first_matrix,
            number_of_rows,
            number_of_columns,
            "A"
        );

        transposeMatrix(
            first_matrix,
            result_matrix,
            number_of_rows,
            number_of_columns
        );

        cout << endl;
        cout << "Original Matrix:" << endl;

        displayMatrix(
            first_matrix,
            number_of_rows,
            number_of_columns
        );

        cout << endl;
        cout << "Transposed Matrix:" << endl;

        displayMatrix(
            result_matrix,
            number_of_columns,
            number_of_rows
        );
    }


    else if (selected_operation == 2)
    {
        int number_of_rows;
        int number_of_columns;

        cout << "Enter number of rows: ";
        cin >> number_of_rows;

        cout << "Enter number of columns: ";
        cin >> number_of_columns;

        if (!dimensionsAreValid(number_of_rows, number_of_columns))
        {
            cout << "Error: Rows and columns must be between 1 and 10."
                 << endl;

            return 0;
        }

        enterMatrix(
            first_matrix,
            number_of_rows,
            number_of_columns,
            "A"
        );

        enterMatrix(
            second_matrix,
            number_of_rows,
            number_of_columns,
            "B"
        );

        addMatrices(
            first_matrix,
            second_matrix,
            result_matrix,
            number_of_rows,
            number_of_columns
        );

        cout << endl;
        cout << "Matrix A:" << endl;

        displayMatrix(
            first_matrix,
            number_of_rows,
            number_of_columns
        );

        cout << endl;
        cout << "Matrix B:" << endl;

        displayMatrix(
            second_matrix,
            number_of_rows,
            number_of_columns
        );

        cout << endl;
        cout << "Added Matrix:" << endl;

        displayMatrix(
            result_matrix,
            number_of_rows,
            number_of_columns
        );
    }


    else if (selected_operation == 3)
    {
        int first_matrix_rows;
        int first_matrix_columns;
        int second_matrix_rows;
        int second_matrix_columns;

        cout << "Enter rows for Matrix A: ";
        cin >> first_matrix_rows;

        cout << "Enter columns for Matrix A: ";
        cin >> first_matrix_columns;

        cout << "Enter rows for Matrix B: ";
        cin >> second_matrix_rows;

        cout << "Enter columns for Matrix B: ";
        cin >> second_matrix_columns;

        if (
            !dimensionsAreValid(
                first_matrix_rows,
                first_matrix_columns
            ) ||
            !dimensionsAreValid(
                second_matrix_rows,
                second_matrix_columns
            )
        )
        {
            cout << "Error: Rows and columns must be between 1 and 10."
                 << endl;

            return 0;
        }

        if (first_matrix_columns != second_matrix_rows)
        {
            cout << "Error: The columns of Matrix A must be equal "
                 << "to the rows of Matrix B." << endl;

            return 0;
        }

        enterMatrix(
            first_matrix,
            first_matrix_rows,
            first_matrix_columns,
            "A"
        );

        enterMatrix(
            second_matrix,
            second_matrix_rows,
            second_matrix_columns,
            "B"
        );

        multiplyMatrices(
            first_matrix,
            second_matrix,
            result_matrix,
            first_matrix_rows,
            first_matrix_columns,
            second_matrix_columns
        );

        cout << endl;
        cout << "Matrix A:" << endl;

        displayMatrix(
            first_matrix,
            first_matrix_rows,
            first_matrix_columns
        );

        cout << endl;
        cout << "Matrix B:" << endl;

        displayMatrix(
            second_matrix,
            second_matrix_rows,
            second_matrix_columns
        );

        cout << endl;
        cout << "Matrix A x Matrix B:" << endl;

        displayMatrix(
            result_matrix,
            first_matrix_rows,
            second_matrix_columns
        );
    }


    else
    {
        cout << "Error: Please choose option 1, 2, or 3." << endl;
    }

    return 0;
}

