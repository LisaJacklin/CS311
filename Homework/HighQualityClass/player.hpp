//player.hpp
//Lisa Jacklin
//9/5/2023

//Objective: High-Quality Class
//CS 311 Data Structures and Analysis
//Homework 1

#ifndef FILE_PLAYER_HPP_INCLUDED
#define FILE_PLAYER_HPP_INCLUDED

#include <string>
//for std::osteam, std::string
#include <cassert>
//for assert usage

//-------------------------------------------------------
//Class Player - Class Definition
class Player {

	//friend definitions
	friend std::ostream & operator<<(std::ostream& str, const Player& obj);

	//-------------------------------------------------------
	//Player constructors, deconstructors, and operators
public:
	//default constructor
	Player();

	Player(std::string & _playerName, std::string& _playerUsername, int& _gamesPlayed);

	//-------------------------------------------------------
	//Player - general public functions

	void getData(std::string & _PlayerName,
				 std::string & _playerUsername,
				 int & _gamesPlayed); 


	void setData(std::string & _PlayerName,
				 std::string & _playerUsername,
				 int & _gamesPlayed);

	bool inactive() const; //should return a bool (1 if games = 0, false otherwise

	std::string toString(); //should return a string

	//-------------------------------------------------------
	//Player - general public operators
	//increment and decrement
	Player& operator++();
	Player& operator++(int);

	Player& operator--();
	Player& operator--(int);


	void setName(std::string);
	void setUsername(std::string);
	void setGames(int a);

	//-------------------------------------------------------
	//Data members/objects -----------------
private:
	std::string _playerName;
	std::string _playerUsername;
	int _gamesPlayed;

}; //end of class Player

//-------------------------------------------------------
//Class Player - Declarations of associated Global operators
//note that this function is defined in the source file.
std::ostream& operator<<(std::ostream& str, const Player& obj);

bool operator==(const Player& num, const Player& num2);
bool operator!=(const Player& num, const Player& num2);


#endif