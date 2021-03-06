//
// Created by David NGUYEN on 22/02/2022.
//

#ifndef CPLUSPLUS_SEGMENT_H
#define CPLUSPLUS_SEGMENT_H

#include "iostream"
#include "sstream"
#include "../IShape.h"
#include "../Point.h"

class Segment: public IShape{

    private:
        Point p1;
        Point p2;

    public:
        Segment(){
            this->name = "Segment";
            this->tagName = "line";
        }

        //IShape methods
        string getName() override { return this->name; }

        string getShapeTag() override{
            stringstream shapeTag;
            shapeTag << "<" << this->tagName << " x1=\"" << this->p1.getX() << "\" x2=\"" << this->p2.getX() << "\" y1=\"" << this->p1.getY() << "\" y2=\"" << this->p2.getY() <<"\" stroke=\"" << this->getShapeColor()->getColorTag() << "\"""/>";
            return shapeTag.str();
        }

        void askShapeDim() override {
            string x1, x2, y1, y2;

            cout << "--- Point 1 --- " << endl;
            while(!checkDimIsNumber(x1)) {
                cout << "x: ";
                cin >> x1;
            }

            while(!checkDimIsNumber(y1)) {
                cout << "y: ";
                cin >> y1;
            }
            p1.setPoint(stoi(x1),stoi(y1));

            cout << "--- Point 2 --- " << endl;
            while(!checkDimIsNumber(x2)) {
                cout << "x: ";
                cin >> x2;
            }

            while(!checkDimIsNumber(y2)) {
                cout << "y: ";
                cin >> y2;
            }

            p2.setPoint(stoi(x2),stoi(y2));

        }
};

#endif //CPLUSPLUS_SEGMENT_H
