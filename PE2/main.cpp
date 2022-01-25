#include <iostream>
#include "Point.cpp"
using namespace std;

int main(){
    Point p1;//define points
    Point p2(1,3);
    Point p3(2,-3);

    double dist1,dist2,dist3 = 0;//define distances

    dist1 = p1.distance(p2);//calc distances
    dist2 = p2.distance(p3);
    dist3 = p3.distance(p1);
    
    cout << "Point 1's coordinates: ("<< p1.getX() <<"," << p1.getY() <<")" << endl <<"Point 2's coordinates: ("<< p2.getX() <<","  << p2.getY() <<")" <<endl <<"Point 3's coordinates: ("<< p3.getX() <<","  << p3.getY() <<")" <<endl;//print coordinates    
    cout << "Point 1's distance to Point 2: " << dist1 << endl  << "Point 2's distance to Point 3: " << dist2 << endl << "Point 3's distance to Point 1: " << dist3 << endl; //print distances

    p1.translate(3);
    dist1 = p1.distance(p2);//calc distances
    dist2 = p2.distance(p3);
    dist3 = p3.distance(p1);

    cout << "Point 1's coordinates: ("<< p1.getX() <<"," << p1.getY() <<")" << endl <<"Point 2's coordinates: ("<< p2.getX() <<","  << p2.getY() <<")" <<endl <<"Point 3's coordinates: ("<< p3.getX() <<","  << p3.getY() <<")" <<endl;//print coordinates    
    cout << "Point 1's distance to Point 2: " << dist1 << endl  << "Point 2's distance to Point 3: " << dist2 << endl << "Point 3's distance to Point 1: " << dist3 << endl; //print distances

    p1.translate(-5);
    dist1 = p1.distance(p2);//calc distances
    dist2 = p2.distance(p3);
    dist3 = p3.distance(p1);

    cout << "Point 1's coordinates: ("<< p1.getX() <<"," << p1.getY() <<")" << endl <<"Point 2's coordinates: ("<< p2.getX() <<","  << p2.getY() <<")" <<endl <<"Point 3's coordinates: ("<< p3.getX() <<","  << p3.getY() <<")" <<endl;//print coordinates    
    cout << "Point 1's distance to Point 2: " << dist1 << endl  << "Point 2's distance to Point 3: " << dist2 << endl << "Point 3's distance to Point 1: " << dist3 << endl; //print distances
}