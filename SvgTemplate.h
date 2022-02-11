//
// Created by Gwendal on 06/02/2022.
//

#ifndef CPLUSPLUS_SVGTEMPLATE_H
#define CPLUSPLUS_SVGTEMPLATE_H


class SvgTemplate {
    public:
        void setHeight(int height);
        void setWidth(int width);
        int getHeight();
        int getWidth();

        void askSizeOfSVG();

    //Shape addShape(Shape shape);
    private:
        int height;
        int width;
};


#endif //CPLUSPLUS_SVGTEMPLATE_H
