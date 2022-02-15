#include <iostream>
#include "Game.h"
using namespace std;


int main(){
    string name= "";
    bool good = false;
    while(good == false){//sets name
        cout << "Enter a player name between 1 and 10 characters "<< endl;
        cin >> name;
        if((name.length()>0)&&(name.length()<11)){//makes sure name isnt to long
            good = true;
        } 
    }
    Player p(name,true);//enemies and player for game
    Player e1("blue",false);
    Player e2("red",false);

    Player *pPoint = &p;
    Player *e1Point = &e1;
    Player *e2Point = &e2;

    vector<Player*> enemies{e1Point,e2Point};
    Game g;//initilize game
    g.NewGame(pPoint,enemies,2);//game play loop
    while(g.IsGameOver(pPoint)==false){
        cout<<g<<endl;
        g.TakeTurn(pPoint,enemies);
     }

}