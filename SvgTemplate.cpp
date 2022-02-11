//
// Created by Gwendal on 06/02/2022.
//

#include "SvgTemplate.h"
#include <iostream>
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
    stringstream svgTag;
    svgTag << "<svg width=\"" << this->getWidth() << "\" height=\"" << this->getHeight() <<"\">";
    return svgTag.str();
}

string SvgTemplate::getSvgClosingTag() {
    return "</svg>";
}

void SvgTemplate::askSizeOfSVG() {
    int height, width;
    cout << "Please enter the width of SVG:" << endl;
    cin >> width;
    this->setWidth(width);

    cout << "Please enter the height of SVG:" << endl;
    cin >> height;
    this->setHeight(height);
}