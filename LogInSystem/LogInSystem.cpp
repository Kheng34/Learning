#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <windows.h>
using namespace std;

int hallway, hallway2;
int id;
string name, pass;
string nameNew, passNew;
string newUserName, newUserPass;
string databaseStr;
int totalUsers = 0;

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

int main() {
	database.close();
	cout << "1 > Log In\n2 > Sign Up\n";
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
		changeData();
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
