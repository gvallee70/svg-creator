//
// Created by David NGUYEN on 22/02/2022.
//

#ifndef CPLUSPLUS_SEGMENT_H
#define CPLUSPLUS_SEGMENT_H

#include "iostream"
#include "sstream"
#include "../IShape.h"

class Segment: public IShape{

    private:
        int x1;
        int x2;
        int y1;
        int y2;
        void setX1(int x1) { this->x1 = x1; }
        void setX2(int x2) { this->x2 = x2; }
        void setY1(int y1) { this->y1 = y1; }
        void setY2(int y2) { this->y2 = y2; }


    public:
        Segment(){
            this->name = "Segment";
            this->tagName = "line";
        }
        int getX1() const { return this->x1; }
        int getX2() const { return this->x2; }
        int getY1() const { return this->y1; }
        int getY2() const { return this->y2; }

        
        //IShape methods
        string getName() override { return this->name; }

        string getShapeTag() override{
            stringstream shapeTag;
            shapeTag << "<" << this->tagName << " x1=\"" << this->getX1() << "\" x2=\"" << this->getX2() << "\" y1=\"" << this->getY1() << "\" y2=\"" << this->getY2() <<"\" stroke=\"" << this->getShapeColor()->getColorTag() << "\"""/>";
            return shapeTag.str();
        }

        void askShapeDim() override {
            int x1, x2, y1, y2;

            cout << "x1 : ";
            cin >> x1;
            cout << "x2 : ";
            cin >> x2;
            cout << "y1 : ";
            cin >> y1;
            cout << "y2 : ";
            cin >> y2;

            this->setX1(x1);
            this->setX2(x2);
            this->setY1(y1);
            this->setY2(y2);

        }

};


#endif //CPLUSPLUS_SEGMENT_H
