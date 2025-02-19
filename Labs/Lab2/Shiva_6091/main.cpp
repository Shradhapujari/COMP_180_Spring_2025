/* shiva kumar rudroju*/
#include <iostream>
using namespace std;


int additionsubtraction(int a, int b,char c) {
	if (c == '+') return a + b;
	if (c == '-') return a - b;
}
int multiplydivision(int a, int b, char c) {
	if (c == '*') return a * b;
	if (c == '/') return a / b;
}


int main() {
	int total_v = 0;
	int current_v = 0;
	char input, q = ' ';



	do {
		cout << "totalvalue" << total_v << endl;
		cout << "currentvalue" << current_v << endl;
		cout << "to exit press p" << endl;
		cout << "queue" << q << endl;
		cin >> input;
		if (input >= '0' && input <= '9') {
			current_v *= 10;
			current_v += (input - '0');
		}
		else if (input == '+' || input == '-' || input == '/' || input == '*' || input == '=') {
			if (q != ' ') {
				if (q == '+') {
					total_v = additionsubtraction(total_v, current_v, q);
					current_v = 0;
					q = input;
				}
				else if (q == '-') {
					total_v = additionsubtraction(total_v, current_v, q);
					current_v = 0;
					q = input;
				}
				else if (q == '/') {
					total_v = multiplydivision(total_v, current_v, q);
					current_v = 0;
					q = input;
				}
				else if (q == '*') {
					total_v = multiplydivision(total_v, current_v, q);
					current_v = 0;
					q = input;
				}
				else if (q == '=') {
					if (current_v != 0) total_v = current_v;
					current_v = 0;
					q = input;
				}
			}
			else {
				total_v = current_v;
				current_v = 0;
				q = input;
			}

		}

	} while (input != 'p');










	return 0;
}
