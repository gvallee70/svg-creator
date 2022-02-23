//
// Created by David NGUYEN on 22/02/2022.
//

#ifndef CPLUSPLUS_CIRCLE_H
#define CPLUSPLUS_CIRCLE_H

#include "iostream"
#include "sstream"
#include "../IShape.h"

class Circle: public IShape {
    private:
        int rayon;
        int cx;
        int cy;
        void setRayon(int rayon) { this->rayon = rayon; }
        void setCx(int cx) { this->cx = cx; }
        void setCy(int cy) { this->cy = cy; }

    public:
        Circle(){
            this->name = "Circle";
            this->tagName = "circle";
        }

        int getRayon() const { return this->rayon; }
        int getCx() const { return this->cx; }
        int getCy() const { return this->cy; }


        //IShape methods
        string getName() override { return this->name; }

        string getShapeTag() override{
            stringstream shapeTag;
            shapeTag << "<" << this->tagName << " cx=\"" << this->getCx() << "\" cy=\"" << this->getCy() << "\" r=\"" << this->getRayon() <<"\" fill=\"" << this->getShapeColor()->getColorTag() << "\"""/>";
            return shapeTag.str();
        }

        void askShapeDim() override {
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
