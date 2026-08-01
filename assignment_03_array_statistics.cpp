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
#include <vector>
using namespace std;

// Function to calculate the sum
double calculateSum(const vector<double>& numbers) {
    double total = 0;
    for (double num : numbers) {
        total += num;
    }
    return total;
}

// Function to calculate the average
double calculateAverage(const vector<double>& numbers) {
    return calculateSum(numbers) / numbers.size();
}

// Function to find the maximum
double findMaximum(const vector<double>& numbers) {
    double maximum = numbers[0];
    for (double num : numbers) {
        if (num > maximum) {
            maximum = num;
        }
    }
    return maximum;
}

// Function to find the minimum
double findMinimum(const vector<double>& numbers) {
    double minimum = numbers[0];
    for (double num : numbers) {
        if (num < minimum) {
            minimum = num;
        }
    }
    return minimum;
}

int main() {
    int n;

    cout << "How many numbers? ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: Number of values must be greater than 0." << endl;
        return 0;
    }

    vector<double> numbers;

    for (int i = 0; i < n; i++) {
        double value;
        cout << "Enter number " << i + 1 << ": ";
        cin >> value;
        numbers.push_back(value);
    }

    cout << "\nResults:" << endl;
    cout << "Sum: " << calculateSum(numbers) << endl;
    cout << "Average: " << calculateAverage(numbers) << endl;
    cout << "Maximum: " << findMaximum(numbers) << endl;
    cout << "Minimum: " << findMinimum(numbers) << endl;

    return 0;
}
