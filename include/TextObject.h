#pragma once

#include <iostream>
#include <string>

#define MAX_STR_LINES 256

class TextObject {
    private:
        struct Dimmensions {
            unsigned short x;
            unsigned short y;
        } size;
        std::string text;
        std::string textArray[MAX_STR_LINES];
    public:
        /* Returns a textbox with default dimmensions x=20, y=5 */
        TextObject();
        /* Returns a textbox with given dimmensions and optionally a text to format */
        TextObject(const unsigned int x, const unsigned int y, std::string _text=NULL);
};