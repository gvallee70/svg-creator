//
// Created by kissm on 24/02/2022.
//

#ifndef CPLUSPLUS_MYCLI_H
#define CPLUSPLUS_MYCLI_H
#include <iostream>
#include "SvgTemplate.h"
#include "Shape/Rectangle.h"
#include "Shape/Circle.h"
#include "Shape/Segment.h"
#include "Shape/Polygon.h"
#include <sstream>
using namespace std;

class MyCLI {
public:
    IShape* shapeToDraw;
    IShape *shapes[4] = {new Rectangle(), new Circle(), new Segment(), new Polygon()};
    SvgTemplate svgTemplate;
    string svgTag;


    IShape* getListShapes(){
        return *shapes;
    }

    int sizeListShape(){
        return sizeof(*shapes);
    }

    IShape* getShapeToDraw() const{
        return shapeToDraw;
    }

    string getSvgTag() const{
        return svgTag;
    }


    void setSvgTag(string svg){
        this->svgTag = svg;
    }

    void setShapeToDraw(IShape* shape){
        this->shapeToDraw = shape;
    }

    void printListShapes(){
        int i = 1;
        for (IShape *shape: shapes) {
            cout << i << ". " << shape->getName() << endl;
            i++;
        }
    }


    void createShape() const {
        cout << "You want to draw a " << shapeToDraw->getName() << endl;
        shapeToDraw->askShapeDim();
    }

    void addColorShape() const {
        shapeToDraw->askShapeColor();
    }


    void createSvgTag(){
       stringstream content;
       content << svgTemplate.getSvgOpeningTag() << "\n" << shapeToDraw->getShapeTag() << "\n" << svgTemplate.getSvgClosingTag();
       cout << content.str() << endl;
       setSvgTag(content.str());
    }

    void createSvgFile(){
        svgTemplate.exportToSvgFile(shapeToDraw->getName(), svgTag);
    }


    void askShapeToDraw() {
        int shapeChoice;
        cout << this->sizeListShape();
        cout << "Please, select the shape you want to draw: " << endl;
        printListShapes();
        cin >> shapeChoice;
        this->setShapeToDraw(shapes[shapeChoice-1]);
    }

    void mainProgr(){
        askShapeToDraw();
        createShape();
        addColorShape();
        createSvgTag();
        createSvgFile();
    }
};


#endif //CPLUSPLUS_MYCLI_H
