#pragma once

#include <iostream>
#include <string>

#define MAX_STR_LINES 256

class TextObject {
        struct Dimmensions {
            unsigned short x;
            unsigned short y;
        } size;
        /* Raw text */
        std::string textStr=std::string("");
        /* Parsed text */
        std::string textArray[MAX_STR_LINES];
        /* Initializes textArray with spacebars */
        void initTextArray();

    public:
        /* Returns a textbox with default dimmensions x=20, y=5 */
        TextObject();
        /* Returns a textbox with given dimmensions and a text to format */
        TextObject(const unsigned int& x, const unsigned int& y, const std::string& text);
        /* Adds the text string to the object */
        void appendString(const std::string& text);
        /* Parses a string to a 2D string array, centered or aligned to the left and with a given spacing */
        void format(const std::string& text, const std::string& method, const unsigned int& spacing=0);
};