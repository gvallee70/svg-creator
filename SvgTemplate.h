//
// Created by Gwendal on 06/02/2022.
//

#ifndef CPLUSPLUS_SVGTEMPLATE_H
#define CPLUSPLUS_SVGTEMPLATE_H

#include <string>

using namespace std;

class SvgTemplate {
    public:
        void setHeight(int height);
        void setWidth(int width);
        int getHeight();
        int getWidth();

        string getSvgOpeningTag();
        string getSvgClosingTag();

        void setShapeTag(string tag);
        string getShapeTag();

        void exportToSvgFile();

        void mergeTwoDraw(string name1, string name2);

        void setSVGTag(string svgTag);
        string getSVGTag();

        void setDrawName(string drawName);
        string getDrawName();


    //Shape addShape(Shape shape);
    private:
        int height;
        int width;

        string shapeTag;
        string svgTag;
        string drawName;
};


#endif //CPLUSPLUS_SVGTEMPLATE_H
