//
// Created by David NGUYEN on 11/02/2022.
//

#include "Rectangle.h"

Rectangle::Rectangle(){
    this->name = "rect";
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
    string toto = "<" + this->name + "width=" + this->getWidth() + "\" height=\"100\" ;\" />";
    return "<" + this->name + "width=" + this->getWidth() + "\" height=\"100\" style=\"fill:rgb(0,0,255);\" />";
}