// Shradha Pujari
// Propositional Logic Lab


#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;

bool evaluateExpression(const string& expr, const unordered_map<char, bool>& values, size_t& pos) 
{
    if (pos >= expr.size()) return false;

    char ch = expr[pos];
    if (ch == ' ') {
        pos++;
        return evaluateExpression(expr, values, pos);
    }

    if (ch == 'p' || ch == 'q' || ch == 'r') {
        pos++;
        return values.at(ch);
    }

    if (ch == '~') {
        pos++;
        return !evaluateExpression(expr, values, pos);
    }

    bool left = evaluateExpression(expr, values, pos);
    if (pos >= expr.size()) return left;

    char op = expr[pos];
    pos++;
    bool right = evaluateExpression(expr, values, pos);

    switch (op) {
	case '^': return left && right; // and
	case 'v': return left || right; // or
    case 'x': return left != right; // xor
    case '>': return !left || right; // implication
    case '=': return left == right; // bi-conditional
    default: return false;
    }
}

bool evaluateExpression(const string& expr, const unordered_map<char, bool>& values) {
    size_t pos = 0;
    return evaluateExpression(expr, values, pos);
}

void generateTruthTable(const string& expr) {
    vector<char> vars = { 'p', 'q', 'r' };
    int numVars = vars.size();
    int numRows = 1 << numVars; // 2^numVars

    
    for (char var : vars) {
        cout << var << "\t";
    }
    cout << expr << "\n";


    for (int i = 0; i < numRows; ++i) {
        unordered_map<char, bool> values;
        for (int j = 0; j < numVars; ++j) {
            values[vars[j]] = i & (1 << (numVars - j - 1));
        }

       
        for (char var : vars) {
            cout << values[var] << "\t";
        }
        cout << evaluateExpression(expr, values) << "\n";
    }
}

int main() {
    string expr;
    char input;

    do {
        cout << "Enter a propositional logical statement using variables p, q, r, ^ (AND), v (OR), ~ (NOT), x (XOR), > (Conditional ), = (Bi-Conditional):\n";
        getline(cin, expr);

        
        set<char> variables;
        for (char ch : expr) {
            if (ch == 'p' || ch == 'q' || ch == 'r') {
                variables.insert(ch);
            }
        }

        if (variables.size() != 3) {
            cout << "Error: Enter 3 variables (p, q, r) \n";
        }
        else {
            cout << "Print Truth Table \n";
            generateTruthTable(expr);

        }

        cout << "Do you want to enter another expression? (y/n): ";
        cin >> input;
        cin.ignore();
    } while (input == 'y');

    return 0;
}

