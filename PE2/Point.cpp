#include <iostream>
#include <math.h>
#include "Point.h"

using namespace std;

Point::Point(int n){
    for(int i=0; i < n; i++){
        pos.push_back(0);
    }
}

Point::Point(vector<int> dim){
    for(int i=0; i < (int)dim.size();i++){
        pos.push_back(dim[i]);
    }
}

void Point::setN(int dim, int n){
    pos[n] = dim;
}

int Point::getN(int n){
    return(pos[n]);
}
int Point::getSize(){
    return((int)pos.size());
}

void Point::translate(int iter){
    for(int i=0; i < (int)pos.size();i++){
        pos[i]+=iter; 
    }
}

double Point::distance(Point p2){
    double temp = 0;
    if(p2.getSize()!=(int)pos.size()){
        cout << "Point 1 and Point 2 are of different dimmensions" << endl;
        return(-1);
    }
    else{
        for(int i=0;i<(int)pos.size();i++){
            temp+=pow((pos[i]-p2.getN(i)),2);
        }
        return(sqrt(temp));
    }
}