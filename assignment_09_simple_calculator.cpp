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
#include <iomanip>  // For std::fixed and std::setprecision
#include <cmath>    // For std::pow
#include <limits>   // For input validation clearing

using namespace std;

// -----------------------------------------------------------------------------
// FUNCTION DECLARATIONS & DEFINITIONS
// -----------------------------------------------------------------------------

double add(double num1, double num2) {
    return num1 + num2;
}

double subtract(double num1, double num2) {
    return num1 - num2;
}

double multiply(double num1, double num2) {
    return num1 * num2;
}

bool divide(double num1, double num2, double &result) {
    if (num2 == 0) {
        return false; // Division by zero error
    }
    result = num1 / num2;
    return true;
}

bool modulus(double num1, double num2, double &result) {
    if (num2 == 0) {
        return false; // Modulus by zero error
    }
    result = std::fmod(num1, num2);
    return true;
}

double exponentiate(double base, double exp) {
    return std::pow(base, exp);
}

void printMenu() {
    cout << "       SIMPLE CALCULATOR     \n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Modulus\n";
    cout << "6. Exponentiation\n";
    cout << "7. Quit\n";
}


int main() {
    int choice = 0;
    
    // Set floating-point precision formatting to 2 decimal places
    cout << fixed << setprecision(2);

    while (true) {
        printMenu();
        cout << "Select an operation (1-7): ";
        cin >> choice;

        // Handle non-integer input gracefully
        if (cin.fail()) {
            cin.clear(); // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid selection. Please enter a number between 1 and 7.\n";
            continue;
        }

        // Check for quit condition
        if (choice == 7) {
            cout << "Goodbye!\n";
            break;
        }

        // Handle invalid menu options
        if (choice < 1 || choice > 7) {
            cout << "Oops! Invalid choice. Please select an option from 1 to 7.\n";
            continue;
        }

        double num1, num2, result;
        cout << "Enter first number : ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;

        switch (choice) {
            case 1:
                result = add(num1, num2);
                cout << "Result: " << num1 << " + " << num2 << " = " << result << "\n";
                break;

            case 2:
                result = subtract(num1, num2);
                cout << "Result: " << num1 << " - " << num2 << " = " << result << "\n";
                break;

            case 3:
                result = multiply(num1, num2);
                cout << "Result: " << num1 << " * " << num2 << " = " << result << "\n";
                break;

            case 4:
                if (divide(num1, num2, result)) {
                    cout << "Result: " << num1 << " / " << num2 << " = " << result << "\n";
                } else {
                    cout << "Error: Cannot divide by zero.\n";
                }
                break;

            case 5:
                if (modulus(num1, num2, result)) {
                    cout << "Result: " << num1 << " % " << num2 << " = " << result << "\n";
                } else {
                    cout << "Ooops! Cannot perform modulus by zero.\n";
                }
                break;

            case 6:
                result = exponentiate(num1, num2);
                cout << "Result: " << num1 << " ^ " << num2 << " = " << result << "\n";
                break;
        }
    }

    return 0;
}

