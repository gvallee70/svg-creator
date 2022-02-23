//
// Created by David NGUYEN on 11/02/2022.
//

#ifndef CPLUSPLUS_ISHAPE_H
#define CPLUSPLUS_ISHAPE_H

#include <string>
#include <iostream>
#include "Color.h"

using namespace std;

class IShape {

    protected:
        string name;
        string tagName;

        Color* shapeColor;

    private:
        void setShapeColor(Color *pColor) { this->shapeColor = pColor; };

    public:
        virtual string getName() = 0;
        virtual string getShapeTag() = 0;
        virtual void askShapeDim() = 0;

        Color* getShapeColor() const {  return this->shapeColor; };
        void askShapeColor() {
            cout << "What color?" << endl;

            int i = 1;
            int colorChoice;
            vector<Color*> colors = Color::getColors();

            for(Color *color : colors) {
                cout << i << ". " << color->getColorName() << endl;
                i++;
            }
            cin >> colorChoice;

            this->setShapeColor(colors[colorChoice - 1]);
        }
};


#endif //CPLUSPLUS_ISHAPE_H
