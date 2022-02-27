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
#include <vector>

using namespace std;

class MyCLI {

private:
    IShape* shapeToDraw;
    SvgTemplate svgTemplate;
    MyLibrary lib;

    void setShapeToDraw(IShape* shape){
        this->shapeToDraw = shape;
    }

    void createShape() const {
        cout << "You want to draw a " << this->getShapeToDraw()->getName() << endl;
        this->getShapeToDraw()->askShapeDim();
    }

    void addShapeColor() const {
        this->getShapeToDraw()->askShapeColor();
    }

    void createSvgTag(){
        vector<string> v;
        v.push_back(this->getShapeToDraw()->getShapeTag());
        this->svgTemplate.setSVGTag();
        this->svgTemplate.setShapeTag(v);
        this->svgTemplate.setSVGTag();
    }

    void createSvgDraw(){
        this->askNameOfTheDraw();
        this->lib.addDraw(this->svgTemplate);
    }

    void askNameOfTheDraw() {
        string filename;
        cout << "Name of the draw: ";
        cin >> filename;
        while(lib.filenameExists(filename)){
            cout << "This name already exists. Please enter another one." << endl;
            cout << "Name of the draw : ";
            cin >> filename;
        }
        this->svgTemplate.setDrawName(filename);
    }


    void askShapeToDraw() {
        int shapeChoice;
        cout << "Please, select the shape you want to draw: " << endl;
        this->printShapesList();
        cin >> shapeChoice;

        while(shapeChoice < 1 || shapeChoice > this->getShapesList().size()) {
            cout << "Please, select an existing choice: " << endl;
            this->printShapesList();
            cin >> shapeChoice;

            this->clearAndIgnoreCIN();
        }
        this->setShapeToDraw(this->getShapesList()[shapeChoice-1]);
    }

    void choiceDrawShape(){
        this->askShapeToDraw();
        this->createShape();
        this->addShapeColor();
        this->createSvgTag();
        this->createSvgDraw();
    }

    void choiceMerge(){
        int id1 = 0, id2 = 0;

        cout << "Please, select two drawings you want to merge: " << endl;
        cout << this->lib.getMyDrawingsName() << endl;

        while(id1 < 1 || id1 > this->lib.getMyDrawings().size()) {
            cout << "Choice 1 : ";
            cin >> id1;
            cout << endl;
            this->clearAndIgnoreCIN();
        }
        while(id2 < 1 || id2 > this->lib.getMyDrawings().size()) {
            cout << "Choice 2 : ";
            cin >> id2;
            cout << endl;
            this->clearAndIgnoreCIN();
        }

        this->CLIMergeTwoDraw(id1, id2);
    }

    void CLIMergeTwoDraw(int id1, int id2){
        string shapeTag1 = lib.getShapeTag2(id1);
        string shapeTag2 = lib.getShapeTag2(id2);
        this->svgTemplate.mergeTwoDraw(shapeTag1, shapeTag2);
        createSvgDraw();
    }

    void choiceSeeMyLibrary(){
        if (lib.getMyDrawings().empty()) {
            cout << "Your library is empty." << endl;
        } else {
            cout << "------- Content of your library: -------- " << endl;
            cout << lib.getMyDrawingsSVGTag() << endl;
        }
    }

    void choiceExportAsSVG() {
        int choice = 0;
        if (lib.getMyDrawings().empty()) {
            cout << "Your library is empty." << endl;
        } else {
            while(choice < 1 || choice > this->lib.getMyDrawings().size()) {
                cout << "Please, select the draw that you want to export as SVG file: " << endl;
                cout << lib.getMyDrawingsName() << endl;
                cout << "Choice: ";
                cin >> choice;

                this->clearAndIgnoreCIN();
            }
            this->svgTemplate.exportToSvgFile(lib.getSvgTemplate(choice));
        }
    }

    void choiceDeleteElement(){
        int id = 0, choiceElementDelete = 0;

        if (lib.getMyDrawings().empty()) {
            cout << "Your library is empty." << endl;
        } else {
            while(id < 1 || id > this->lib.getMyDrawings().size()) {
                cout << "Please, select the draw on which you want to delete an element: " << endl;
                cout << lib.getMyDrawingsName() << endl;
                cout << "Choice: ";
                cin >> id;

                this->clearAndIgnoreCIN();
            }

            SvgTemplate svg = this->lib.getSvgTemplate(id);

            while(choiceElementDelete < 1 || choiceElementDelete > svg.getShapesTag().size()) {
                cout << "Choose a tag to delete: " << "\n";
                cout << svg.getShapeTagToStringWithId();
                cin >> choiceElementDelete;

                this->clearAndIgnoreCIN();
            }

            svg.removeShapeTag(choiceElementDelete);
            lib.replaceSvgTemplate(id, svg);
        }
    }

    void choiceQuitProgram(){
        cout << "Bye bye" << endl;
    }

public:
    static vector<IShape *> getShapesList() {
        return vector<IShape *>{
                new Rectangle(),
                new Circle(),
                new Segment(),
                new Polygon()
        };
    };

    void clearAndIgnoreCIN() {
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
        }
    }

    IShape* getShapeToDraw() const{
        return this->shapeToDraw;
    }


    void printShapesList(){
        int i = 1;
        for (IShape *shape: this->getShapesList()) {
            cout << i << ". " << shape->getName() << endl;
            i++;
        }
    }


     int initProgram(){
        int initChoice;

        cout << "Hello, please select your choice:" << endl;
        cout << "1/ Draw new shape" << endl;
        cout << "2/ Merge two drawings" << endl;
        cout << "3/ Consult your library" << endl;
        cout << "4/ Export as SVG file" << endl;
        cout << "5/ Delete element" << endl;
        cout << "6/ Quit " << endl;
        cin >> initChoice;
        return initChoice;
    }

    void mainProgram(){
        int choice = 0;

        while(choice != 6) {
            choice = this->initProgram();

           this->clearAndIgnoreCIN();

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
                    choiceExportAsSVG();
                    break;
                case 5:
                    choiceDeleteElement();
                    break;
                case 6:
                    choiceQuitProgram();
                    break;
                default:
                    break;
            }
        }
    }
};

#endif //CPLUSPLUS_MYCLI_H