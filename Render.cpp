
#include "Render.h"


Render::Render() {
	LoginMenu = MenuBox(1, { Box(1, "LOGIN"), Box(2, "CREATE ACCOUNT"), Box(3, "EXIT") });
	MainMenu = MenuBox(2, { Box(5, "Add new password"), Box(6, "Delete Entries"), Box(7, "Re-encrypt"), Box(8, "Toggle Encryption"), Box(9, "DELETE USER") });
	VaultMenu = MenuBox(3, { Box(10, "Delete Entries"), Box(11, "Re-encrypt"), Box(12, "Toggle Encryption") });
	//thread render([this] {this->Menu(); });
}



void Render::RenderVaultAnimate() {

/*	cout << char(218);      for (int i = 0; i < 150; i++) { cout << char(196); }      cout << char(191) << endl;
	for (int i = 0; i < 50; i++) {
		cout << char(179) << " " << setw(150) << char(179) << endl;
	}
	cout << char(192);      for (int i = 0; i < 150; i++) { cout << char(196); }      cout << char(217) << e*///ndl;
	while (1) {
		if (RENDER_VAULT == true) {
			for (int j = 0; j < currentRender[0].size(); ++j) {
				cout << currentRender[0][j];
			}
			currentRender.erase(currentRender.begin()); //remove first frame displayed
			cout << currentRender.size() << endl;
			if (currentRender.size() == 1) {
				RENDER_VAULT = false;
			}
		}
		else {
			Sleep(10);
		}
	}
}


void Render::RenderVault() {
	for (int j = 0; j < currentRender[0].size(); ++j) {
		cout << currentRender[0][j];
	}
}

void Render::AddFrame(vector<Slot>frame) {
	currentRender.push_back(frame);
	//RENDER = true;
}

void Render::Menu() {
	int Set[] = { 7, 7, 7 };

	while (true) {
		system("cls");
		for (int i = 0; i < currentMenu->size; ++i) {
			cout << currentMenu->boxes[i] << endl << flush;
		}
		currentMenu->boxes[currentBoxIndex].isHighlighted = false;
		key = _getch();
		

		color(Set[0]);
		color(Set[1]);
		color(Set[2]);

		if (key == 72 && (currentBoxIndex >= lowerBound && currentBoxIndex <= upperBound)) {
			currentBoxIndex--; //up arrow key
			currentMenu->boxes[currentBoxIndex].isHighlighted = true;
			//RE_RENDER = true;
		}
		if (key == 80 && (currentBoxIndex >= lowerBound - 1 && currentBoxIndex <= upperBound - 1)) {
			//RE_RENDER = true;
			currentBoxIndex++; //down arrow key
			currentMenu->boxes[currentBoxIndex].isHighlighted = true;
		}
		if (key == '\r') { //enter
			RENDER_MENU = false;
			system("cls");
			MenuCall(currentMenu->boxes[currentBoxIndex]);  //lets keep a function pointer designated to the index of a list item in a menu, which is also the box id. 
			loadMenu();
			if (isTerminate()) {
				cout << "Terminating render" << endl;
				Sleep(2000);
				return;
			}
		}
		//default colors
		Set[0] = 7;
		Set[1] = 7;
		Set[2] = 7;
	}


}

void Render::loadMenu() {
	if (currentMenuID == LOGIN) {
		currentMenu = &LoginMenu;
	}
	else if (currentMenuID == MAIN) {
		currentMenu = &MainMenu;
	}
	else if (currentMenuID == VAULT) {
		currentMenu = &VaultMenu;
	}
	upperBound = currentMenu->size - 1;
	lowerBound = 1;
	currentBoxIndex = 1;
	return;
}



void Render::RenderMenu() {
	cout << flush;
	for (int i = 0; i < currentMenu->size; ++i) {
		cout << currentMenu->boxes[i] << endl << flush;
	}
	//RENDER_MENU = true;
}

void Render::DetectInputs() {
	RENDER_MENU = true;
	while (true) {
		if (RENDER_MENU == false) {
			Sleep(100);
			continue;
		}
		if (RE_RENDER == true) {
			system("cls");
			RenderMenu();
			RE_RENDER = false;
		
		}
	}
}