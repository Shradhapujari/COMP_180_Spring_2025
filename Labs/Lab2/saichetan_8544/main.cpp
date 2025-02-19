/*sai chetan macharla*/
#include <iostream>
#include <vector>
using namespace std;


int increseDecrease(int a, int b, char c) {
	if (c == '+') return a + b;
	if (c == '-') return a - b;

}


int multplyDivide(int a, int b, char c) {
	if (c == '*') return a * b;
	if (c == '/') return a / b;
}



int main() {
	int totalValue = 0;
	int currentValue = 0;
	char input, queue = ' ';



	do {
		cout << "totalvalue = " << totalValue << endl;
		cout << "currentValue = " << currentValue << endl;
		cout << "to exit press p" << endl;
		cout << "queue" << queue << endl;
		cin >> input;
		if (input >= '0' && input <= '9') {
			currentValue *= 10;
			currentValue += (input - '0');
		}
		else if (input == '+' || input == '-' || input == '/' || input == '*' || input == '=') {
			if (queue != ' ') {
				if (queue == '+') {
					totalValue = increseDecrease(totalValue, currentValue,queue);
					currentValue = 0;
					queue = input;
				}
				else if (queue == '-') {
					totalValue = increseDecrease(totalValue, currentValue,queue);
					currentValue = 0;
					queue = input;
				}
				else if (queue == '/') {
					totalValue = multplyDivide(totalValue, currentValue,queue);
					currentValue = 0;
					queue = input;
				}
				else if (queue == '*') {
					totalValue = multplyDivide(totalValue, currentValue,queue);
					currentValue = 0;
					queue = input;
				}
				else if (queue == '=') {
					if (currentValue != 0) totalValue = currentValue;
					currentValue = 0;
					queue = input;
				}
			}
			else {
				totalValue = currentValue;
				currentValue = 0;
				queue = input;
			}

		}

	} while (input != 'p');










	return 0;
}
