#include <iostream>
using namespace std;

string cUsername = "onur";
string cPassword = "sifre";
string tUsername, tPassword;
bool getIn = 0;
int hallway;

int nuclearHallway;
string nuclearCode = "0NURK1L1C";
string nuclearEntered;
bool nuclearIn = 0;

int calculatorHallway;
float num1, num2, result;
char calculatorStartAgain = 'Y';

void logInTest() {
	while(getIn == 0){
		cout << "Username: ";
		cin >> tUsername;
		cout << "Password: ";
		cin >> tPassword;
		if(tUsername == cUsername) {
			if(tPassword == cPassword) {
				getIn = 1;
				cout << "Login successful!" << endl;
			}
			else {
				cout << "Login failed!" << endl;
				cout << "Incorrect username or password entered!" << endl;
			}
		}
		else {
		cout << "Login failed!" << endl;
		cout << "Incorrect username or password entered!" << endl;
		}
	}
}

void calculator() {
	while (calculatorStartAgain == 'Y') {
		cout << "Welcome to The Calculator" << endl << "1 > Addition" << endl << "2 > Subtraction" << endl << "3 > Multiplication" << endl << "4 > Division" << endl;
		cin >> calculatorHallway;
		cout << "First Number: ";
		cin >> num1;
		cout << "Second Number: ";
		cin >> num2;
		if (calculatorHallway == 1) {
			result = num1 + num2;
		}
		else if (calculatorHallway == 2) {
			result = num1 - num2;
		}
		else if (calculatorHallway == 3) {
			result = num1 * num2;
		}
		else if (calculatorHallway == 4) {
			result = num1 / num2;
		}
		cout << "Result: " << result << endl;
		cout << "Again? Y/N" << endl;
		cin >> calculatorStartAgain;
	}
}

void nuclearTest() {
	while (nuclearIn == 0){
		cout << "Enter Nuclear Code: ";
		cin >> nuclearEntered;
		if(nuclearEntered == nuclearCode) {
			nuclearIn = 1;
			cout << "Success!";
		}
		else{
			cout << "Failed!";
		}
	}
}

void nuclearSystem() {
	cout << "1 > !Release the Nuke!" << endl;
	cout << "2 > Change Nuke Code" << endl;
	cin >> nuclearHallway;
	if(nuclearHallway == 1){
		nuclearTest();
		cout << "Releasing the Nuke...";
		cout << "Successful!";
	}
	if(nuclearHallway == 2){
		nuclearTest();
		cout << "Enter new code: ";
		cin >> nuclearCode;
	}
}

void changeUsername() {
	
}

void changePassword() {
	
}

int main() {
	cout << "Welcome!" << endl << "Please Log In" << endl;
	logInTest();
	cout << "1 > Calculator" << endl << "2 > !Nuclear System!" << endl << "3 > Change Username" << endl << "4 > Change Password" << endl;
	cin >> hallway;
	if(hallway == 1) {
		calculator();
	}
	else if(hallway == 2) {
		nuclearSystem();
	}
	else if(hallway == 3) {
		changeUsername();
	}
	else if(hallway == 4) {
		changePassword();
	}
	return 0;
}
