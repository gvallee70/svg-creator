//
// Created by David NGUYEN on 11/02/2022.
//

#ifndef CPLUSPLUS_ISHAPE_H
#define CPLUSPLUS_ISHAPE_H

#include <string>

using namespace std;

class IShape {

    public:
        /*string name;
        string tagName;
        string shapeTag;

        string getName();
        string getTagName();
        string getShapeTag();

        virtual void askShapeDim() = 0;*/

        string shapeTag;

        virtual string getShapeTag() = 0;
        virtual void askShapeDim() = 0;
        virtual string getName() = 0;

};


#endif //CPLUSPLUS_ISHAPE_H
