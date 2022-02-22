#include <iostream>
#include "SvgTemplate.h"
#include "Shape/Rectangle.h"
#include "Shape/Circle.h"
#include "Shape/Segment.h"
#include <sstream>

using namespace std;

SvgTemplate svgTemplate;

//string shapesNames [4] = { "Rectangle", "Circle", "Segment", "Polygon" };
//IShape *shapes [1] = {  new Rectangle()};

void askShapeToDraw() {

    IShape *shapes[3] = {new Rectangle(), new Circle(), new Segment()};

    cout << "Please, select the shape you want to draw: " << endl;

    int i = 1;
    int shapeChoice;

    for(IShape *shape : shapes) {
        cout << i << ". " << shape->getName() << endl;
        i++;
    }

    cin >> shapeChoice;

    IShape *myShape = shapes[shapeChoice-1];
    cout << "You want to draw a " << myShape->getName() << endl;
    myShape->askShapeDim();

    stringstream content;
    content << svgTemplate.getSvgOpeningTag() << "\n" << myShape->getShapeTag() << "\n" << svgTemplate.getSvgClosingTag();

    cout << content.str() << endl;

    svgTemplate.exportToSvgFile(myShape->getName(), content.str());

}


int main() {

    askShapeToDraw();
    /*SvgTemplate svgTemplate;
    Rectangle rectangle;
    rectangle.width = 200;
    rectangle.height = 100;

    stringstream content;
    content << svgTemplate.getSvgOpeningTag() << "\n" << rectangle.getShapeTag() << "\n" << svgTemplate.getSvgClosingTag();

    cout << content.str() << endl;

    svgTemplate.exportToSvgFile("rectangleShape", content.str());*/

    return 0;
}
