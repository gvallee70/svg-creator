//
// Created by David NGUYEN on 22/02/2022.
//

#ifndef CPLUSPLUS_CIRCLE_H
#define CPLUSPLUS_CIRCLE_H

#include "iostream"
#include "sstream"
#include "../IShape.h"

class Circle: public IShape {
public:
    int rayon;
    int cx;
    int cy;
    string name;
    string tagName;

    int getRayon() { return rayon; }
    int getCx() { return cx; }
    int getCy() { return cy; }

    string getName() { return name; }

    void setRayon(int rayon) { this->rayon = rayon; }
    void setCx(int cx) { this->cx = cx; }
    void setCy(int cy) { this->cy = cy; }

    Circle(){
        this->name = "Circle";
        this->tagName = "circle";
    }

    string getShapeTag(){
        stringstream shapeTag;
        shapeTag << "<" << this->tagName << " cx=\"" << this->getCx() << "\" cy=\"" << this->getCy() << "\" r=\"" << this->getRayon() <<"\" style=\"fill:rgb(0,0,0);\"/>";
        return shapeTag.str();
    }

    void askShapeDim() {
        int cx, cy, rayon;

        cout << "Cx : ";
        cin >> cx;
        cout << "Cy : ";
        cin >> cy;
        cout << "Rayon : ";
        cin >> rayon;

        this->setCx(cx);
        this->setCy(cy);
        this->setRayon(rayon);

    }
};

#endif //CPLUSPLUS_CIRCLE_H
