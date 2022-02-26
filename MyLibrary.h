//
// Created by David NGUYEN on 26/02/2022.
//

#ifndef CPLUSPLUS_MYLIBRARY_H
#define CPLUSPLUS_MYLIBRARY_H

#include <vector>
#include "SvgTemplate.h"
#include <string>
#include <sstream>

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
            for (SvgTemplate drawing: myDrawings){
                content << drawing.getDrawName() << "\n";
            }
            return content.str();
        }

        void addDraw(SvgTemplate svg){
            myDrawings.push_back(svg);
        }
};

#endif //CPLUSPLUS_MYLIBRARY_H
