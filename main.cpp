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

void askSizeOfSVG() {
    int width, height;

    cout << "Please enter a width:" << endl;
    cin >> width;
    svgTemplate.setWidth(width);

    cout << "Please enter an height:" << endl;
    cin >> height;
    svgTemplate.setHeight(height);

    cout << "You chose:" << endl;
    cout << "Width: " << svgTemplate.getWidth() << endl;
    cout << "Height: " << svgTemplate.getHeight() << endl;

}

int main() {

    Rectangle r;
    r.width = 100;
    r.height = 100;
    cout << r.getName() << endl;
    cout << r.getShapeTag() << endl;
    askShapeToDraw();
    askSizeOfSVG();
    return 0;
}
