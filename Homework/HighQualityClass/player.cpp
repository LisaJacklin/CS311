//player.cpp
//Lisa Jacklin
//9/5/2023

//Objective: High-Quality Class
//CS 311 Data Structures and Analysis
//Homework 1

#include "player.hpp"
//includes the player class created
#include <cassert>
//for assert
#include <ostream>
//for std::ostream;


//-------------------------------------------------------
//Definitions of class functions
void Player::getData(std::string& _PlayerName,
					 std::string& _playerUsername,
					 int& _gamesPlayed) {


}

void Player::setData(std::string& _PlayerName,
					 std::string& _playerUsername,
					 int& _gamesPlayed) {


}


//-------------------------------------------------------
//Definitions of Associated Global Operators
std::ostream& operator<<(std::ostream& str,  Player& obj) {
	std::string _playerName;
	std::string _playerUsername;
	int _gamesPlayed;

	obj.getData(_playerName, _playerUsername, _gamesPlayed);

	return str;
};

