#ifndef CPLUSPLUS_MYCLI_H
#define CPLUSPLUS_MYCLI_H
#include <iostream>
#include "SvgTemplate.h"
#include "Shape/Rectangle.h"
#include "Shape/Circle.h"
#include "Shape/Segment.h"
#include "Shape/Polygon.h"
#include "MyLibrary.h"
#include <sstream>
#include <iostream>
#include <fstream>
using namespace std;

class MyCLI {
public:
    IShape* shapeToDraw;
    IShape *shapes[4] = {new Rectangle(), new Circle(), new Segment(), new Polygon()};
    SvgTemplate svgTemplate;
    MyLibrary lib;

    IShape* getListShapes(){
        return *shapes;
    }

    int sizeListShape(){
        return sizeof(*shapes);
    }

    IShape* getShapeToDraw() const{
        return shapeToDraw;
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
        svgTemplate.setShapeTag(shapeToDraw->getShapeTag());
        svgTemplate.setSVGTag(content.str());
    }

    void createSvgFile(SvgTemplate svg){
        string filename;
        cout << "Name of draw : ";
        cin >> filename;
        while(lib.nameFileExist(filename)){
            cout << "Name draw existing" << endl;
            cout << "Name of draw : ";
            cin >> filename;
        }
        svg.setDrawName(filename);
        svg.exportToSvgFile();
        lib.addDraw(svg);
    }

    void askShapeToDraw() {
        int shapeChoice;
        cout << "Please, select the shape you want to draw: " << endl;
        printListShapes();
        cin >> shapeChoice;
        this->setShapeToDraw(shapes[shapeChoice-1]);
    }

    void choiceDrawShape(){
        askShapeToDraw();
        createShape();
        addColorShape();
        createSvgTag();
        createSvgFile(this->svgTemplate);
    }

    void choiceMerge(){
        int id1, id2;
        cout << "Please, select two drawings you want to merge: " << endl;
        cout << lib.getMyDrawingsName() << endl;
        cout << "Choice 1 : ";
        cin >> id1;
        cout << "Choice 2 : ";
        cin >> id2;
        CLIMergeTwoDraw(id1, id2);
    }

    void CLIMergeTwoDraw(int id1, int id2){
        string shapeTag1 = lib.getShapeTag2(id1);
        string shapeTag2 = lib.getShapeTag2(id2);
        SvgTemplate newSVG;
        newSVG.mergeTwoDraw(shapeTag1, shapeTag2);
        createSvgFile(newSVG);
    }

    void choiceSeeMyLibrary(){
        cout << "------- Content of your library: -------- " << endl;
        cout << lib.getMyDrawingsSVGTag() << endl;
    }

    void choiceDeleteElement(){
        cout << "Please, select the draw you want to delete element: " << endl;
        cout << lib.getMyDrawingsName() << endl;
    }

    void choiceQuitProg(){
        cout << "Bye bye" << endl;
    }

    int initProgr(){
        int initChoice;
        cout << "Hello, please select your choice:" << endl;
        cout << "1/ Draw new shape" << endl;
        cout << "2/ Merge two drawings" << endl;
        cout << "3/ Consult your library" << endl;
        cout << "4/ Delete element" << endl;
        cout << "5/ Quit " << endl;
        cin >> initChoice;
        return initChoice;
    }

    void mainProgr(){
        int choice = 0;
        while(choice != 5) {
            choice = initProgr();
            switch (choice) {
                case 1:
                    choiceDrawShape();
                    break;
                case 2:
                    choiceMerge();
                    break;
                case 3:
                    choiceSeeMyLibrary();
                    break;
                case 4:
                    choiceDeleteElement();
                    break;
                case 5:
                    choiceQuitProg();
                    break;
                default:
                    break;
            }
        }
    }
};

#endif //CPLUSPLUS_MYCLI_H