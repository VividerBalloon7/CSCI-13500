//Name: Darius McLendon
//Due Date: 6/07/2026
//Summer '26 CSCI 13500
//Assignment 1.5 (Basic Calculator)

#include <iostream>
using namespace std;

int main() {

//Asking user to input two integers
    int n1, n2;
    cout << "Enter first integers:";
    cin >> n1;

    cout << "Enter second integer:";
    cin >> n2;

//Ask the user what operation they want to use
    char operation;
    cout << "What operation would you like to perform: ";
    cin >> operation;

//Performance and output of chosen operation
switch (operation) {

    case '+':
    cout << n1 << " + " << n2 << " = " << n1 + n2 << endl;
    break;

    case '-':
    cout << n1 << " - " << n2 << " = " << n1 - n2 << endl;
    break;

    case '*':
    cout << n1 << " * " << n2 << " = " << n1 * n2 << endl;
    break;

    case '/':
        if (n2 == 0) {
            cout << "Error! Division by zero!" << endl;
        }
        else{
            cout << n1 << " / " << n2 << " = " << n1 / n2 << endl;
        }
        break;

    case '%':
        if (n2 == 0) {
            cout << "Error! Division by zero!" << endl;
        }
        else{
            cout << n1 << " % " << n2 << " = " << n1 % n2 << endl;
        }
        break;
default:
    cout << "Invalid operation" << endl;


    }

}
