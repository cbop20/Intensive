#include "Circle.h"
#include "math.h"

//Caleb Starkey

//Circle could be initialized with negative radius, shrink could make radius negative, Overlaps only worked if the point was on the edge of the cirlce and sometimes would say circles overlapped even if they didn't
Circle::Circle(Point p, int rad){
    center_ = p;
    if(rad >= 0){
        radius_ = rad;
    }
    else{
        radius_ = 0;
    }
}

bool Circle::Overlaps(Circle& other){
    int radDiff = pow((other.get_radius()-radius_),2);
    int radSum = pow((other.get_radius()+radius_),2);
    Point otherCen = other.get_center();
    int dist = pow((otherCen.x-center_.x),2) + pow((otherCen.y-center_.y),2);
    if((otherCen.x == center_.x) && (otherCen.y == center_.y)){
        return true;
    }
    else if((dist >= radDiff) && (dist<=radSum)){
        return true;
    }
    else{
        return false;
    }
}

  // returns the area of this circle
int Circle::CalculateArea(){
    if(radius_ == 0){
        return 0;
    }
    else{
        int area = radius_*radius_;
        area = area*M_PI;
        return(area);
    }
}

  // increases the radius by one
void Circle::Expand(){
    radius_++;
}

  // decreases the radius by one
void Circle::Shrink(){
    if(radius_ > 0){
        radius_--;
    }
}