#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include "Colors.h"
#include <thread>
#include <sstream>



struct Slot {

	int ID;
	string token; //(basically the key)
	int width = 50;
	int yCOORD;
	int xCOORD;
	bool isEmpty;
	bool isSet;
	int shift_key;
	Slot(int id, string t, int y) {
		token = t;
		isEmpty = false;

		isSet = false;
		yCOORD = y;
		shift_key = 5;
		if (yCOORD < 36) {
			xCOORD = 50; //col 1
		}
		else {
			xCOORD = 100; //col 2
		}
		width = 50;
		ID = id;
	}
	Slot() {
		isEmpty = true;
	}


	friend ostream& operator <<(ostream& out, Slot slot) {
		//clearSpace(slot);
		gotoxy(slot.xCOORD, slot.yCOORD);
		for (int i = 0; i < slot.width; ++i) {
			//gotoxy(slot.xCOORD+i, slot.yCOORD);
			out << char(196);
		}
		//gotoxy(slot.xCOORD, slot.yCOORD+1);
		//out << '\n';
		if (slot.isSet != true) { //if the slot is not completed in its decryption/encryption transition.
			int x = slot.xCOORD;//start
			int y = slot.yCOORD; //start
			//ycoord is the upper most starting point
			y++; //account for spacing 
			int distance = 0;
			while (distance != slot.width) {
				gotoxy(x, y);
				cout << "\b " << flush;
				x++;
				distance++;
			}
			gotoxy(slot.xCOORD, slot.yCOORD + 1);
			out << "| " << slot.ID << " | " << slot.token << " " << setw(47 - 3 - slot.token.size() - to_string(slot.ID).size()) << " |";// << '\n';
			gotoxy(slot.xCOORD, slot.yCOORD + 2);
			for (int i = 0; i < slot.width; ++i) {
				out << char(196);
			}
		}
		//out << '\n';
		return out;
	}

};
