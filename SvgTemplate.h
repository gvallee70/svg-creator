//
// Created by Gwendal on 06/02/2022.
//

#ifndef CPLUSPLUS_SVGTEMPLATE_H
#define CPLUSPLUS_SVGTEMPLATE_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class SvgTemplate {
    public:
        vector<string> shapeTag;

        void setHeight(int height);
        void setWidth(int width);
        int getHeight();
        int getWidth();

        string getSvgOpeningTag();
        string getSvgClosingTag();

        void setShapeTag(vector<string> tag);
        vector<string> getShapesTag();
        string getShapeTagToString();
        string getShapeTagToStringWithId();

        void exportToSvgFile(SvgTemplate svg);

        void mergeTwoDraw(string name1, string name2);

        void setSVGTag();
        string getSVGTag();

        void setDrawName(string drawName);
        string getDrawName();

        void removeShapeTag(int id);

    private:
        int height;
        int width;

        string svgTag;
        string drawName;

};


#endif //CPLUSPLUS_SVGTEMPLATE_H
