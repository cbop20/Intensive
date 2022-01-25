#include <iostream>
#include "Point.cpp"
using namespace std;

int main(){
    Point p1(3);
    vector<int> v1= {3,6,5};
    Point p2(v1);//testing both constructors with 3 dimensional point
    vector<int> v2= {5,1,9,10};
    Point p3(v2);//constructor with 4 dimenstional point

    cout << p1.distance(p2) << endl;//testing distance
    p1.translate(5);
    cout << p1.distance(p2) << endl;//using updated distance to show translate works 
    cout << p2.distance(p3) << endl; //to show error when 2 points of different dimesion are compared

}