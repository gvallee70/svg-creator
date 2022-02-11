//
// Created by David NGUYEN on 11/02/2022.
//

#include "Rectangle.h"
#include <sstream>

Rectangle::Rectangle(){
    this->name = "Rectangle";
    this->tagName = "rect";
}

void Rectangle::setWidth(int width){
    this->width = width;
}

void Rectangle::setHeight(int height){
    this->height = height;
}

int Rectangle::getWidth(){
    return this->width;
}

int Rectangle::getHeight() {
    return this->height;
}

string Rectangle::getShapeTag(){
    stringstream shapeTag;
    shapeTag << "<" << this->tagName << " width=\"" << this->getWidth() << "\" height=\"" << this->getHeight() <<"\" style=\"fill:rgb(0,0,0);\"/>";
    return shapeTag.str();
}