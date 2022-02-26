//
// Created by Gwendal on 06/02/2022.
//

#include "SvgTemplate.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void SvgTemplate::setHeight(int height) {
    this -> height = height;
}

void SvgTemplate::setWidth(int width) {
    this -> width = width;
}

int SvgTemplate::getHeight() {
    return this -> height;
}

int SvgTemplate::getWidth() {
    return this -> width;
}

string SvgTemplate::getSvgOpeningTag() {
    return "<svg viewBox=\"0 0 300 300\" xmlns=\"http://www.w3.org/2000/svg\">";
}

string SvgTemplate::getSvgClosingTag() {
    return "</svg>";
}

void SvgTemplate::setShapeTag(string tag){
    this->shapeTag = tag;
}

string SvgTemplate::getShapeTag(){
    return this->shapeTag;
}

void SvgTemplate::exportToSvgFile() {
    std::ofstream outfile (this->getDrawName() + ".svg");

    outfile << svgTag << std::endl;
    outfile.close();
}

void SvgTemplate::mergeTwoDraw(string shapeTag1, string shapeTag2){
    stringstream str;
    str << this->getSvgOpeningTag() << "\n";
    str << shapeTag1 << "\n";
    str << shapeTag2 << "\n";
    str << this->getSvgClosingTag();
    this->setSVGTag(str.str());
}

void SvgTemplate::setSVGTag(string svgTag){
    this->svgTag = svgTag;
}

string SvgTemplate::getSVGTag(){
    return this->svgTag;
}

void SvgTemplate::setDrawName(string drawName){
    this->drawName = drawName;
}

string SvgTemplate::getDrawName() {
    return this->drawName;
}