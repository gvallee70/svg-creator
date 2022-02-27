//
// Created by David NGUYEN on 11/02/2022.
//

#ifndef CPLUSPLUS_RECTANGLE_H
#define CPLUSPLUS_RECTANGLE_H

#include "../IShape.h"
#include "iostream"
#include "sstream"
using namespace std;

/*class Rectangle : public IShape {
    public:
        int width;
        int height;

        Rectangle();

        void setWidth(int width);
        void setHeight(int height);
        int getWidth();
        int getHeight();

        string getShapesTag();

        void askShapeDim(){
            int width, height;

            cout << "Height : ";
            cin >> height;
            cout << "Width : ";
            cin >> width;

            this->setWidth(width);
            this->setHeight(height);
        }

};

#endif //CPLUSPLUS_RECTANGLE_H
*/

class Rectangle : public IShape {
    private:
        int width;
        int height;
        void setWidth(int width) { this->width = width; }
        void setHeight(int height) { this->height = height; }

    public:
        Rectangle() {
            this->name = "Rectangle";
            this->tagName = "rect";
        }

        int getWidth() const { return this->width; }
        int getHeight() const { return this->height; }

        //IShape methods
        string getName() override { return this->name; }

        string getShapeTag() override{
            stringstream shapeTag;
            shapeTag << "<" << this->tagName << " width=\"" << this->getWidth() << "\" height=\"" << this->getHeight() <<"\" fill=\"" << this->getShapeColor()->getColorTag() << "\"""/>";
            return shapeTag.str();
        }

        void askShapeDim() override {
            int width, height;
            cout << "Height : ";
            cin >> height;
            cout << "Width : ";
            cin >> width;

            this->setWidth(width);
            this->setHeight(height);

        }
};

#endif