#include <iostream>
#include <string>
#include "Player.h" 

using namespace std;

Player::Player(const std::string name, const bool is_human){
    
    name_ = name;
    points_ = 0;
    pos_.row = 0;
    pos_.col = 0; 
    is_human_ = is_human;
    has_Treasure_ = false;
    isDead_ = false;
};

void Player::ChangePoints(const int x){
    points_ +=x;
};

void Player::SetPosition(Position pos){
    pos_= pos;
};

void Player::setHasTreasure(bool treasure){
    has_Treasure_ = treasure;
};

	//checks if the enemy is dead
void Player::setIsDead(bool isdead){
    isDead_ = isdead;
};


	// You may want to implement these functions as well
	// ToRelativePosition is a function we used to translate positions
	// into directions relative to the player (up, down, etc)
string Player::ToRelativePosition(Position other){
    int delX = other.row - pos_.row;
    int delY = other.col - pos_.col;
    if(delX > 0){
        return("right");
    }
    if(delX < 0){
        return("left");
    }
    if(delY > 0){
        return("down");
    }
    else{
        return("up");
    }
};