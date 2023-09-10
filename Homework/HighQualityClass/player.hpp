//player.hpp
//Lisa Jacklin
//9/5/2023

//Objective: High-Quality Class
//CS 311 Data Structures and Analysis
//Homework 1

#ifndef FILE_PLAYER_HPP_INCLUDED
#define FILE_PLAYER_HPP_INCLUDED

#include <string>
//for std::string

class Player {
public:
	//note that copy constr, mov constr, copy assign, mov assign, and dstructor 
	//are all automatically generated and need not be created.

	//default constructor
	Player() {
		//set playername and playerusername to unknown,
		//games set to zero
	};

	Player(const std::string& _playerName) {};

	Player(const std::string& _playerUsername) {};

	Player(int& _gamesPlayed) {
		//will need an assert because no nonnegative.
	};

	Player(std::string & _playerName, std::string& _playerUsername, int& _gamesPlayed)
	{};

	getData(); // stores data and calls the three pieces

	setData(); //takes and returns nothing while calling three pieces.

	inactive(); //should return a bool (1 if games = 0, false otherwise

	toStirng(); //no parameters
	//reutns a string rep of the stored info: name, ( username ): games in base10 int.

	Player& operator==();
	Player& operator!=();

	//pre and post incremental operators
	//stream insertion to output toString


	//Data members -----------------
private:
	std::string _playerName;
	std::string _playerUsername;
	int _gamesPlayed;

}; //end of class Player

#endif