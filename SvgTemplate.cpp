//
// Created by Gwendal on 06/02/2022.
//

#include "SvgTemplate.h"
#include <iostream>
#include <fstream>

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
    return "<svg xmlns=\"http://www.w3.org/2000/svg\">";
}

string SvgTemplate::getSvgClosingTag() {
    return "</svg>";
}


void SvgTemplate::exportToSvgFile(string filename, string content) {
    std::ofstream outfile (filename + ".svg");

    outfile << content << std::endl;
    outfile.close();
}
