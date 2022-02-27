//
// Created by David NGUYEN on 26/02/2022.
//

#ifndef CPLUSPLUS_MYLIBRARY_H
#define CPLUSPLUS_MYLIBRARY_H

#include <vector>
#include "SvgTemplate.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class MyLibrary {
    private:
        vector<SvgTemplate> myDrawings;

    public:
        vector <SvgTemplate> getMyDrawings() {
            return this->myDrawings;
        }

        string getMyDrawingsSVGTag(){
            stringstream content;
            for (SvgTemplate drawing: this->getMyDrawings()){
                content << "-> " << drawing.getDrawName() << "\n";
                content << drawing.getSVGTag() << "\n\n";
            }
            return content.str();
        }

        string getMyDrawingsName(){
            stringstream content;
            int i = 1;
            for (SvgTemplate drawing: this->getMyDrawings()){
                content << i <<"/ " << drawing.getDrawName() << "\n";
                i++;
            }
            return content.str();
        }

        void addDraw(SvgTemplate svg){
            this->myDrawings.push_back(svg);
        }

        bool filenameExists(string filename){
            string filenames = getMyDrawingsName();
            bool result = false;
            if (filenames.find(filename) != string::npos) {
                result = true;
            }
            return result;
        }

        string getShapeTag2(int id){
            SvgTemplate &svg = this->myDrawings.at(id-1);
            string result = svg.getShapeTagToString();
            return result;
        }

        SvgTemplate getSvgTemplate(int id){
            SvgTemplate &svg = this->myDrawings.at(id-1);
            return svg;
        }

        void replaceSvgTemplate(int id, SvgTemplate svg){
            this->myDrawings.at(id-1) = svg;
            this->myDrawings.at(id-1).setSVGTag();
            this->myDrawings.at(id-1).exportToSvgFile(svg);
        }
};

#endif //CPLUSPLUS_MYLIBRARY_H
