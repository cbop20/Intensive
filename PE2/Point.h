#include <iostream>
#include <vector>
using namespace std;
class Point{
    private:
        vector<int> pos; 
    public:
        Point(int n);//constructor for n degree point
        Point(vector<int> dim);//
        void translate(int iter);
        double distance(Point p2);
        
        int getN(int n); //getters and setters
        void setN(int dim,int n);
};