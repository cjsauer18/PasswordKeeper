#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include "User.h"
#include "Box.h"
#include "Colors.h"
#include <thread>
#include <sstream>
#include "Slot.h"
using namespace std;



class PassKeeper {

private:
	//slotGrid[][] -> 2D grid denoting what goes where when printing. Could have a print column function that composes the sides of the vault.

	
	int ThreadCounter;
	int ThreadTarget;
	bool SCRAMBLE;
	bool RELEASE;
	vector<Slot>PasswordContainer; //the slots in this container will always be instantiated as isSet = false as it never is displayed.
	map<int,Slot>Container;
	User currentUser;
	string filename;
	int key;
	bool VAULT_OPEN;
	bool RETRIEVE;
	bool VAULT_EMPTY; //flag
	bool DECRYPT; //flag
	bool ENCRYPT; //flag
	bool RENDER;
	bool DISPLAY;
	bool TOGGLE;
	int passwordCount;
	int keyCount;
	static const int VAULT_HEIGHT = 150;
	static const int VAULT_WIDTH = 150;
	static const int FIRST_COL_X_COORD = 10;
	static const int SECOND_COL_X_COORD = 50;

	static const int VAULT_ROW_COUNT = 15;
	static const int VAULT_COL_COUNT = 2;
	//Slot slotMap[VAULT_ROW_COUNT][VAULT_COL_COUNT];

	int Y_COORD = 2;
	//int yKeyDisCoord;
public:
	
	void DisplayKeys();
	void toggle();
	void Scramble(Slot*);
	PassKeeper(User);
	PassKeeper();
	void reMapIDs();
	bool unlockVault();
	void DisplayVault();
	void deleteEntry(int);
	void Encrypt();
	void Decrypt();
	void recieveEntry(string);
	void Retrieve(); //utility that retrieves passwords and puts into password container. Calls decrypt.
	void StoreToFile();
	void getStorage();
	void RetrievePasswords();
	void closeVault();

};