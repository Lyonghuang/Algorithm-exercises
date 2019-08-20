#include <iostream>
#include <stack>
#include <queue>
#include <cstring>

using namespace std;

int calculate(char *expression);
void deal(char op, stack<int> &number);

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

/*
参数说明：
*expression：字符数组指针，即字符串，应保证字符串为合法的四则运算表达式
返回值：字符串表达式的计算结果
时间复杂度：O(n)，n为表达式长度
*/
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
				deal(letter.top(), number);
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
				deal(letter.top(), number);
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
				deal(letter.top(), number);
				letter.pop();
			}
			letter.pop();
		}
		indexIn++;
	}

	if (curCache) number.push(cur);

	while (!letter.empty()) {
		deal(letter.top(), number);
		letter.pop();
	}

	return number.top();
}

/*
参数说明
op：四则运算的四种运算符中的一种
number：临时保存表达式中访问到的数组的栈
返回值：无
算法复杂度：O(1)
函数功能额外说明：将临时保存数字的栈顶两个数字通过op运算符运算后再保存在栈顶
*/
void deal(char op, stack<int> &number) {
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
