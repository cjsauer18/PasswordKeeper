#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include "Colors.h"
using namespace std;

//avoid overcomplication with function pointers. Get a black box working. 
class Box {
public:
	int BoxID;
	//vector<int>boxProps;   //contains the spacing and other properties of the box to assemble
	int boxType;
	string text;
	bool isHighlighted;
	Box(int box_id, string text) {
		BoxID = box_id;
		this->text = text;
		isHighlighted = false;
	}friend ostream& operator <<(ostream& out, Box box) {
		if (!(box.isHighlighted)) {
			out << flush;
			out << char(218);      for (int i = 0; i < 21; i++) { out << char(196); }      out << char(191) << endl;
			out << char(179) << "                     " << char(179) << endl;
			out << char(179) << "                     " << char(179) << endl;
			out << char(179) << box.text << setw(22 - box.text.size()) << char(179) << endl;
			out << char(179) << "                     " << char(179) << endl;
			out << char(179) << "                     " << char(179) << endl;
			out << char(192);      for (int i = 0; i < 21; i++) { out << char(196); }      out << char(217) << endl;
		}
		else {
			out << flush;
			out << char(201);      for (int i = 0; i < 21; i++) { out << char(205); }      out << char(187) << endl;
			out << char(186) << "                     " << char(186) << endl;
			out << char(186) << "                     " << char(186) << endl;
			out << char(186) << box.text << setw(22 - box.text.size())  << char(186) << endl;
			out << char(186) << "                     " << char(186) << endl;
			out << char(186) << "                     " << char(186) << endl;
			out << char(200);      for (int i = 0; i < 21; i++) { out << char(205); }      out << char(188) << endl;
		}
		return out;
	}
	void toggleHighlight();
};


class MenuBox {
public:
	int MenuID;
	vector<Box>boxes;
	int size;
	int xCord;
	int yCord;

    MenuBox() {}
    MenuBox(int ID, const vector<Box>boxList) {
		boxes = boxList;
		MenuID = ID;
		size = boxList.size();
		//xCord = xPos;
		//yCord = yPos;
	}
	
};

//class Menu : public MenuBox {
//	//std::vector<void (*)()> vectoroffunctions;
//
//	//SomeClass::addThingy(void (*function)())
//	vector<void (*)()> functionVector;
//	void addFunction(void (*function)()){
//	}
//
//};