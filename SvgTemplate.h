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

        void setContent(string tag);
        string getContent();

        void exportToSvgFile(string filename);

    //Shape addShape(Shape shape);
    private:
        int height;
        int width;

        string content;
};


#endif //CPLUSPLUS_SVGTEMPLATE_H
