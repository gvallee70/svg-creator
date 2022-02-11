#include <iostream>
#include "SvgTemplate.h"
#include "Shape/Rectangle.h"

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
    Rectangle r;
    r.width = 31;
    r.height = 899;

    svgTemplate.askSizeOfSVG();

    cout <<  svgTemplate.getSvgOpeningTag() << endl;
    cout << r.getShapeTag() << endl;
    cout << svgTemplate.getSvgClosingTag() << endl;

    return 0;
}
