#include <iostream>
using namespace std;
class Point{
    private:
        int x;
        int y;
    public:
        Point();//arg less init
        Point(int i, int j);//using args init
        void translate(int iter);
        double distance(Point p1);
        
        int getX() {return x;}//getters and setters
        int getY() {return y;}
        void setX(int i);
        void setY(int i);
};