//
// Created by kissm on 23/02/2022.
//

#ifndef CPLUSPLUS_POINT_H
#define CPLUSPLUS_POINT_H
#include <string>
#include <sstream>
using namespace std;


class Point {

private:
    int x;
    int y;

public:
    Point(){}

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    void setPoint(int x, int y) {
        this->x = x;
        this->y = y;
    }

    int getX() const { return this->x; }
    int getY() const { return this->y; }

    Point getPoint() const {return *this;}

    string toString() const {
        stringstream res;
        res << getX() << "," << getY();
        return res.str();
    }

};


#endif //CPLUSPLUS_POINT_H
