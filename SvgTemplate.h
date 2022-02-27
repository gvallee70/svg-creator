//
// Created by Gwendal on 06/02/2022.
//

#ifndef CPLUSPLUS_SVGTEMPLATE_H
#define CPLUSPLUS_SVGTEMPLATE_H

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

class SvgTemplate {
    public:
        vector<string> shapeTag;

        int getHeight() { return this -> height; }
    
        int getWidth() { return this -> width; }

        string getSvgOpeningTag() {
            return "<svg viewBox=\"0 0 300 300\" xmlns=\"http://www.w3.org/2000/svg\">";
        }

        string getSvgClosingTag() {
            return "</svg>";
        }

        void setShapeTag(vector<string> tag){
            this->shapeTag = tag;
        }

        vector<string> getShapesTag() const{
            return this->shapeTag;
        }

        void exportToSvgFile(SvgTemplate svg) {
            std::ofstream outfile (svg.getDrawName() + ".svg");

            outfile << svg.getSVGTag() << std::endl;
            outfile.close();
        }

        void mergeTwoDraw(string shapeTag1, string shapeTag2){
            stringstream str;
            vector<string> v;
            v.push_back(shapeTag1);
            v.push_back(shapeTag2);
            this->setShapeTag(v);
            this->setSVGTag();
        }

        string getShapeTagToString(){
            stringstream content;
            for(string st: shapeTag){
                content << st << "\n";
            }
            return content.str();
        }

        string getShapeTagToStringWithId(){
            stringstream content;
            int i = 1;
            for(string st: shapeTag){
                content << i << "/ " << st;
                i++;
            }
            return content.str();
        }

        void setSVGTag(){
            stringstream ss;
            ss << this->getSvgOpeningTag() << "\n" << this->getShapeTagToString() << "\n" << this->getSvgClosingTag();
            this->svgTag = ss.str();
        }

        string getSVGTag(){
            return this->svgTag;
        }

        void setDrawName(string drawName){
            this->drawName = drawName;
        }

        string getDrawName() {
            return this->drawName;
        }

        void removeShapeTag(int id){
            this->shapeTag.erase(shapeTag.begin()+id-1);
        }

    private:
        int height;
        int width;

        string svgTag;
        string drawName;

        void setHeight(int height) {
            this -> height = height;
        }

        void setWidth(int width) {
            this -> width = width;
        }

};


#endif //CPLUSPLUS_SVGTEMPLATE_H
