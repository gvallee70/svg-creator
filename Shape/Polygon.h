//
// Created by kissm on 23/02/2022.
//

#ifndef CPLUSPLUS_POLYGON_H
#define CPLUSPLUS_POLYGON_H
#include "iostream"
#include "sstream"
#include "../IShape.h"
#include "../Point.h"
#include <vector>

class Polygon: public IShape {
    public:

        vector<Point> points;

        Polygon(){
            this->name = "Polygon";
            this->tagName = "polygon";
        }

        //IShape methods
        string getName() override { return this->name; }

        string getPoints(){
            stringstream res;
            for (auto point : points) {
                res << point.toString() << " ";
            }
            return res.str();
        }

        string getShapeTag() override{
                stringstream shapeTag;
                shapeTag << "<" << this->tagName << " points=\"" << this->getPoints() << "\" fill=\"" << this->getShapeColor()->getColorTag() << "\"""/>";
                return shapeTag.str();
        }

        void askShapeDim() override {
            int numPoint=1;
            string myChoice;
            int x,y;

            //minimum 3 points pour un polygon
            while(numPoint<=3 || myChoice != "n"){
                cout << "--- Point " << numPoint << " ---" << endl;
                cout << "x: ";
                cin >> x;
                cout << "y:";
                cin >> y;
                this->points.push_back(*new Point(x,y));

                if(numPoint>=3) {
                    cout << "Continue (y/n) ? " << endl;
                    cin >> myChoice;
                }
                numPoint++;

            }
        }

};


#endif //CPLUSPLUS_POLYGON_H
