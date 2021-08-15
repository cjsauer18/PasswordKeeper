#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include "User.h"
#include <stdlib.h>
#include <Windows.h>
#include "Box.h"
#include "Colors.h"
#include "Slot.h"
//#include "PassKeeper.h"
using namespace std;


class Console {
private:

	enum
	{ LOGIN, MAIN, VAULT };

	///PassKeeper vvault;
	static User currentUser;
	static vector<User> userList; //retrieved in constructor with call to external file. (FOR BETA)
	static bool login;
	static int userID; //an integer for next available user ID. Needs to know amt of users in system so that is retrieved at runtime from DB.
	int functionPtr;
	static bool exit;


public:
	Console();
	static int currentMenuID;
	static void DeleteUser();
	static void displayUsers(); //debugging function
	static void changePassword();
	static void setUserIDs(); //sets the map count to user index.
	static void StoreUsers();
	static void DetectInputs();
	static void MenuCall(Box);
	static void Exit();


	static bool isTerminate();

	static void newUser(std::string username);   
	void Retrieval(); //parses, distingushes and accepts user input. If invalid, reprompt. If valid, call passkeeper storage
	void DisplayPasswords();
	static void Login(); //prompts user for login info, processes entry to system.
	void display();//dispaly gui of username at top, list of passwords following 

	//UTILITIES for user info storage
	void getUsers();

};