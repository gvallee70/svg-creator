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
        return this->shapeToDraw;
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
        this->getShapeToDraw()->askShapeDim();
    }

    void addShapeColor() const {
        this->getShapeToDraw()->askShapeColor();
    }

    void createSvgTag(){
        stringstream content;
        vector<string> v;
        v.push_back(this->getShapeToDraw()->getShapeTag());
        content << this->svgTemplate.getSvgOpeningTag() << "\n" << this->getShapeToDraw()->getShapeTag() << "\n" << this->svgTemplate.getSvgClosingTag();
        cout << content.str() << endl;
        svgTemplate.setShapeTag(v);
        svgTemplate.setSVGTag();
    }

    void askNameOfTheDraw() {
        string filename;
        cout << "Name of the draw: ";
        cin >> filename;
        while(lib.nameFileExist(filename)){
            cout << "This name already exists. Please enter another one." << endl;
            cout << "Name of the draw : ";
            cin >> filename;
        }
        this->svgTemplate.setDrawName(filename);
    }

    void createSvgFile(){
        askNameOfTheDraw();
        this->svgTemplate.exportToSvgFile();
        this->lib.addDraw(this->svgTemplate);
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
        addShapeColor();
        createSvgTag();
        createSvgFile();
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
        this->svgTemplate.mergeTwoDraw(shapeTag1, shapeTag2);
        createSvgFile();
    }

    void choiceSeeMyLibrary(){
        cout << "------- Content of your library: -------- " << endl;
        cout << lib.getMyDrawingsName() << endl;
        cout << lib.getMyDrawingsSVGTag() << endl;
    }

    void choiceDeleteElement(){
        int id, choiceElementDelete;
        cout << "Please, select the draw on which you want to delete an element: " << endl;
        cout << lib.getMyDrawingsName() << endl;
        cout << "Choice: ";
        cin >> id;
        SvgTemplate svg = lib.getSvgTemplate(id);
        cout << "Choose an element to delete: " << "\n";
        cout << svg.getShapeTagToStringWithId();
        cin >> choiceElementDelete;
        //cout << "Avant : " << svg.getShapeTagToString();
        svg.removeShapeTag(choiceElementDelete);
        //cout << "Après : " << svg.getShapeTagToString();
        lib.replaceSvgTemplate(id, svg);
    }

    void choiceQuitProgram(){
        cout << "Bye bye" << endl;
    }

    int initProgram(){
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

    void mainProgram(){
        int choice = 0;

        while(choice != 5) {
            choice = initProgram();

            if (cin.fail()) {
                cin.clear();
                cin.ignore();
            }

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
                    choiceQuitProgram();
                    break;
                default:
                    break;
            }
        }
    }
};

#endif //CPLUSPLUS_MYCLI_H