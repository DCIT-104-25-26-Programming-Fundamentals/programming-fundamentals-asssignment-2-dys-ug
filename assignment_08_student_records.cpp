// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;


struct Student
{
    string name;
    int id;
    vector<double> scores;
};


double calculateAverage(const vector<double>& student_scores)
{
    double total_score = 0;

    for (int score_position = 0;
         score_position < student_scores.size();
         score_position++)
    {
        total_score = total_score + student_scores[score_position];
    }

    double average_score = total_score / student_scores.size();

    return average_score;
}


void addStudent(vector<Student>& student_records)
{
    Student new_student;

    cin.ignore();

    cout << "Student name: ";
    getline(cin, new_student.name);

    cout << "Student ID: ";
    cin >> new_student.id;

    for (int student_position = 0;
         student_position < student_records.size();
         student_position++)
    {
        if (student_records[student_position].id == new_student.id)
        {
            cout << "Error: This student ID already exists." << endl;
            return;
        }
    }

    int number_of_scores;

    cout << "How many scores? ";
    cin >> number_of_scores;

    if (number_of_scores <= 0)
    {
        cout << "Error: Number of scores must be positive." << endl;
        return;
    }

    for (int score_number = 1;
         score_number <= number_of_scores;
         score_number++)
    {
        double current_score;

        cout << "Enter score " << score_number << ": ";
        cin >> current_score;

        new_student.scores.push_back(current_score);
    }

    student_records.push_back(new_student);

    cout << "Student \"" << new_student.name
         << "\" added successfully."
         << endl;
}


void displayAllStudents(const vector<Student>& student_records)
{
    if (student_records.size() == 0)
    {
        cout << "No student records have been added." << endl;
        return;
    }

    cout << endl;
    cout << "-------------------------------------------------------------------" << endl;

    cout << left
         << setw(20) << "Name"
         << setw(15) << "ID"
         << setw(22) << "Scores"
         << setw(10) << "Average"
         << endl;

    cout << "-------------------------------------------------------------------" << endl;

    for (int student_position = 0;
         student_position < student_records.size();
         student_position++)
    {
        Student current_student = student_records[student_position];

        cout << left
             << setw(20) << current_student.name
             << setw(15) << current_student.id;

        string scores_text = "";

        for (int score_position = 0;
             score_position < current_student.scores.size();
             score_position++)
        {
            scores_text = scores_text
                + to_string(current_student.scores[score_position]);

            if (score_position < current_student.scores.size() - 1)
            {
                scores_text = scores_text + ", ";
            }
        }

        double average_score = calculateAverage(
            current_student.scores
        );

        cout << setw(22) << scores_text
             << fixed << setprecision(2)
             << average_score
             << endl;
    }

    cout << "-------------------------------------------------------------------" << endl;
}


void findStudentAverage(const vector<Student>& student_records)
{
    int student_id_to_find;

    cout << "Enter student ID: ";
    cin >> student_id_to_find;

    bool student_found = false;

    for (int student_position = 0;
         student_position < student_records.size();
         student_position++)
    {
        if (student_records[student_position].id == student_id_to_find)
        {
            double average_score = calculateAverage(
                student_records[student_position].scores
            );

            cout << student_records[student_position].name
                 << "'s average score: "
                 << fixed << setprecision(2)
                 << average_score
                 << endl;

            student_found = true;
            break;
        }
    }

    if (student_found == false)
    {
        cout << "Error: Student ID was not found." << endl;
    }
}


void displayMenu()
{
    cout << endl;
    cout << "================================" << endl;
    cout << "   STUDENT RECORD SYSTEM MENU" << endl;
    cout << "================================" << endl;
    cout << "1. Add student" << endl;
    cout << "2. Display all students" << endl;
    cout << "3. Calculate average score" << endl;
    cout << "4. Quit" << endl;
}


int main()
{
    vector<Student> student_records;

    bool program_running = true;

    while (program_running == true)
    {
        displayMenu();

        int selected_option;

        cout << "Enter your choice (1-4): ";
        cin >> selected_option;

        if (selected_option == 1)
        {
            addStudent(student_records);
        }
        else if (selected_option == 2)
        {
            displayAllStudents(student_records);
        }
        else if (selected_option == 3)
        {
            findStudentAverage(student_records);
        }
        else if (selected_option == 4)
        {
            cout << "Goodbye!" << endl;
            program_running = false;
        }
        else
        {
            cout << "Error: Please choose a number from 1 to 4." << endl;
        }
    }

    return 0;
}