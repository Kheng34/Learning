#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <windows.h>
using namespace std;

int hallway, hallway2, hallway3;
int id;
string name, pass;
string nameNew, passNew;
string newUserName, newUserPass;
string databaseStr;
int totalUsers = 0;

int nuclearHallway;
string nuclearCode = "0NURK1L1C";
string nuclearEntered;
bool nuclearIn = 0;

int calculatorHallway;
float num1, num2, result;
char calculatorStartAgain = 'Y';

bool logInTest = 0;
string passTry, nameTry;

fstream database("database.txt");

void databaseToStr() {
	stringstream buffer;
	database.open("database.txt");
	buffer << database.rdbuf();
	databaseStr = buffer.str();
	cout << databaseStr << endl << endl; //DevMode
	database.close();
}

void strToDatabase() {
	database.open("database.txt",ios::out|ios::trunc);
	database << databaseStr;
	cout << databaseStr << endl << endl; //DevMode
	database.close();
}

void findData() {
	for(int i = 2*id-1; i > 0; i--) {
		database.ignore(100,' ');	
	}
}

void logIn() {
	while(logInTest == 0) {
		cout << "Username: ";
		cin >> nameTry;
		cout << "Password: ";
		cin >> passTry;
		if(nameTry == name) {
			if(passTry == pass) {
				logInTest = 1;
				cout << "You're in!" << endl;
			}
			else {
				cout << "Wrong Username or Password!" << endl;
			}
		}
		else {
			cout << "Wrong Username! or Password!" << endl; //DevMode
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
	cout << totalUsers << endl; //DevMode
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

int main() {
	database.close();
	cout << "Welcome!" << endl << "1 > Log In\n2 > Sign Up\n";
	cin >> hallway;
	if(hallway == 1) {
		database.open("database.txt");
		cout << "Id: ";
		cin >> id;
		findData();
		database >> name;
		database >> pass;
		database.close();
		cout << name << endl; //DevMode
		cout << pass << endl; //DevMode
		logIn();
		cout << "1 > Calculator\n2 > !Nuclear System!\n3 > Account Settings\n";
		cin >> hallway3;
		if(hallway3 == 1) {
			calculator();
		}
		else if(hallway3 == 2) {
			nuclearSystem();
		}
		else if(hallway3 == 3) {
			changeData();
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
	//The End
	cout << endl;system("PAUSE");return 0;
}
