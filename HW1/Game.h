#ifndef _GAME_H_
#define _GAME_H_

#include <vector>
#include "Player.h"

// you may change this enum as you need
enum class SquareType { Wall, Dots, Pacman, Treasure, Enemies, Empty, PowerfulPacman, Trap, EnemySpecialTreasure };

// TODO: implement
std::string SquareTypeStringify(SquareType sq);

class Board {
public:
	// TODO: implement
	Board();

	// already implemented in line
	int get_rows() const {return 10; }  // you should be able to change the size of your
	int get_cols() const {return 10; }  // board by changing these numbers and the numbers in the arr_ field

	// TODO: you MUST implement the following functions
	SquareType get_square_value(Position pos) const;

	// set the value of a square to the given SquareType
	void SetSquareValue(Position pos, SquareType value);

	// get the possible Positions that a Player/Enemy could move to
	// (not off the board or into a wall)
	std::vector<Position> GetMoves(Player *p);

	// Move a player to a new position on the board. Return
	// true if they moved successfully, false otherwise.
	bool MovePlayer(Player *p, Position pos, std::vector<Player*> enemylist);

  // Move an enemy to a new position on the board. Return
	// true if they moved successfully, false otherwise.
	bool MoveEnemy(Player *p, Position pos);

	void removeDotPos(Position pos);

	bool isDot(Position pos);
	
	void spawnEnemy(Player *p);
	// You probably want to implement this
	friend std::ostream& operator<<(std::ostream& os, const Board &b);

private:
	SquareType arr_[10][10];
	int rows_; // might be convenient but not necessary
	int cols_;
	int wallPos[34][2] ={{0,4},{0,5},{0,6},{0,7},{0,8},{1,2},{1,3},{1,5},{1,8},{2,2},{2,3},{2,5},{2,8},{3,5},{3,6},{3,8},{4,1},{4,2},{5,1},{5,2},{5,3},{5,4},{7,5},{7,6},{8,5},{8,6},{8,7},{8,8},{8,9},{9,5},{9,6},{9,7},{9,8},{9,9}};
	int validOtherPos[65][2] = {{0,1},{0,2},{0,3},{0,9},{1,0},{1,1},{1,4},{1,6},{1,7},{1,9},{2,0},{2,1},{2,4},{2,6},{2,7},{2,9},{3,0},{3,1},{3,2},{3,3},{3,4},{3,7},{3,9},{4,0},{4,3},{4,4},{4,5},{4,6},{4,7},{4,8},{4,9},{5,0},{5,5},{5,6},{5,7},{5,8},{5,9},{6,0},{6,1},{6,2},{6,3},{6,4},{6,5},{6,6},{6,7},{6,8},{6,9},{7,0},{7,1},{7,2},{7,3},{7,4},{7,7},{7,8},{7,9},{8,0},{8,1},{8,2},{8,3},{8,4},{9,0},{9,1},{9,2},{9,3},{9,4}};
	int dotPos[65][2] = {{0,1},{0,2},{0,3},{0,9},{1,0},{1,1},{1,4},{1,6},{1,7},{1,9},{2,0},{2,1},{2,4},{2,6},{2,7},{2,9},{3,0},{3,1},{3,2},{3,3},{3,4},{3,7},{3,9},{4,0},{4,3},{4,4},{4,5},{4,6},{4,7},{4,8},{4,9},{5,0},{5,5},{5,6},{5,7},{5,8},{5,9},{6,0},{6,1},{6,2},{6,3},{6,4},{6,5},{6,6},{6,7},{6,8},{6,9},{7,0},{7,1},{7,2},{7,3},{7,4},{7,7},{7,8},{7,9},{8,0},{8,1},{8,2},{8,3},{8,4},{9,0},{9,1},{9,2},{9,3},{9,4}};
	// you may add more fields, as needed
};  // class Board

class Game {
public:
	// TODO: implement these functions
	Game(); // constructor

	// initialize a new game, given one human player and
	// a number of enemies to generate
	void NewGame(Player *human,std::vector<Player*> enemylist, const int enemies);

	// have the given Player take their turn
	void TakeTurn(Player *p,std::vector<Player*> enemylist);

	//have the enemy take turn
	void TakeTurnEnemy(Player *p);

	bool IsGameOver(Player *p);

	// return true if all pellets have been collected
	bool CheckifdotsOver();

	int getDotCount() const {return dots_count_; }

	int getTurnCount() const {return turn_count_; }
	// You probably want to implement these functions as well
	// string info about the game's conditions after it is over
	std::string GenerateReport(Player *p);

	friend std::ostream& operator<<(std::ostream& os, const Game &m);

private:
	Board *board_;
	std::vector<Player *> players_;
	int turn_count_;
	int dots_count_;
	bool GameOver;

	// you may add more fields, as needed

};  // class Game

#endif  // _GAME_H_
