//player.hpp
//Lisa Jacklin
//9/5/2023

//Objective: High-Quality Class
//CS 311 Data Structures and Analysis
//Homework 1

#ifndef FILE_PLAYER_HPP_INCLUDED
#define FILE_PLAYER_HPP_INCLUDED

#include <ostream>
//for std::osteam
#include <cassert>
//for assert usage

//-------------------------------------------------------
//Class Player - Class Definition
class Player {
	//insertion operator definition
	friend std::ostream & operator<<(std::ostream& str, const Player& obj);

	//-------------------------------------------------------
	//Player constructors, deconstructors, and operators
public:
	//note that copy constr, mov constr, copy assign, mov assign, and dstructor 
	//are all automatically generated and need not be created.

	//default constructor
	Player() {
		//player unknown, tag unknown, games zero
		setData("Unknown", "Unknown", 0);
	};

	Player(const std::string& _playerName) {};

	Player(const std::string& _playerUsername) {};

	Player(int& _gamesPlayed) {
		//will need an assert because no nonnegative.
	};

	Player(std::string & _playerName, std::string& _playerUsername, int& _gamesPlayed)
	{};

	//-------------------------------------------------------
	//Player - general public functions

	void getData(std::string & _PlayerName,
				 std::string & _playerUsername,
				 int & _gamesPlayed); 
	// stores data and calls the three pieces


	void setData(std::string & _PlayerName,
				 std::string & _playerUsername,
				 int & _gamesPlayed);
	//takes and returns nothing while calling three pieces.

	void inactive(); //should return a bool (1 if games = 0, false otherwise

	void toStirng(); //no parameters
	//reutns a string rep of the stored info: name, ( username ): games in base10 int.

	//-------------------------------------------------------
	//Player - general public operators
	Player& operator==();
	Player& operator!=();

	//pre and post incremental operators
	//stream insertion to output toString

	//-------------------------------------------------------
	//Data members -----------------
private:
	std::string _playerName;
	std::string _playerUsername;
	int _gamesPlayed;

}; //end of class Player

//-------------------------------------------------------
//Class Player - Declarations of associated Global operators
//note that this function is defined in the source file.
std::ostream& operator<<(std::ostream& str, const Player& obj);


#endif