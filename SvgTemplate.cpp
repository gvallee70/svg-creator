//
// Created by Gwendal on 06/02/2022.
//

#include "SvgTemplate.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

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

void SvgTemplate::setShapeTag(vector<string> tag){
    this->shapeTag = tag;
}

vector<string> SvgTemplate::getShapeTag(){
    return this->shapeTag;
}

void SvgTemplate::exportToSvgFile() {
    std::ofstream outfile (this->getDrawName() + ".svg");

    outfile << svgTag << std::endl;
    outfile.close();
}

void SvgTemplate::mergeTwoDraw(string shapeTag1, string shapeTag2){
    stringstream str;
    vector<string> v;
    v.push_back(shapeTag1);
    v.push_back(shapeTag2);
    this->setShapeTag(v);
    this->setSVGTag();
}

string SvgTemplate::getShapeTagToString(){
    stringstream content;
    for(string st: shapeTag){
        content << st << "\n";
    }
    return content.str();
}

string SvgTemplate::getShapeTagToStringWithId(){
    cout << "Vous voulez supprimer quel element ?" << "\n";
    stringstream content;
    int i = 1;
    for(string st: shapeTag){
        content << i << "/ " << st;
        i++;
    }
    return content.str();
}

void SvgTemplate::setSVGTag(){
    stringstream ss;
    ss << this->getSvgOpeningTag() << "\n" << this->getShapeTagToString() << "\n" << this->getSvgClosingTag();
    this->svgTag = ss.str();
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

void SvgTemplate::removeShapeTag(int id){
    this->shapeTag.erase(shapeTag.begin()+id-1);
}