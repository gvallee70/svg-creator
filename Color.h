//
// Created by Gwendal on 22/02/2022.
//

#ifndef CPLUSPLUS_COLOR_H
#define CPLUSPLUS_COLOR_H

#include <string>
#include <vector>

using namespace std;

class Color {

    private:
        string name;
        string tag;

    public:
        Color(string name, string tag) {
            this->name = name;
            this->tag = tag;
        }

        string getColorName() const { return this->name; }
        string getColorTag() const { return this->tag; }
        static vector<Color *> getColors() {
            return std::vector<Color *>{
                    new Color("Red", "red"),
                    new Color("Blue", "blue"),
                    new Color("Black", "black"),
                    new Color("Green", "green")
            };
        };
};
#endif //CPLUSPLUS_COLOR_H
