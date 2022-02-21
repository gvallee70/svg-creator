//
// Created by David NGUYEN on 11/02/2022.
//

#ifndef CPLUSPLUS_RECTANGLE_H
#define CPLUSPLUS_RECTANGLE_H

#include "../IShape.h"
using namespace std;

class Rectangle : public IShape {
    public:
        int width;
        int height;

        Rectangle();

        void setWidth(int width);
        void setHeight(int height);
        int getWidth();
        int getHeight();

        string getShapeTag();

        void askShapeDim();

};

#endif //CPLUSPLUS_RECTANGLE_H
