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
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Student
{
    string name;
    string id;
    vector<double> scores;
};

vector<Student> students;

// Function to add a student
void addStudent()
{
    Student student;
    int numScores;

    cout << "Student name: ";
    cin.ignore();
    getline(cin, student.name);

    cout << "Student ID: ";
    getline(cin, student.id);

    cout << "How many scores? ";
    cin >> numScores;

    for (int i = 0; i < numScores; i++)
    {
        double score;
        cout << "Enter score " << i + 1 << ": ";
        cin >> score;
        student.scores.push_back(score);
    }

    students.push_back(student);
    cout << "Student \"" << student.name << "\" added successfully.\n\n";
}

// Function to display all students
void displayStudents()
{
    if (students.empty())
    {
        cout << "No students have been added yet.\n\n";
        return;
    }

    cout << "---------------------------------------------------------------------\n";
    cout << left << setw(20) << "Name"
         << setw(15) << "ID"
         << setw(20) << "Scores"
         << "Average\n";
    cout << "---------------------------------------------------------------------\n";

    for (Student student : students)
    {
        double sum = 0;

        cout << left << setw(20) << student.name
             << setw(15) << student.id;

        for (int i = 0; i < student.scores.size(); i++)
        {
            cout << student.scores[i];
            sum += student.scores[i];

            if (i != student.scores.size() - 1)
                cout << ", ";
        }

        double average = sum / student.scores.size();
        cout << "\t" << fixed << setprecision(2) << average << endl;
    }

    cout << "---------------------------------------------------------------------\n\n";
}

// Function to calculate average
void calculateAverage()
{
    string id;
    cout << "Enter student ID: ";
    cin.ignore();
    getline(cin, id);

    for (Student student : students)
    {
        if (student.id == id)
        {
            double sum = 0;

            for (double score : student.scores)
                sum += score;

            double average = sum / student.scores.size();

            cout << student.name << "'s average score: "
                 << fixed << setprecision(2)
                 << average << "\n\n";
            return;
        }
    }

    cout << "Student ID not found.\n\n";
}

int main()
{
    int choice;

    do
    {
        cout << "================================\n";
        cout << "   STUDENT RECORD SYSTEM MENU\n";
        cout << "================================\n";
        cout << "1. Add student\n";
        cout << "2. Display all students\n";
        cout << "3. Calculate average score\n";
        cout << "4. Quit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            displayStudents();
            break;
        case 3:
            calculateAverage();
            break;
        case 4:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please enter 1-4.\n\n";
        }

    } while (choice != 4);

    return 0;
}

