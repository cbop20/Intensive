#include <iostream>
#include <string>
#include "Game.h" 
using namespace std;

SquareType Game::get_square_value(Position pos) const{
    return(arr_[pos.row][pos.col]) 
};

	// set the value of a square to the given SquareType
void Game::SetSquareValue(Position pos, SquareType value){
    arr_[pos.row][pos.col] = value;
};

// get the possible Positions that a Player/Enemy could move to
// (not off the board or into a wall)
vector<Position> Game::GetMoves(Player *p){
    Position pPos = p->get_position;
    Position p1,p2,p3,p4 = pPos;
    p1.row+=1;
    p2.row-=1;
    p3.col+=1;
    p4.col-=1;

    vector<Position> possible{p1,p2,p3,p4};

    for(int i = ; i < possible.size();i++){
        temp = get_square_value(possible[i];
        if((p1.row > 0)||(p1.row < 10)){

        }
        if((p1.col> 0)||(p1.col < 10)){

        }
    }
};

// Move a player to a new position on the board. Return
// true if they moved successfully, false otherwise.
bool Game::MovePlayer(Player *p, Position pos, std::vector<Player*> enemylist);

// Move an enemy to a new position on the board. Return
// true if they moved successfully, false otherwise.
bool Game::MoveEnemy(Player *p, Position pos);