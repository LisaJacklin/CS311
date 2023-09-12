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
Player::Player()
	:_playerName("Unknown"), _playerUsername("Unknown"), _gamesPlayed(0)
{}

Player::Player(std::string& _playerName, std::string& _playerUsername, int& _gamesPlayed)
	:_playerName(_playerName), _playerUsername(_playerUsername), _gamesPlayed(_gamesPlayed)
{}

//bool for if game is being played or not
bool Player::inactive() const {
	return _gamesPlayed == 0;
}

std::string Player::toString() {
	std::string ret; //gathering pieces of the tag
	ret += getName();
	ret += " (";
	ret += getUsername();
	ret += "): ";
	ret += getGames();

	return ret;
}


//-------------------------------------------------------
//Operators definitions
Player& Player::operator++() {
	_gamesPlayed++;
	return *this;
}
Player& Player::operator++(int) {
	Player ret(*this);
	++(*this);
	return ret;
}


Player& Player::operator--() {
	if (_gamesPlayed > 0) _gamesPlayed--;
	return *this;
}
Player& Player::operator--(int) {
	Player ret(*this);
	--(*this);
	return ret;
}

//setting up getting values for each variable
//setting items
std::string Player::getName() const {
	return _playerName;
}

std::string Player::getUsername() const {
	return _playerUsername;
}
int Player::getGames() const {
	return _gamesPlayed;
}

void Player::setName(std::string name) {
	_playerName = name;
}

void Player::setUsername(std::string user) {
	_playerUsername = user;
}

void Player::setGames(int a) {
	assert(a > 0); //games played must be higher than zero...
	_gamesPlayed = a;
}

//-------------------------------------------------------
//Definitions of Associated Global Operators
std::ostream& operator<<(std::ostream& str,  Player& obj) {
	
	str << obj.toString();
	return str;
};

bool operator==(const Player& num, const Player& num2) {
	return num.getName() == num2.getName() && num.getUsername() == num2.getUsername() && num.getGames() == num2.getGames();
}

bool operator!=(const Player& num, const Player& num2) {
	return !(num == num2);
}
