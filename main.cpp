#include <iostream>
#include "Error_code.h"
#include "Stack.h"

using std::cout, std::cin, std::endl;

char get_command();

bool do_command(char, Stack &);

void instructions();

void introduction();

int main() {
    Stack stored_numbers;
    introduction();
    instructions();
    while (do_command(get_command(), stored_numbers));
    return 0;
}


char get_command() {
    char command;
    bool waiting = true;
    cout << "Select command and press <Enter>:";

    while (waiting) {
        cin >> command;
        command = tolower(command);
        if (command == '?' || command == '=' || command == '+' ||
            command == '-' || command == '*' || command == '/' ||
            command == 'q' || command == 'x' || command == 's' ||
            command == 'a' || command == 'h')
            waiting = false;


        else {
            cout << "Please enter a valid command:" << endl;
            instructions();
        }
    }
    return command;
}


bool do_command(char command, Stack &numbers) {
    double num1, num2;
    switch (command) {
        case '?': {
            cout << "Enter a real number: ";
            cin >> num1;
            if (numbers.push(num1) == overflow)
                cout << "Warning: Stack full, lost number" << endl;
            break;

            case '=':
                if (numbers.top(num1) == underflow)
                    cout << "Stack empty" << endl;
                else
                    cout << num1 << endl;
            break;
        }

        case '+': {
            if (numbers.top(num1) == underflow)
                cout << "Stack empty" << endl;
            else {
                numbers.pop();
                if (numbers.top(num2) == underflow) {
                    cout << "Stack has just one entry" << endl;
                    numbers.push(num1);
                } else {
                    numbers.pop();
                    if (numbers.push(num2 + num1) == overflow)
                        cout << "Warning: Stack full, lost result" << endl;
                }
            }
            break;
        }

        case '-': {
            if (numbers.top(num1) == underflow)
                cout << "Stack empty" << endl;
            else {
                numbers.pop();
                if (numbers.top(num2) == underflow) {
                    cout << "Stack has just one entry" << endl;
                    numbers.push(num1);
                } else {
                    numbers.pop();
                    if (numbers.push(num2 - num1) == overflow)
                        cout << "Warning: Stack full, lost result" << endl;
                }
            }
            break;
        }

        case '*': {
            if (numbers.top(num1) == underflow)
                cout << "Stack empty" << endl;
            else {
                numbers.pop();
                if (numbers.top(num2) == underflow) {
                    cout << "Stack has just one entry" << endl;
                    numbers.push(num1);
                } else {
                    numbers.pop();
                    if (numbers.push(num2 * num1) == overflow)
                        cout << "Warning: Stack full, lost result" << endl;
                }
            }
            break;
        }

        case '/': {
            if (numbers.top(num1) == underflow)
                cout << "Stack empty" << endl;
            else {
                numbers.pop();
                if (numbers.top(num2) == underflow) {
                    cout << "Stack has just one entry" << endl;
                    numbers.push(num1);
                } else {
                    numbers.pop();
                    if (numbers.push(num2 / num1) == overflow)
                        cout << "Warning: Stack full, lost result" << endl;
                }
            }
            break;
        }

        case 'x': {
            if (numbers.top(num1) == underflow)
                cout << "Stack empty" << endl;
            else {
                numbers.pop();
                if (numbers.top(num2) == underflow) {
                    cout << "Stack has just one entry" << endl;
                    numbers.push(num1);
                } else {
                    numbers.pop();
                    numbers.push(num1);
                    if (numbers.push(num2) == overflow)
                        cout << "Warning: Stack full, lost result" << endl;
                }
            }
            break;
        }

        case 's': {
            double sum{};
            while (!numbers.empty()) {
                numbers.top(num1);
                numbers.pop();
                sum += num1;
            }
            numbers.push(sum);
            break;
        }

        case 'a': {
            double sum{};
            int count = numbers.size();

            while(!numbers.empty()){
                numbers.top(num1);
                numbers.pop();
                sum += num1;
            }
            numbers.push(sum / count);
            break;
        }

        case 'h': {
            instructions();
            break;
        }

        case 'q': {
            cout << "Calculation finished.\n";
            return false;
        }
    }
    return true;
}

void instructions(){
    cout << "----------------------------------------------------\n"
         << "[?] Push To Stack   [=] Print Top    [X] Exchange\n"
         << "[S] Sum             [A] Average      [H] Help\n"
         << "[+] [-] [*] [/]     Are Arithmetic Operations\n"
         << "[Q] Quit.\n"
         << "----------------------------------------------------" << endl;
}

void introduction(){
    cout << "Welcome to Postfix Calculator.\n"
         << "Postfix is a mathematical notation\n"
         << "in which the operators follow the operands." << endl;
}
