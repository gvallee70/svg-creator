//
// Created by David NGUYEN on 11/02/2022.
//

#ifndef CPLUSPLUS_ISHAPE_H
#define CPLUSPLUS_ISHAPE_H

#include <string>

using namespace std;

class IShape {

    public:
        string name;
        string shapeTag;

        string getName();

        string getShapeTag();

};


#endif //CPLUSPLUS_ISHAPE_H
