#pragma once

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
using namespace std;



//make function pointer to create the box (print);

void gotoxy(int, int);

void color(int);

void formatBox(std::string, int, int);

void formatBox(std::string);

//void highlightBox(struct Box);