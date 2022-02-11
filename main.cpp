#include <iostream>
#include "SvgTemplate.h"
#include "Shape/Rectangle.h"
#include <sstream>

using namespace std;

SvgTemplate svgTemplate;


string shapesNames [4] = { "Rectangle", "Circle", "Segment", "Polygon" };

void askShapeToDraw() {
    cout << "Please, select the shape you want to draw: " << endl;

    int i = 1;
    int shapeChoice;

    for(string shapeName : shapesNames) {
        cout << i << ". " << shapeName << endl;
        i++;
    }

    cin >> shapeChoice;

    cout << "You want to draw a " << shapesNames[shapeChoice-1] << endl;
}


int main() {

    SvgTemplate svgTemplate;
    Rectangle rectangle;
    rectangle.width = 200;
    rectangle.height = 100;

    stringstream content;
    content << svgTemplate.getSvgOpeningTag() << "\n" << rectangle.getShapeTag() << "\n" << svgTemplate.getSvgClosingTag();

    cout << content.str() << endl;

    svgTemplate.exportToSvgFile("rectangleShape", content.str());

    return 0;
}
