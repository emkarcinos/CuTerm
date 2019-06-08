#pragma once

#include <iostream>
#include <string>

class InnerWindow;
class TextWindow;
template<class type> class PromptWindow;

class TextObject {
    friend class InnerWindow;
    friend class TextWindow;
    friend class PromptWindow<int>;
    friend class PromptWindow<double>;
    friend class PromptWindow<std::string>;
    private:
        struct Dimmensions {
            unsigned short x;
            unsigned short y;
            unsigned short spacing;
        } size;
        InnerWindow* parent=nullptr;
        /* Raw text */
        std::string textStr=std::string("");
        /* Parsed text */
        std::string finalStr=std::string("");

    public:
        /* Returns a textbox with default dimmensions x=20, y=5 */
        TextObject();
        /* Returns a textbox with given dimmensions and a text to format */
        TextObject(const std::string& text, const unsigned int& x, const unsigned int& y, const unsigned int& spacing=0);
        ~TextObject();
        /* Adds the text string to the object */
        void appendString(const std::string& text);
        /* Parses a string to a 2D string array, centered or aligned to the left and with a given spacing */
        void format(const std::string& method="left", const unsigned int& spacing=9999);
        /* Returns a raw string */
        std::string toString();
};