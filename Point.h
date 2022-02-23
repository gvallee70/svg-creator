//
// Created by kissm on 23/02/2022.
//

#ifndef CPLUSPLUS_POINT_H
#define CPLUSPLUS_POINT_H


class Point {

private:
    int x;
    int y;



public:
    Point(){}

    void setPoint(int x, int y) {
        this->x = x;
        this->y = y;
    }

    int getX() const { return this->x; }
    int getY() const { return this->y; }

};


#endif //CPLUSPLUS_POINT_H
