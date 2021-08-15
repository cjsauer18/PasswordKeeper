#include "Console.h"
#include <Windows.h>
#include <sstream>
#include <iomanip>
#include <thread>
#include <condition_variable>
using namespace std;


Console::Console() {
	
	currentUser = User();
	login = false;
	userID = 0;
	getUsers();
	currentMenuID = LOGIN;
	//initialize passkeeper
	exit = false;
	//anything else that needs loading into memory before menus are prompted

}

 bool Console::isTerminate() {
	return exit;
}
//where function mapping is called
//takes into consideration the current menu, maps accordingly
//boxes each have a map key which corresponds to function call
void Console::MenuCall(Box option) {

	if (option.BoxID == 1) {
		Login();
	}
	else if (option.BoxID == 2) {
		newUser("");
	}
	else if (option.BoxID == 3) {
		Exit();
	}
	else if (option.BoxID == 4) {
		//accessVault(User user);
	}
	else if (option.BoxID == 5) {
		//Insert New Password()
	}
	else if (option.BoxID == 6) {
		//deleteEntries
	}
	else if (option.BoxID == 7) {
		//Toggle Encryption (do funky cool animation!)
	}
	else if (option.BoxID == 8) {
	
	}
	else if (option.BoxID == 9) {
	
	}
	else if (option.BoxID == 10) {
	
	}
	else if (option.BoxID == 11) {

	}
	else if (option.BoxID == 12) {

	}
	else if (option.BoxID == 13) {

	}
	//everything that returns from here will set the new menu designation

}


void Console::Exit() {
	system("cls");
	cout << "Exiting ArkEncrypt" << endl;
	Sleep(5000);
	StoreUsers();
	//ClosePassKeeper();
	exit = true;
}



bool contains(vector<User>vec, string username) {
	for (auto itr = vec.begin(); itr != vec.end(); itr++) {
		if (itr->username == username) {
			return true;
		}
	}
	return false;
}
bool verification(vector<User>vec, string username, string pass) {
	for (auto itr = vec.begin(); itr != vec.end(); itr++) {
		if (itr->username == username && itr->password == pass) {
			return true;
		}
	}
	return false;
}

void Console::Login() {
	//format to be in the middle of screen, big boxes. Some cool loading animation on the sides. Spice it up.
	while (true) {
		login = false;
		string username;
		string password;
		cout << "LOGIN" << endl;
		cout << "Username: ";
		cin >> username;
		if (!contains(userList, username)) {  //if user does not exist, prompt new user.
			newUser(username);
			system("cls");
			Login();
			return;
		}
		cout << endl;
		cout << "Password: ";
		cin >> password;
		cout << endl;
		if (verification(userList, username, password)) {
			system("cls");
			cout << "password is correct. Logging In" << endl;
			currentUser = User(username, password, userID);
			login = true;
			currentMenuID = MAIN;
			break;
		}
		else {
			cout << "Incorrect password for " << username << endl;
			Sleep(2000);
			system("cls");
		}
	}
}//login screen

void Console::newUser(string username){
	//cout << "Is this the username you want to use?"
	while (true) {
		if (username == "") {
			cout << "Create a username: ";
			cin >> username;
			cout << endl;
		}
		cout << "Create a password for " << username << endl;
		cout << "Password: ";
		string password;
		string confirm;
		cin >> password;
		cout << endl;
		cout << "Re-Enter Password: ";
		cin >> confirm;
		cout << endl;
		if (confirm == password) {
			userID++;
			userList.push_back(User(username, password, userID)); //during runtime userID should be either 1 (first entry) or >1 as the userList fills.
			return;
}
		else {
		cout << "Passwords do not match, try again" << endl;
		system("cls");
		}
	}
}

void remove(vector<User>*vec, User currentUser) {
	for (auto itr = vec->begin(); itr != vec->end(); itr++) {
		if (itr->username == currentUser.username && itr->password == currentUser.password && itr->userID == currentUser.userID) {
			vec->erase(itr);
			return;
		}
	}
}
//Updates Userlist and deletes account from both runtime container and file. Changes menu to login screen if deletion successful and otherwise back to main menu if exit.
//need to handle removing file related to user.
void Console::DeleteUser() {
	string password;
	//string username
		while (1) {
			system("cls");
			cout << "Are you sure you want to delete: " << currentUser.username << " from ArkEncrypt?" << endl;
			cout << "Re-Enter Password To Confirm: ";
			cin >> password;
			cout << endl;
			if (password == currentUser.password) {
				cout << "DELETING ACCOUNT..." << endl;
				Sleep(2000);
				system("cls");
				remove(&userList, currentUser);
				StoreUsers(); //update userlist 
				currentUser = User();
				currentMenuID = LOGIN;
				break;
			}
			else if (password == "exit") {
				cout << "Exiting" << endl;
				Sleep(5000);
				currentMenuID = MAIN;
				return;
			}else{
				cout << "Incorrect confirmation password. Re-Enter or enter 'Exit' to quit"<< endl;
				Sleep(5000);
			}
		}
	}







//utility to store user data from memory into file
//calls everytime program closes
void Console::StoreUsers() {
	ofstream output;
	output.open("userfile.txt", ofstream::out);
	for (auto itr = userList.begin(); itr != userList.end(); itr++) {
		if (itr == userList.begin()) {
			output << "USERNAMES" << " " << setw(5) << "PASSWORDS" << endl;
		}
		output << itr->username << " " << setw(5) << itr->password << " " << setw(5) << itr->userID << endl;//AES keys..
	}
	output.close();
}


//username   password
//chris      123
//jeff       234
//done to read user data into memory during runtime.
void Console::getUsers() {
	ifstream input;
	input.open("userfile.txt");
	string name;
	string pass;
	string line;
	string ID;
	stringstream buffer;
	while (getline(input, line)) {
		stringstream buffer(line);
		buffer >> name;
		if (name == "username")
			continue;
		buffer >> pass;
		buffer >> ID;
		userID++;
		userList.push_back(User(name, pass, stoi(ID)));
	}
	input.close();
}

 //calls respective functions from input
 //prompts starting menu
void Console::Retrieval() {


}//parses, distingushes and accepts user input. If invalid, reprompt. If valid, call passkeeper storage
void Console::DisplayPasswords() {


}

void printVault() {
	cout << "-" << setw(10) << endl;



}


 //prompts user for login info, processes entry to system.








void Console::display() {

}//dispaly gui of username at top, list of passwords following 


