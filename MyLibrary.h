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

    public:
        vector<SvgTemplate> myDrawings;

        string getMyDrawingsSVGTag(){
            stringstream content;
            for (SvgTemplate drawing: myDrawings){
                content << drawing.getSVGTag() << "\n";
            }
            return content.str();
        }

        string getMyDrawingsName(){
            stringstream content;
            int i = 1;
            for (SvgTemplate drawing: myDrawings){
                content << i <<"/ " << drawing.getDrawName() << "\n";
                i++;
            }
            return content.str();
        }

        void addDraw(SvgTemplate svg){
            myDrawings.push_back(svg);
        }

        bool nameFileExist(string filename){
            string filenames = getMyDrawingsName();
            bool result = false;
            if (filenames.find(filename) != string::npos) {
                result = true;
            }
            return result;
        }

        string getShapeTag2(int id){
            SvgTemplate &svg = myDrawings.at(id-1);
            string result = svg.getShapeTagToString();
            return result;
        }

        SvgTemplate getSvgTemplate(int id){
            SvgTemplate &svg = myDrawings.at(id-1);
            return svg;
        }

        void replaceSvgTemplate(int id, SvgTemplate svg){
            myDrawings.at(id-1) = svg;
            myDrawings.at(id-1).setSVGTag();
            myDrawings.at(id-1).exportToSvgFile();
        }
};

#endif //CPLUSPLUS_MYLIBRARY_H
