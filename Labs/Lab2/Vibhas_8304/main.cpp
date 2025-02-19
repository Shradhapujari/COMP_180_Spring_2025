#pragma once
//Name: Venkata Vibhas
#include <iostream>

using namespace std;

int SubAdd(int a, int b, char c) {
    if (c == '+') return a + b;
    if (c == '-') return a - b;
}
int MulDiv(int a, int b, char c) {
    if (c == '*') return a * b;
    if (c == '/') return a / b;
 }
int main()
{
    int totalvalue = 0; int currentvalue = 0; char q = ' ';
    char input = ' ';
    do {
        cout << "Total value = " << totalvalue << endl; cout << "Current Value = " << currentvalue << endl; cout << "Valid Operators : +,-,*,/" << endl;
        cin >> input;
        input = tolower(input);
        if (input >= '0' && input <= '9') {
            currentvalue *= 10;
            currentvalue += (input - '0');
        }
        else if (input == '+' || input == '-' || input == '*' || input == '/' || input == '=') {
            if (q != ' ') {
                if (q == '+') {
                    totalvalue = SubAdd(totalvalue, currentvalue, q);
                    currentvalue = 0;
                    q = input;
                }
                else if (q == '-') {
                    totalvalue = SubAdd(totalvalue, currentvalue, q);
                    currentvalue = 0;
                    q = input;
                }
                else if (q == '*') {
                    totalvalue = MulDiv(totalvalue, currentvalue, q);
                    currentvalue = 0;
                    q = input;
                }
                else if (q == '/') {
                    if (currentvalue != 0) totalvalue = MulDiv(totalvalue, currentvalue, q);
                    currentvalue = 0;
                    q = input;
                }
                else if (q == '=') {
                    if (currentvalue != 0) totalvalue = currentvalue;
                    currentvalue = 0;
                    q = input;
                }
            }
            else {
                totalvalue = currentvalue;
                currentvalue = 0;
                q = input;
            }
        }
    } while (input != 'A');
}
