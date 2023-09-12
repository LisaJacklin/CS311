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

void Player::getData(std::string& _PlayerName,
					 std::string& _playerUsername,
					 int& _gamesPlayed) 
{}

void Player::setData(std::string& _PlayerName,
					 std::string& _playerUsername,
					 int& _gamesPlayed) 
{}
//-------------------------------------------------------
//Operators definitions
Player& Player::operator++() {
	_gamesPlayed++;
	return *this;
}
Player& Player::operator++(int) {
	
	return *this;
}


Player& Player::operator--() {
	if (_gamesPlayed > 0) _gamesPlayed--;
	return *this;
}
Player& Player::operator--(int) {

	return *this;
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
	std::string _playerName;
	std::string _playerUsername;
	int _gamesPlayed;

	obj.getData(_playerName, _playerUsername, _gamesPlayed);

	return str;
};

