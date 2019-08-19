#include <iostream>
#include <stack>
#include <queue>
#include <cstring>

using namespace std;

int calculate(char *expression);
void deal(char op);

stack<char> letter;
stack<int> number;

int main() {
	char expression[50];
	cout<<"Please enter a valid expression."<<endl;
	while (cin >> expression) {
	
		int result;
		int l = strlen(expression);
		expression[l] = '\0';
		result = calculate(expression);
		cout << result % 10000 << endl;
	}
	
	return 0;
}

int calculate(char *expression) {
	int indexIn = 0;
	int cur = 0;
	bool curCache = 1;

	while (expression[indexIn] != '\0') {
		if (expression[indexIn] == '(') {
			letter.push(expression[indexIn]);
		}
		else if (expression[indexIn] >= '0' && expression[indexIn] <= '9') {
			cur *= 10;
			cur += expression[indexIn] - '0';
			curCache = 1;
		}
		else if (expression[indexIn] == '+' || expression[indexIn] == '-') {
			if (curCache) {
				number.push(cur);
				cur = 0;
			}
			curCache = 0;
			while (!letter.empty() && letter.top() != '(') {
				deal(letter.top());
				letter.pop();
			}
			letter.push(expression[indexIn]);
		}
		else if (expression[indexIn] == '*' || expression[indexIn] == '/') {
			if (curCache) {
				number.push(cur);
				cur = 0;
			}
			curCache = 0;
			while (!letter.empty() && letter.top() != '(' && letter.top() != '+' && letter.top() != '-') {
				deal(letter.top());
				letter.pop();
			}
			letter.push(expression[indexIn]);
		}
		else if (expression[indexIn] == ')') {
			if (curCache) {
				number.push(cur);
				cur = 0;
			}
			curCache = 0;
			while (!letter.empty() && letter.top() != '(') {
				deal(letter.top());
				letter.pop();
			}
			letter.pop();
		}
		indexIn++;
	}

	if (curCache) number.push(cur);

	while (!letter.empty()) {
		deal(letter.top());
		letter.pop();
	}

	return number.top();
}

void deal(char op) {
	int number_1, number_2;

	number_2 = number.top();
	number.pop();
	number_1 = number.top();
	number.pop();

	switch (op) {
	case '+':
		number.push(number_1 + number_2);
		break;
	case '-':
		number.push(number_1 - number_2);
		break;
	case '*':
		number.push(number_1 * number_2);
		break;
	case '/':
		number.push(number_1 / number_2);
		break;
	}
}
