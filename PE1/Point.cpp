#include <iostream>
#include <math.h>
#include "Point.h"

using namespace std;

Point::Point(){
    x = 0;
    y = 0;
}

Point::Point(int i, int j){
    x = i;
    y = j;
}

void Point::setX(int i){
    x=i;
}

void Point::setY(int i){
    y=i;
}

void Point::translate(int iter){
    x = x+iter;
    y = y+iter;
}

double Point::distance(Point p2){
    int p2x=p2.getX();
    int p2y=p2.getY();
    double dist = sqrt(pow((x-p2x),2) + pow((y-p2y),2));//calc euclidean dist
    return dist;
}