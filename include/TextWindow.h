#pragma once

#include "InnerWindow.h"
#include <string>

class TextWindow : public InnerWindow {
    private:
        /* Creates the matrix */
        virtual void makeDrawingMatrix() override;
        /* Sets window dimmension based of the text object */
        //void setDimmensions(TEXTOBJ);
    public:
        TextWindow();
        TextWindow(const char &frameChar, const char* winName, const char* text);
        ~TextWindow();
        /* Adds a text to the window */
        virtual void addText(const char* text) override;
        /* Adds a text object to the window */
        //void addText(TEXTOBJ)
        /* Clears the window's content */
        virtual void clear() override;
};