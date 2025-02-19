/* Shradha D Pujari
COMP-180-01
Lab 2: User-Defined Functions Lab
*/

#include <iostream>
#include <vector>

using namespace std;

int ProcessQueue(int total, int current, char oper)
{
    if (oper == '+') return total + current;
    if (oper == '-') return total - current;
    if (oper == '*') return total * current;
    if (oper == '/') {
        if (current == 0) {
            cout << "Error" << endl;
            return total;
        }
        return total / current;
    }
    return total;
}

int main() 
{
    vector<char> opQueue;
    int totalValue = 0, currValue = 0;
    char input;

    do {
        cout << "Total Value =" << totalValue << endl;
        cout << "Current Value = " << currValue << endl;
        cin >> input;

        if (input >= '0' && input <= '9')
        {
            currValue = currValue * 10 + (input - '0');
        }
        else if (input == '+' || input == '-' || input == '*' || input == '/' || input == '=')
        {
            opQueue.push_back(input);
            totalValue = ProcessQueue(totalValue, currValue, opQueue.back());
            currValue = 0;
        }

    } while (input != 'q');

    return 0;
}
