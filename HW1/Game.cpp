#include <iostream>
#include <vector>
#include <string>
#include "Game.h"
#include <time.h>
using namespace std;

Board::Board(){
    rows_=10;
    cols_=10;
    int random = 0;
    for(int i = 0; i < rows_; i++){
        for(int j = 0; j < cols_; j++){
            arr_[i][j] = SquareType::Dots;//sets all of the squares to dot squares 
        }
    }
    for(int i = 0; i < 34; i++){
        arr_[wallPos[i][1]][wallPos[i][0]] = SquareType::Wall;//sets the correct positoins to walls 

    }
    for(int i = 0; i < 65; i++){
        random = rand()%10;
        if(random==1){
            arr_[validOtherPos[i][1]][validOtherPos[i][0]] = SquareType::Treasure;//randomly assigns treasures
        }
    }
    arr_[0][0]=SquareType::Pacman;//assigns pacman to 0,0
}


SquareType Board::get_square_value(Position pos) const{
    return(arr_[pos.row][pos.col]); //returns squaretpye of given position
};

	// set the value of a square to the given SquareType
void Board::SetSquareValue(Position pos, SquareType value){
    arr_[pos.row][pos.col] = value;//sets square type to given position
};

// get the possible Positions that a Player/Enemy could move to
// (not off the board or into a wall)
vector<Position> Board::GetMoves(Player *p){
    Position pPos = p->get_position();//gets the position of player
    Position p1= pPos;//creates positions for each of the 4 cardinal directions
    Position p2= pPos;
    Position p3= pPos;
    Position p4= pPos;
    p1.row+=1;
    p2.row-=1;
    p3.col+=1;
    p4.col-=1;
    vector<Position> potential{p1,p2,p3,p4};//defines a vector for the 4 directions 
    vector<Position> possible;//defines a return vector for valid positions
    for(int i = 0; i < potential.size();i++){
        SquareType temp = get_square_value(potential[i]);
        if((potential[i].row >=0)&&(potential[i].row < 10)){
            if((potential[i].col >=0)&&(potential[i].col < 10)){
                if(temp!=SquareType::Wall){//if postion isnt a wall assigns it as a valid position
                    possible.push_back(potential[i]);
                }
            }
        }
    }
    return(possible);
};

// Move a player to a new position on the board. Return
// true if they moved successfully, false otherwise.
bool Board::MovePlayer(Player *p, Position pos, std::vector<Player*> enemylist){
    vector<Position> valid = GetMoves(p);
    for(int i = 0; i < valid.size();i++){
        if(pos==valid[i]){//checks if the position passed is in the valid moves list
            for(int j = 0; j <enemylist.size();j++){//checks to make sure its not an enemy position
                if(pos==enemylist[j]->get_position()){
                    if(p->hasTreasure()){//if pacman has treasure
                        enemylist[j]->setIsDead(true);
                        p->setHasTreasure(false);//kill enemy and take treasure from pacman
                        spawnEnemy(enemylist[j]);//random spawn enemy back
                    }
                    else{
                        p->setIsDead(true);//if no treasure set pacman to dead
                        return true;
                    }
                }
            }
            if(get_square_value(pos)==SquareType::Treasure){//if its a treasure spot we make pacman powerful
                p->setHasTreasure(true);
                p->ChangePoints(100);//gives pacman 100 points for treasure
            }
            if(p->hasTreasure()){//set the square value to powerful pacman if pacman has a treasure
                
                SetSquareValue(pos,SquareType::PowerfulPacman);
            }
            else{
                SetSquareValue(pos,SquareType::Pacman);//set square value to normal pacman if not
            }
            if(isDot(pos)){
                removeDotPos(pos);//if position had a dot remove it from the dot positions
                p->ChangePoints(1);//give pacman a point
            }
            SetSquareValue(p->get_position(),SquareType::Empty);//set old square to empty
            p->SetPosition(pos);//update players position
            return true;
        }
    }
    return false;//if we havent returned yet then the position wasnt valid 
};

// Move an enemy to a new position on the board. Return
// true if they moved successfully, false otherwise.
bool Board::MoveEnemy(Player *p, Position pos){
    vector<Position> valid = GetMoves(p);
    for(int i = 0; i < valid.size();i++){
        if(pos==valid[i]){//checks to make sure position is valid
            if(isDot(pos)){
                SetSquareValue(p->get_position(),SquareType::Dots);//if old position had a dot set it back to dot
            }
            else{
                SetSquareValue(p->get_position(),SquareType::Empty);//if old position was empty set it to empty
            }
            //update square type
            p->SetPosition(pos);//if valid then move
            SetSquareValue(pos,SquareType::Enemies);
            return true;
        }
    }
    return false;//if we havent returned yet then the position wasnt valid 
};

void Board::removeDotPos(Position pos){//removes a position from list of dot positions
    for(int i =0; i <65; i++){
        if((pos.row==dotPos[i][1])&&(pos.col==dotPos[i][0])){
            dotPos[i][0]= -1;
            dotPos[i][1]= -1;
        }
    }
};

bool Board::isDot(Position pos){//checks if position has a dot
    for(int i =0; i < 65; i++){
        if((pos.row==dotPos[i][1])&&(pos.col==dotPos[i][0])){
            return true;
        }
    }
    return false;
};

void Board::spawnEnemy(Player *p){
    Position temp;
    SquareType tempType;
    bool spawned = false;
    int randX = 0;
    int randY = 0;
    while(spawned == false){//while enemy hasnt beens spawned
        randX = (rand()&9);//creates random position
        randY = (rand()&9);
        temp.col = randX;
        temp.row = randY;
        tempType = get_square_value(temp);
        if((tempType == SquareType::Dots) || (tempType == SquareType::Empty)){//checks if postion is a dot or empty
            p->SetPosition(temp);//if so spawn the enemy 
            p->setIsDead(false);
            SetSquareValue(temp,SquareType::Enemies);
            spawned = true;
        }
        //add enemies to the player list 
    }
};

std::ostream& operator<<(std::ostream& os, const Board &b){
    Position temp;//used to print out board, pretty self explanitory
    for(int i = 0; i< b.get_cols(); i++){
        temp.col = i;
        for(int j = 0; j< b.get_rows(); j++){
            temp.row = j;
            switch(b.get_square_value(temp)){
                case SquareType::Wall:
                    os << "|X|";
                    break;
                case SquareType::Dots:
                    os << "|*|";
                    break;
                case SquareType::Pacman:
                    os << "|p|";
                    break;
                case SquareType::Treasure:
                    os <<"|T|";
                    break;
                case SquareType::Enemies:
                    os <<"|~|"; 
                    break;
                case SquareType::Empty:
                    os<< "| |";
                    break;
                case SquareType::PowerfulPacman:
                    os<<"|P|";
                    break;
                case SquareType::Trap:
                    os<<"|?|";
                    break;
                case SquareType::EnemySpecialTreasure:
                    os<<"|E|";
                    break;
                default: 
                    os<<"| |";
                    break;

            }
        }
        os << endl;
    }
    return os;
    
}

Game::Game(){
    board_ = new Board;
	turn_count_ = 0;
	dots_count_ = 0;
    GameOver = false;
    
    Position temp;
    for(int i = 0; i < board_->get_rows(); i++){
        temp.row = i;
        for(int j=0; j <board_->get_cols(); j++){
            temp.col= j;
            if(board_->get_square_value(temp)==SquareType::Dots){
                dots_count_+=1;//count dots
            }
        }
    }
}; // constructor

	// initialize a new game, given one human player and
	// a number of enemies to generate
void Game::NewGame(Player *human,std::vector<Player*> enemylist, const int enemies){
    srand(time(NULL));//sets a new random seed to try and give games some variation
    bool generated = false;
    int randX = 0;
    int randY = 0;
    Position temp;
    temp.col = 0;
    temp.row = 0;
    human->SetPosition(temp); //sets position of pacman
	players_.push_back(human);//add human to the players list

    for(int i = 0; i < enemies; i++){//randomly spawns enemies
        cout << i << endl;
        generated = false;
        players_.push_back(enemylist[i]);
        while(generated == false){
            randX = (rand()&9);
            randY = (rand()&9);
            temp.col = randX;
            temp.row = randY;
            if(board_->get_square_value(temp) == SquareType::Dots){
                 enemylist[i]->SetPosition(temp);
                 board_->SetSquareValue(temp,SquareType::Enemies);
                 generated = true;
             }
        }
    }
};

// have the given Player take their turn
void Game::TakeTurn(Player *p,std::vector<Player*> enemylist){
    turn_count_+=1;//update turn count
    vector<Position>moves;
    moves= board_->GetMoves(p);//gets valid moves
    int choice = 0;
    bool moved = false;
    SquareType ptype = SquareType::Pacman;
    SquareType empty = SquareType::Empty;
    if(p->hasTreasure()){
        ptype = SquareType::PowerfulPacman;//checks if packman has treasure
    } 
    while(moved==false){//loop untill pacman has moved
        for(int i = 0; i <moves.size();i++){
            cout << i << ". Move " << p->ToRelativePosition(moves[i]) << endl;//prints out valid moves
        }
        cout << moves.size()<<endl;
        cin >> choice;
        while(!cin)//this makes sure theres no errors due to strings being input instead of ints
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout <<"Use the number associated with your choice"<<endl;
            cin >> choice;
        }
        if(choice < moves.size() ){
            moved = board_->MovePlayer(p,moves[choice],enemylist);//makes sure the choice is within moveset and wont cause seg fault
        }
        else {
            cout << "Invalid move choice, your valid move choices are :"<<endl;
        }
    }
    for(int i = 0; i < enemylist.size(); i++){
        if(enemylist[i]->isDead()==false){
            TakeTurnEnemy(enemylist[i]); //have enemies take their turn
        }
    }
};

//have the enemy take turn
void Game::TakeTurnEnemy(Player *p){
    vector<Position>moves=board_->GetMoves(p); //gets enemies valid moves
    int choice = rand() %moves.size();//chooses a random move
    if(moves[choice]==players_[0]->get_position()){//if this move hits the human
        if(players_[0]->hasTreasure()==false){//check if the human has a treasure
            players_[0]->setIsDead(true);//if he doesnt, kill him then game over
            GameOver = true;
        }
        else{
            p->setIsDead(true);//else kill this enemy
            board_->SetSquareValue(p->get_position(),SquareType::Empty);
            board_->spawnEnemy(p);//spawns enemy 
        }
    }
    else{
        board_->MoveEnemy(p,moves[choice]);//if no player then move the enemy 
    }

};

bool Game::IsGameOver(Player *p){
    if(CheckifdotsOver() ==true){//checks if theres no dots left
        cout << "Game over, You Win" << endl;
        GenerateReport(p);
        return(true);
    }
    else if(p->isDead()){
        cout << "Game over, You Lose" << endl;//checks if player is dead
        GenerateReport(p);
        return(true);
    }
    else{
        return(false);
    }
};

// return true if all pellets have been collected
bool Game::CheckifdotsOver(){
    Position temp;
    for(int i = 0; i < board_->get_rows();i++){//loops through board to see if any dots are left
        temp.row = i;
        for(int j = 0; j < board_->get_cols();j++){
            temp.col = j;
            if(board_->get_square_value(temp) == SquareType::Dots){
                return false;
            }
        }
    }
    return true;
};

// You probably want to implement these functions as well
// string info about the game's conditions after it is over
std::string Game::GenerateReport(Player *p){
    cout << "Pacman Score: " << p->get_points() << endl;
}

std::ostream& operator<<(std::ostream& os, const Game &m){
    os << "Turn Number: " << m.getTurnCount() << endl;
    os << *(m.board_) <<endl;
    return(os); 
};