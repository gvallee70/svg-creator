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

        string getShapeTag();

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
public:
    int width;
    int height;
    string name;
    string tagName;

    Rectangle(){
        this->name = "Rectangle";
        this->tagName = "rect";
    }

    int getWidth() { return width; }

    int getHeight() { return height; }

    string getName() { return name; }

    void setWidth(int width) { this->width = width; }

    void setHeight(int height) { this->height = height; }

    string getShapeTag(){
        stringstream shapeTag;
        shapeTag << "<" << this->tagName << " width=\"" << this->getWidth() << "\" height=\"" << this->getHeight() <<"\" style=\"fill:rgb(0,0,0);\"/>";
        return shapeTag.str();
    }

    void askShapeDim() {
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