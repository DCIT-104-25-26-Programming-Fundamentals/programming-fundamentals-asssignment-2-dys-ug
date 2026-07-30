// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 7
// =============================================================================
//
// TASK: Console-Based To-Do List Application
//
// Build a simple to-do list program that runs entirely in the console and
// allows the user to manage their tasks interactively using a menu.
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Task
//      - Prompt the user to type a task description.
//      - Add it to the list and confirm it was added.
//
//   2. View All Tasks
//      - Display all tasks currently in the list, numbered from 1.
//      - If the list is empty, print a friendly message saying so.
//
//   3. Delete a Task
//      - Show the list of tasks with their numbers.
//      - Ask the user which task number they want to remove.
//      - Remove the task and confirm the deletion.
//      - If the task number is invalid, print an error message.
//
//   4. Quit
//      - End the program with a farewell message.
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        TO-DO LIST MENU
//   ============================
//   1. Add task
//   2. View tasks
//   3. Delete task
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Enter task: Buy groceries
//   Task added: "Buy groceries"
//
//   Enter your choice (1-4): 2
//   Your Tasks:
//   1. Buy groceries
//   2. Study for exams
//
//   Enter your choice (1-4): 3
//   Enter task number to delete: 1
//   Task "Buy groceries" has been removed.
//
//   Enter your choice (1-4): 4
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Store tasks in a vector<string> (a dynamic list of text).
// - Use a loop to keep the menu running until the user chooses to quit.
// - Each feature MUST be implemented in its own function (see scaffold below).
// - Handle invalid menu choices gracefully (print an error, do not crash).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;


void addTask(vector<string>& task_list)
{
    string task_description;

    cout << "Enter task: ";
    getline(cin, task_description);

    task_list.push_back(task_description);

    cout << "Task added: \"" << task_description << "\"" << endl;
}


void viewTasks(const vector<string>& task_list)
{
    if (task_list.size() == 0)
    {
        cout << "Your to-do list is empty." << endl;
        return;
    }

    cout << "Your Tasks:" << endl;

    for (int task_position = 0;
         task_position < task_list.size();
         task_position++)
    {
        cout << task_position + 1
             << ". "
             << task_list[task_position]
             << endl;
    }
}


void deleteTask(vector<string>& task_list)
{
    if (task_list.size() == 0)
    {
        cout << "There are no tasks to delete." << endl;
        return;
    }

    viewTasks(task_list);

    int task_number;

    cout << "Enter task number to delete: ";
    cin >> task_number;

    cin.ignore();

    if (task_number < 1 || task_number > task_list.size())
    {
        cout << "Error: Invalid task number." << endl;
        return;
    }

    int task_position = task_number - 1;

    string deleted_task = task_list[task_position];

    task_list.erase(task_list.begin() + task_position);

    cout << "Task \"" << deleted_task
         << "\" has been removed."
         << endl;
}


void displayMenu()
{
    cout << endl;
    cout << "============================" << endl;
    cout << "     TO-DO LIST MENU" << endl;
    cout << "============================" << endl;
    cout << "1. Add task" << endl;
    cout << "2. View tasks" << endl;
    cout << "3. Delete task" << endl;
    cout << "4. Quit" << endl;
}


int main()
{
    vector<string> task_list;

    bool program_running = true;

    while (program_running == true)
    {
        displayMenu();

        int selected_option;

        cout << "Enter your choice (1-4): ";
        cin >> selected_option;

        cin.ignore();

        if (selected_option == 1)
        {
            addTask(task_list);
        }
        else if (selected_option == 2)
        {
            viewTasks(task_list);
        }
        else if (selected_option == 3)
        {
            deleteTask(task_list);
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

