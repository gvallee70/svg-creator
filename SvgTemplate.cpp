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
    return "<svg viewBox=\"0 0 300 300\" xmlns=\"http://www.w3.org/2000/svg\">";
}

string SvgTemplate::getSvgClosingTag() {
    return "</svg>";
}

void SvgTemplate::setContent(string tag){
    this->content = tag;
}

string SvgTemplate::getContent(){
    return this->content;
}

void SvgTemplate::exportToSvgFile(string filename) {
    std::ofstream outfile (filename + ".svg");

    outfile << content << std::endl;
    outfile.close();
}
