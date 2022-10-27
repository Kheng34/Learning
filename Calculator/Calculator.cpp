#include <iostream>
using namespace std;

int operation;
float num1, num2, result;
char startAgain = 'Y';

void add() {
	result = num1 + num2;
}
void subtract() {
	result = num1 - num2;
}
void multiply() {
	result = num1 * num2;
}
void divide() {
	result = num1 / num2;
}

int main() {
	while (startAgain == 'Y') {
		cout << "Welcome to The Calculator\nPlease enter the operation you want to do:\nFor Addition > 1\nFor Subtraction > 2\nFor Multiplication > 3\nFor Division > 4\n";
		cin >> operation;
		cout << "Please enter First Number:\n";
		cin >> num1;
		cout << "Please enter Second Number:\n";
		cin >> num2;
		if (operation == 1) {
			add();
		}
		else if (operation == 2) {
			subtract();
		}
		else if (operation == 3) {
			multiply();
		}
		else if (operation == 4) {
			divide();
		}
		cout << "Result: " << result << endl;
		cout << "Again? Y/N" << endl;
		cin >> startAgain;
		/*
		cout << operation << endl;
		cout << num1 << endl;
		cout << num2 << endl;
		cout << result << endl;
		*/
	}
	return 0;
}
