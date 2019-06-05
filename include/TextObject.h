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
        std::string text;
        /* Parsed text */
        std::string textArray[MAX_STR_LINES];
        /* Splits the string into multiple lines */
        void splitStringToLines(const std::string text);

        /* Formatting functions */
        /* Aligns one line to the center of the textbox */
        std::string alignLineCenter(const std::string text);
        /* Aligns one line to the left side of the textbox */
        std::string alignLineLeft(const std::string text);
        /* Aligns one line to the right side of the texbox */
        std::string alignLineRight(const std::string text);

    public:
        /* Returns a textbox with default dimmensions x=20, y=5 */
        TextObject();
        /* Returns a textbox with given dimmensions and a text to format */
        TextObject(const unsigned int x, const unsigned int y, const std::string text);
        /* Parses a string to a 2D string array, centered or aligned to the left and with a given spacing */
        void format(const std::string text, const std::string method, const unsigned int spacing=0);
};