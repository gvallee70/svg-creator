//
// Created by David NGUYEN on 11/02/2022.
//

#include "IShape.h"
#include "iostream"

using namespace std;

string IShape::getName(){
    return this->name;
}

string IShape::getTagName() {
    return this->tagName;
}

string IShape::getShapeTag(){
    return this->shapeTag;
}

