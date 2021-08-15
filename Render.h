#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <thread>
#include <sstream>
#include "Box.h"
#include "Colors.h"
#include "Slot.h"
#include "Console.h"



class Render : public Console{
	enum {LOGIN, MAIN, VAULT};
private:
	static int currentBoxIndex;
	static MenuBox MainMenu;
	static MenuBox VaultMenu;
	static MenuBox LoginMenu;
	static MenuBox* currentMenu;
	static int upperBound;
	static int lowerBound;
	static bool RENDER_MENU;
	static char key;
	static bool RENDER_VAULT;
	static bool RE_RENDER; //is essentially cndition variable but uses a spin lock implementation. --> Chagne to condition variable from library so the thread sleeps instead of constatntly spinning.
	//bool MENU_FLAG;
	//bool VAULT_FLAG;
	//bool VAULT_OPEN;
	static vector<vector<Slot>>currentRender;
	


public:

	Render();
	static void RenderVaultAnimate();
	static void AddFrame(vector<Slot>f);
	static void Scramble();
	static void RenderVault();
	static void Menu();
	static void loadMenu();
	static void RenderMenu();
	static void DetectInputs();

};