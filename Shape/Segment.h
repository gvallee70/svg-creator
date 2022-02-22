//
// Created by David NGUYEN on 22/02/2022.
//

#ifndef CPLUSPLUS_SEGMENT_H
#define CPLUSPLUS_SEGMENT_H

#include "iostream"
#include "sstream"
#include "../IShape.h"

class Segment: public IShape{

public:
    int x1;
    int x2;
    int y1;
    int y2;
    string name;
    string tagName;

    int getX1() { return x1; }
    int getX2() { return x2; }
    int getY1() { return y1; }
    int getY2() { return y2; }

    string getName() { return name; }

    void setX1(int x1) { this->x1 = x1; }
    void setX2(int x2) { this->x2 = x2; }
    void setY1(int y1) { this->y1 = y1; }
    void setY2(int y2) { this->y2 = y2; }

    Segment(){
        this->name = "Segment";
        this->tagName = "line";
    }

    string getShapeTag(){
        stringstream shapeTag;
        shapeTag << "<" << this->tagName << " x1=\"" << this->getX1() << "\" y1=\"" << this->getY1() << "\" x2=\"" << this->getX2() << "\" y2=\"" << this->getY2() <<"\" style=\"fill:rgb(0,0,0);\"/>";
        return shapeTag.str();
    }

    void askShapeDim() {
        int x1, x2, y1, y2;

        cout << "x1 : ";
        cin >> x1;
        cout << "y1 : ";
        cin >> y1;
        cout << "x2 : ";
        cin >> x2;
        cout << "y2 : ";
        cin >> y2;

        this->setX1(x1);
        this->setY1(y1);
        this->setX2(x2);
        this->setY2(y2);

    }

};


#endif //CPLUSPLUS_SEGMENT_H
