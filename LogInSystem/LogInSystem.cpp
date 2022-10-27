#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int hallway, hallway2;
int id;
string name, pass;
string nameNew, passNew;
string databaseStr;

bool logInTest = 0;
string passTry, nameTry;

fstream database("database.txt");

stringstream buffer;

void findData() {
	for(int i = 2*id-1; i > 0; i--) {
		database.ignore(100,' ');	
	}
}

void logIn() {
	while(logInTest == 0) {
		cout << "Name: ";
		cin >> nameTry;
		cout << "Password: ";
		cin >> passTry;
		if(nameTry == name) {
			if(passTry == pass) {
				logInTest = 1;
				cout << "You're in!" << endl;
			}
			else {
				cout << "Wrong Name or Password!" << endl;
			}
		}
		else {
			cout << "Wrong Name! or Password!" << endl; //DevMode
		}
	}
}

void changeData() {
	cout << "1 > Change Name\n2 > Change Pasword\n";
	cin >> hallway2;	
	if(hallway2 == 1) {
		logIn();
		database.open("database.txt");
		cout << "New Name: ";
		cin >> nameNew;
		buffer << database.rdbuf();
		databaseStr = buffer.str();
		cout << databaseStr << endl << endl; //DevMode
		database.close();
		databaseStr.replace(databaseStr.find(name),name.length(),nameNew);
		database.open("database.txt",ios::out|ios::trunc);
		database << databaseStr;
		cout << databaseStr; //DevMode
		database.close();	
	}
	else if(hallway2 == 2) {
		logIn();
		database.open("database.txt");
		cout << "New Password: ";
		cin >> passNew;
		buffer << database.rdbuf();
		databaseStr = buffer.str();
		cout << databaseStr << endl << endl; //DevMode
		database.close();
		databaseStr.replace(databaseStr.find(pass),pass.length(),passNew);
		database.open("database.txt",ios::out|ios::trunc);
		database << databaseStr;
		cout << databaseStr; //DevMode
		database.close();
	}
}

int main() {
	cout << "Id: ";
	cin >> id;
	findData();
	database >> name;
	database >> pass;
	database.close();	
	cout << name << endl; //DevMode
	cout << pass << endl; //DevMode
	cout << "1 > Log In\n2 > Sign In\n";
	cin >> hallway;
	if(hallway == 1) {
		logIn();
		changeData();
	}
	else if(hallway == 2) {
		database.open("database.txt");
		
		
		
		database.close();
	}	
	//The End
	cout << endl;system("PAUSE");return 0;
}
