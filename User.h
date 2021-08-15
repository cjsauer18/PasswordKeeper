#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <map>


struct User {
	int AES_Key;
	int AES_iv;
	std::string username;
	int userID;
	std::string password;
	User(std::string username, std::string pass, int id) {
		this->userID = id;
		this->username = username;
		this->password = pass;
		//this->AES_Key = rand();
		//this->AES_iv = rand();...
	}
	User() {}
};