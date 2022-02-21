#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "math.h"
#include "Circle.h"


TEST_CASE ( "Circle Constructor", "[Circle]") {
  SECTION("normal call"){
    Point p;
    p.x = 0;
    p.y = 0;
    Circle c(p,1);
    Circle c1(p,5);
    Point testCen = c.get_center(); 
    Point testCen2 = c1.get_center(); 
    CHECK(c.get_radius() == 1);
    CHECK(testCen.x == p.x);
    CHECK(testCen.y == p.y);
    CHECK(c1.get_radius() == 5);
    CHECK(testCen2.x == p.x);
    CHECK(testCen2.y == p.y);
  }
  SECTION("negative radius"){
    Point p;
    p.x = 0;
    p.y = 0;
    Circle c3(p,-1);
    CHECK(c3.get_radius() == 0);
  }
}

TEST_CASE("Circle CalculateArea","[Circle]"){
  SECTION("Normal Area Call"){
    Point p;
    p.x = 0;
    p.y = 0;
    int r=2;
    Circle c(p,r);
    int area = r*r;
    area = area*M_PI;
    CHECK(c.CalculateArea()==area);
  }
  SECTION("0 Radius Area Call"){
    Point p;
    p.x = 0;
    p.y = 0;
    int r=0;
    Circle c(p,r);
    CHECK(c.CalculateArea()==0);
  }
}
TEST_CASE("Circle Expand","[Circle]"){
  SECTION("Normal Expand"){
    Point p;
    p.x = 0;
    p.y = 0;
    int r=2;
    Circle c(p,r);
    c.Expand();
    Point testCen = c.get_center(); 
    CHECK(c.get_radius()==r+1);
    CHECK(testCen.x == p.x);
    CHECK(testCen.y == p.y);
  }
}
TEST_CASE("Circle Shrink","[Circle]"){
  SECTION("Normal Shrink"){
    Point p;
    p.x = 0;
    p.y = 0;
    int r=2;
    Circle c(p,r);
    c.Shrink();
    Point testCen = c.get_center(); 
    CHECK(c.get_radius()==r-1);
    CHECK(testCen.x == p.x);
    CHECK(testCen.y == p.y);
  }
  SECTION("0 Shrink"){
    Point p;
    p.x = 0;
    p.y = 0;
    int r=0;
    Circle c(p,r);
    c.Shrink();
    Point testCen = c.get_center(); 
    CHECK(c.get_radius()==0);
    CHECK(testCen.x == p.x);
    CHECK(testCen.y == p.y);
  }
}
TEST_CASE("Circle Overlap","[Circle]"){
  SECTION("Normal Overlap"){
    Point p;
    p.x = 0;
    p.y = 0;
    int r=3;
    Circle c(p,r);

    Point p1;
    p1.x = 2;
    p1.y = 2;
    int r1=3;
    Circle c1(p1,r1);

    CHECK(c.Overlaps(c1)==true);
    CHECK(c1.Overlaps(c)==true);
  }
  SECTION("Point Circle Overlap"){
    Point p;
    p.x = 0;
    p.y = 0;
    int r=3;
    Circle c(p,r);

    Point p1;
    p1.x = 0;
    p1.y = 0;
    int r1=0;
    Circle c1(p1,r1);

    CHECK(c.Overlaps(c1)==true);
    CHECK(c1.Overlaps(c)==true);

    Point p2;
    p2.x = 3;
    p2.y = 0;
    Circle c2(p2,r1);

    CHECK(c.Overlaps(c2)==true);
    CHECK(c2.Overlaps(c)==true);
  }
  SECTION("Point Point Overlap"){
    Point p;
    p.x = 0;
    p.y = 0;
    int r=0;
    Circle c(p,r);

    Point p1;
    p1.x = 0;
    p1.y = 0;
    int r1=0;
    Circle c1(p1,r1);

    CHECK(c.Overlaps(c1)==true);
    CHECK(c1.Overlaps(c)==true);
  }
}