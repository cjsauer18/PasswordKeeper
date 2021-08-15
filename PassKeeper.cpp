#include "PassKeeper.h"


PassKeeper::PassKeeper(){}


PassKeeper::PassKeeper(User user) {
	//thread r([this] {this->render.RenderVault(); });
	currentUser = user;
	filename = currentUser.username + ".txt";
	hash<int>h;
	TOGGLE = false;
	ENCRYPT = true; //standard init
	DECRYPT = false;

	key = currentUser.userID;
	key = h(key);
	passwordCount = 0;
	ifstream file;
	//make sure file is created
	file.open(filename);
	if (file.is_open()) {
		if (file.tellg() == 0) {
			file.close();
			StoreToFile();
		}
		file.close();
	}
	else {
		file.close();
		StoreToFile();
	}
	recieveEntry("cooper14");
	recieveEntry("rebirth13333");
	recieveEntry("Thisisasuperlongpassword");
	recieveEntry("Thisisasuperlongpassword");
	recieveEntry("Thisisasuperafsadfsadfdsf");
	recieveEntry("Thisisaevenbetter");
	recieveEntry("whoareyouplayindawgg");
	recieveEntry("PAssWORDDDD12344556");
	recieveEntry("T42534534534bunchanumbers");
	
	StoreToFile();
	//RetrievePasswords();
	//int row = keyCount % 10;
	
}


//primary access function.
bool PassKeeper::unlockVault() {
	//check if user has vault, if not, create new file
	//if valut exists, call appropriate functions to pull and display (ENCRYPTED).
	ifstream file;
	if (PasswordContainer.size() == 0) {
		VAULT_EMPTY = true;
	}
	else {
		VAULT_EMPTY = false;
	}
	file.open(filename);
	string line;
	getline(file, line);
	cout << "Line: " << line << endl;
	if (line != to_string(key)) {
		cout << "Could not open vault" << endl;
		cout << "Error in matching Vault code to USER ID." << endl;
		file.close();
		return false;
	}
	
	//if empty, display empty vault
	cout << "Accessing Vault";
	Sleep(1000);
	cout << '.';
	Sleep(1000);
	cout << '.';
	Sleep(1000);
	cout << '.';
	Sleep(2000);
	//VAULT_OPEN = true;
	system("cls");
	return true;
	




}



void PassKeeper::Scramble(Slot* slot) {
	//int count = 0;
	
	while (SCRAMBLE == true) {
	//	ThreadCounter++;
		int start = rand() % slot->token.length();
		Sleep(100);
		for (int i = start; i < slot->token.length(); ++i) {
			slot->token[i]++;
			if (slot->token[i] == char(150)) {
				slot->token[i] = char(48);
			}

		}
		cout << *slot;

	//	while (RELEASE == false) {}
	}

}
//slot width might need to be checked (guarded via insertion checking. Black box hsould ignore)
//make factor dependent






bool isEqual(map<int, Slot>a, map<int, Slot>b) {
	for (int i = 0; i < b.size(); ++i) {
		if (a[i].token != b[i].token) {
			return false;
		}
	}
	return true;
}
//separate thread will run this
void PassKeeper::DisplayKeys() { //render

	//IDEALLY

	//SCRAMBLE = true;
	vector<Slot>projectionContainer = PasswordContainer; //separte vecto
	//if (TOGGLE == true) {
	for (int i = 0; i < projectionContainer.size(); ++i) {
		cout << projectionContainer[i];
	}
	while (SCRAMBLE == true) {
		for (int i = 0; i < projectionContainer.size(); ++i) {
	
			Slot* slot = &projectionContainer[i];
			int start = rand() % slot->token.length();
			//Sleep(100);
			for (int i = start; i < slot->token.length(); ++i) {
				slot->token[i]++;
				if (slot->token[i] == char(150)) {
					slot->token[i] = char(48);
				}
			}
		}
		//render.AddFrame(projectionContainer);

	}
	if (DECRYPT) {
		Decrypt();
		
		int completed = 0;
		int target = projectionContainer.size();
		bool completedArr[30] = { 0 };
		int indexCount = 0;
		while (completed != target) {
		
			if (completedArr[indexCount] == true) {
				continue;
			}
			Slot* slot = &projectionContainer[indexCount];

			string goal = PasswordContainer[slot->ID].token;

			for (int i = 0; i < slot->token.length(); ++i) {

				if (slot->token[i] > goal[i]) {
					slot->token[i]--;
				}

				else if (slot->token[i] < goal[i]) {
					slot->token[i]++;
				}
				else {
					// cout << word << endl
					continue;
				}
				//cout << 
			}
			if (slot->token == goal) {
				completedArr[indexCount] = true;
				completed++;
			}
			if (indexCount == target) {
				indexCount = 0;
			}
		 //render.AddFrame(projectionContainer);
		}

	
	}
	else if (ENCRYPT) {
		Encrypt();
		//projectionContainer = PasswordContainer;
		//string goal = Encrypt(PasswordContainer[slot->ID].token);
		int completed = 0;
		int target = projectionContainer.size(); -1;
		bool completedArr[30] = { 0 };
		int indexCount = 0;

		while (completed != target) {
			if (indexCount == target) {
				indexCount = 0;
			}
			if (completedArr[indexCount] == true) {
				continue;
			}
			Slot* slot = &projectionContainer[indexCount];
			string goal = PasswordContainer[slot->ID].token; //should be same as index of vector if ID's are matched and remapped.

			for (int i = 0; i < slot->token.length(); ++i) {

				if (slot->token[i] > goal[i]) {
					slot->token[i]--;
				}

				else if (slot->token[i] < goal[i]) {
					slot->token[i]++;
				}
				else {
					// cout << word << endl
					continue;
				}
			}
			if (slot->token == goal) {

				completedArr[indexCount] = true;
				//slot->isSet = true;
				completed++;
			}

			indexCount++;
			//render.AddFrame(projectionContainer);
		

		}	
	}
	for (int i = 0; i < projectionContainer.size(); ++i) {
		//cout << "1: " << PasswordContainer[i].token << endl;
		//cout << "2: " << projectionContainer[i].token << endl;
		cout << projectionContainer[i];
	}


}
void PassKeeper::closeVault() {

	system("cls");
}
void PassKeeper::toggle() {
	if (DECRYPT == true) {
		DECRYPT = false;
		ENCRYPT = true;
	}
	else {
		ENCRYPT = false;
		DECRYPT = true;
	}
	//TOGGLE = true;
	//SCRAMBLE = true;
	DisplayVault();
	//thread display([this] {this->DisplayKeys();});
	//Sleep(10000);
	//SCRAMBLE = false;
	//cout << "here" << endl;
	//render.RenderVault();
	//render.RenderVault();

}
void PassKeeper::DisplayVault() {
	 //flag for setting if encryption animation already exists.


	//gotoxy(10, 10);
	if (VAULT_OPEN == false) {
		cout << char(218);      for (int i = 0; i < 150; i++) { cout << char(196); }      cout << char(191) << endl;
		for (int i = 0; i < 50; i++) {

			cout << char(179) << " " << setw(150) << char(179) << endl;
		}
		cout << char(192);      for (int i = 0; i < 150; i++) { cout << char(196); }      cout << char(217) << endl;
		//	set = true;
	}
	else {
		VAULT_OPEN = true;
	}

	DisplayKeys();
	//grab password container and check flags for decrypt or encrypt
		
	
	if (VAULT_EMPTY == true) {
		gotoxy(30, 30);
		cout << "Vault is Empty" << endl;
	}
}
void PassKeeper::Encrypt() {
	//ecrypts the contianer. Checks if encrypt flag is set.

	for(int j = 0; j < PasswordContainer.size(); ++j) {
		for (int i = 0; i < PasswordContainer[j].token.length(); ++i) {
			PasswordContainer[j].token[i] -= PasswordContainer[j].shift_key;
		}
	}

	
}

//takes the container and decrypts.
void PassKeeper::Decrypt() {
	//goes through and decrypts the container.
	for (int j = 0; j < PasswordContainer.size(); ++j) {
		for (int i = 0; i < PasswordContainer[j].token.length(); ++i) {
			PasswordContainer[j].token[i] += PasswordContainer[j].shift_key;
		}
	}
}
void PassKeeper::recieveEntry(string password) {
	PasswordContainer.push_back(Slot(passwordCount, password, Y_COORD + passwordCount * 3));
	passwordCount++;

}
void remove(vector<Slot>*vec, int entryID) {
	for (auto i = vec->begin(); i != vec->end(); ++i) {
		if (i->ID == entryID) {
			vec->erase(i);
		}
	}
}
void PassKeeper::deleteEntry(int entryID) {
	//remove(&PasswordContainer, entryID); //requires assurance of direct mapping of key value pairs.
	remove(&PasswordContainer, entryID);     // .erase(entryID);
	passwordCount--;
	keyCount--;
	reMapIDs();

	//reformat (remapIDS)
}

void PassKeeper::reMapIDs() {
	//handle remapping container IDs and slotMap rendering.
	vector<Slot>container;
	for (int i = 0; i < PasswordContainer.size(); ++i) {
		Slot* slot = &PasswordContainer[i];
		slot->ID = i;//this remaps any unmatched ID's to indexes
		container.push_back(*slot);
	}
	PasswordContainer = container;
}
//utility that retrieves passwords and puts into password container. Calls decrypt.
void PassKeeper::StoreToFile() {
	ofstream output;
	output.open(filename, ios::out);
	output << key << endl;
	cout << key << endl;
	for (int i = 0; i < PasswordContainer.size(); i++) {
		output << PasswordContainer[i].ID << " " << setw(5) << PasswordContainer[i].token << endl;
	}

	output.clear();
	output.close();
}



void PassKeeper::RetrievePasswords() {
	//perform decryption when parsing? Or keep the key from AES in memory and only decrypt to a buffer ostream? So nothing is stored in memory..
	ifstream input;
	string line;
	string ID;
	string password;
	input.open(filename);
	int count = 0;
	while (getline(input, line)) {
		count++;
		stringstream buffer(line);
		if (count == 1) {
			if(line != to_string(key))
			{
				input.close();
				cout << "Error in parsing. (File could be corrupt)" << endl;
				RETRIEVE = false;
				break;
			}
			else {
				continue;
			}
		}
		passwordCount++;
		buffer >> ID >> password;
		cout << "ID|" << ID << " |Pass|" << password << "|" << endl;
		PasswordContainer.push_back(Slot(stoi(ID), password, Y_COORD + stoi(ID)*3));//ID * 3. 3 is constant height value for slot
	}

	input.close();

	//insert into slotMap for rendering.
	//int mapCount = 0;
	//for (int i = 0; i < VAULT_COL_COUNT; i++) {
	//	for (int j = 0; j < VAULT_ROW_COUNT; j++) {
	//		if (mapCount == keyCount) {
	//			return;
	//		}
	//		slotMap[j][i] = PasswordContainer[mapCount];
	//		mapCount++;
	//		
	//	}
	//}
}