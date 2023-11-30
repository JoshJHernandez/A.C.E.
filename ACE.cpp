// A.C.E._C++ v1.9 //
/* This program was initially written for python. I had to do a lot of editing
   in the code as python and C++ use different libraries. For example, the
   library time was used for the time.sleep(.1) function in python, but in 
   C++ I needed to use the libraries <chrono> and <thread> in order to 
   use the function this_thread::sleep_for(chrono::milliseconds(100)).
   This function is not detrimental to how the program functions, I just liked
   how the title would procedurally print over time like an old PC booting up 
   from top to bottom instead of it printing all at once. */


#include <iostream>
#include <chrono>
#include <thread>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

time_t currentTime = time(0);
tm* currentLocalTime = localtime(&currentTime);

int intro(void) {
    cout << "░█████╗░░░░█████╗░░░░░███████╗░░░\n";
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "██╔══██╗░░░██╔══██╗░░░██╔════╝░░░\n";
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "███████║░░░██║░░╚═╝░░░█████╗░░░░░\n";
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "██╔══██║░░░██║░░██╗░░░██╔══╝░░░░░\n";
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "██║░░██║██╗╚█████╔╝██╗███████╗██╗\n";
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "╚═╝░░╚═╝╚═╝░╚════╝░╚═╝╚══════╝╚═╝(C++)v1.9\n";
    this_thread::sleep_for(chrono::milliseconds(100));
return 0;
}

int greet(void) {
    cout << "[ Press Enter to continue... ]";
    cin.ignore();
    cin.get();

    cout << "\n[ I am A.C.E., short for Automated Computational Engine. ]\n";
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "[ As of right now, I am in version 1.9, so my functions are limited to presenting the time and date, calculator, choosing a random number, and creating a number pyramid. ]";
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "\n\n[ So how may I help you today? ]";
    return 1;
}

int calc(void) {
    float num1, num2;
    char operation;

    cout << "[ Enter first number: ]\n>>> ";
    cin >> num1;

    cout << "[ Enter an operation (+, -, *, /): ]\n>>> ";
    cin >> operation;

    cout << "[ Enter second number: ]\n>>> ";
    cin >> num2;

    float result;

    switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                cout << "[ Error: Division by zero is not allowed. ]" << endl;
                return 1;
            }
            result = num1 / num2;
            break;
        default:
            cout << "[ Error: Invalid operation. ]" << endl;
            return 1;
    }

    cout << "[ Result: " << num1 << " " << operation << " " << num2 << " = " << result << " ]" << endl;

    return 2;
}

int numgen(void) {
    const int arraySize = 1; 
    int numbers[arraySize];

    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < arraySize; ++i) {
        numbers[i] = rand() % 100;
    }


    cout << "\n [ Randomly Generated number: ";
    for (int i = 0; i < arraySize; ++i) {
        cout << numbers[i] << " ]";
    }
    cout << endl;

    return 3;
}

int numpyrmd(void) {
    int numRows;

    cout << "[ Enter the number of rows for the pyramid: ]\n>>> ";
    cin >> numRows;

    if (numRows <= 0) {
        cerr << "[ Error: Invalid input. Please enter a positive integer for the number of rows. ]" << endl;
        return 1;
    }

    for (int i = 1; i <= numRows; ++i) {
        for (int j = 1; j <= numRows - i; ++j) {
            cout << "  ";
        }

        for (int j = 1; j <= i; ++j) {
            cout << j << " ";
        }

        for (int j = i - 1; j >= 1; --j) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}



int main() {
    intro();
    greet();
    
    string choice;
    bool quit = false;

    while (!quit) {
        cout << "\n[ A) The time and date. B) Calculator. C) Random Number. D) Number Pyramid. Q) Quit the program. ]\n>>> ";
        cin >> choice;
        for (char& c : choice) {
            c = toupper(c);
        }

        if (choice == "A") {
            cout << "\n[ The current time and date is: " << asctime(currentLocalTime) << "]\n";
        } else if (choice == "B") {
            calc();
        }else if (choice == "C"){
            numgen();
        }
         else if (choice == "D"){
            numpyrmd();
        }
         else if (choice == "Q") {
            quit = true;
            cout << "[ Goodbye! ]" << endl;
        } else {
            cout << "Error: Invalid input. Please try again." << endl;
        }

        if (!quit) {
            cout << "\n[ How else can I help you? ]\n";
        }
    }

    return 0;
}