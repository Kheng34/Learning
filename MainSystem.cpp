#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <windows.h>
#include <limits>
using namespace std;

int hallway, hallway2, hallway3;
int id;
string name, pass;
string nameNew, passNew;
string newUserName, newUserPass;
string databaseStr;
int totalUsers = 0;
bool hallway3Again = 1;

bool exitProgram = 0;

bool devMode = 0;

int nuclearHallway;
string nuclearCode = "0NURK1L1C";
string nuclearEntered;
bool nuclearIn = 0;
bool nuclearStartAgain = 1;

int calculatorHallway, calculatorHallway2;
float num1, num2, result;
bool calculatorHallwayAgain = 1;

bool logInTest = 0;
string passTry, nameTry;

fstream database("database.txt");

void databaseToStr() {
	stringstream buffer;
	database.open("database.txt");
	buffer << database.rdbuf();
	databaseStr = buffer.str();
	if(devMode == 1) {
	cout << databaseStr << endl << endl; //DevMode
	}
	database.close();
}

void strToDatabase() {
	database.open("database.txt",ios::out|ios::trunc);
	database << databaseStr;
	if(devMode == 1) {
	cout << databaseStr << endl << endl; //DevMode
	}
	database.close();
}

void findData() {
	for(int i = 2*id-1; i > 0; i--) {
		database.ignore(100,' ');	
	}
}

void logIn() {
	logInTest = 0;
	while(logInTest == 0) {
		cout << "Username: ";
		cin >> nameTry;
		cout << "Password: ";
		cin >> passTry;
		if(nameTry == name) {
			if(passTry == pass) {
				logInTest = 1;
				cout << "You're in!" << endl << endl << endl;
			}
			else {
				cout << "Wrong Username or Password!" << endl;
			}
		}
		else {
			if(devMode == 1) {
				cout << "Wrong Username! or Password!" << endl; //DevMode
			}
			else {
				cout << "Wrong Username or Password!" << endl;
			}
		}
	}
}

void changeData() {
	cout << "1 > Change Username\n2 > Change Pasword\n";
	cin >> hallway2;	
	if(hallway2 == 1) {
		logIn();
		cout << "New Username: ";
		cin >> nameNew;
		databaseToStr();
		databaseStr.replace(databaseStr.find(name),name.length(),nameNew);
		strToDatabase();
	}
	else if(hallway2 == 2) {
		logIn();
		cout << "New Password: ";
		cin >> passNew;
		databaseToStr();
		databaseStr.replace(databaseStr.find(pass),pass.length(),passNew);
		strToDatabase();
	}
}

void countUsers() {
	database.open("database.txt");
	string line;
	while(!database.eof()) {
		getline(database, line);
		totalUsers++;
	}
	line = "";
	database.close();
	if(devMode == 1) {
	cout << totalUsers << endl; //DevMode
	}
}

void calculator() {
	calculatorHallwayAgain = 1;
	while (calculatorHallwayAgain == 1) {
		cout << "Calculator" << endl;
		cout << "1 > Addition" << endl << "2 > Subtraction" << endl << "3 > Multiplication" << endl << "4 > Division" << endl << "5 > Back" << endl << "6 > Exit" << endl;
		cin >> calculatorHallway;
		cout << endl << endl;
		if (calculatorHallway == 1) {
			cout << "First Number: ";
			cin >> num1;
			cout << "Second Number: ";
			cin >> num2;
			result = num1 + num2;
			cout << "Result: " << result << endl;
		}
		else if (calculatorHallway == 2) {
			cout << "First Number: ";
			cin >> num1;
			cout << "Second Number: ";
			cin >> num2;
			result = num1 - num2;
			cout << "Result: " << result << endl;
		}
		else if (calculatorHallway == 3) {
			cout << "First Number: ";
			cin >> num1;
			cout << "Second Number: ";
			cin >> num2;
			result = num1 * num2;
			cout << "Result: " << result << endl;
		}
		else if (calculatorHallway == 4) {
			cout << "First Number: ";
			cin >> num1;
			cout << "Second Number: ";
			cin >> num2;
			result = num1 / num2;
			cout << "Result: " << result << endl;
		}
		else if (calculatorHallway == 5) {
			calculatorHallwayAgain = 0;
		}
		else {
			calculatorHallwayAgain = 0;
			exitProgram = 1;
		}
	}
}

void nuclearTest() {
	while (nuclearIn == 0){
		if(devMode == 1) {
			cout << nuclearCode << endl; //DevMode
		}
		cout << "Enter Nuclear Code: ";
		cin >> nuclearEntered;
		if(nuclearEntered == nuclearCode) {
			nuclearIn = 1;
			cout << "Code Success!" << endl;
		}
		else{
			cout << "Code Failed!" << endl;
		}
	}
}

void nuclearSystem() {
	nuclearStartAgain = 1;
	while(nuclearStartAgain == 1) {
		cout << "Nuclear System" << endl;
		cout << "1 > !Release the Nuke!" << endl;
		cout << "2 > Change Nuke Code" << endl;
		cout << "3 > Back" << endl;
		cout << "4 > Exit" << endl;
		cin >> nuclearHallway;
		cout << endl << endl;
		if(nuclearHallway == 1){
			nuclearTest();
			cout << "Releasing the Nuke..." << endl;
			cout << "Successful!" << endl;
		}
		else if(nuclearHallway == 2){
			nuclearTest();
			cout << "Enter new code: ";
			cin >> nuclearCode;
		}
		else if(nuclearHallway == 3) {
			nuclearStartAgain = 0;
		}
		else {
			nuclearStartAgain = 0;
			exitProgram = 1;
		}
	}
}

int main() {
	database.close();
	while(true) {
		cout << "Welcome!" << endl;
		cout << "1 > Log In\n2 > Sign Up\n3 > Exit\n";
		cin >> hallway;
		cout << endl << endl;
		if(hallway == 1) {
			database.open("database.txt");
			retryId:
			cout << "Id: ";
			cin >> id;
			if(cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Please enter a positive number!" << endl;
				goto retryId;
			}
			findData();
			database >> name;
			database >> pass;
			database.close();
			if(devMode == 1) {
				cout << name << endl; //DevMode
				cout << pass << endl; //DevMode
			}
			logIn();
			hallway3Again = 1;
			while(hallway3Again == 1) {
				cout << "Main Menu\n1 > Calculator\n2 > !Nuclear System!\n3 > Account Settings\n4 > Log Out\n5 > Exit\n";
				cin >> hallway3;
				cout << endl << endl;
				if(hallway3 == 1) {
					calculator();
					if(exitProgram == 1) {
						cout << endl;system("PAUSE");return 0;
					}
				}
				else if(hallway3 == 2) {
					nuclearSystem();
					if(exitProgram == 1) {
						cout << endl;system("PAUSE");return 0;
					}
				}
				else if(hallway3 == 3) {
					changeData();
				}
				else if(hallway3 == 4) {
					hallway3Again = 0;
				}
				else {
					cout << endl;system("PAUSE");return 0;
				}
			}
		}
		else if(hallway == 2) {
			cout << "Your Username: ";
			cin >> newUserName;
			cout << "Your Password: ";
			cin >> newUserPass;
			countUsers();
			databaseToStr();
			database.open("database.txt", ios::out | ios::app);
			database << endl << totalUsers + 1 << " " << newUserName << " " << newUserPass;
			database.close();
			databaseToStr();
			HANDLE  hConsole;
			hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, 10);
			cout << "Please note your id below, you need that for log in" << endl;
			cout << "Your Id is = " << totalUsers + 1 << endl;
			SetConsoleTextAttribute(hConsole, 7);
		}
		else if(hallway == 31) {
			if(devMode == 0) {
				devMode = 1;
				cout << "Developer Mode Activated!" << endl;
			}
			else if(devMode == 1) {
				devMode = 0;
				cout << "Developer Mode Deactivated!" << endl;
			}
		}
		else {
			cout << endl;system("PAUSE");return 0;
		}
	}
}
