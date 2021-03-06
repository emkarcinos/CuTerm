#pragma once

#include "Window.h"

class TerminalWindow;
class TextObject;

class InnerWindow : public Window {
    friend class TerminalWindow;
    friend class TextObj;
    protected:
        struct Dimmensions {
            unsigned short int posX; //Leftmost point
            unsigned short int posY; //Topmost point
            unsigned short int sizeX;
            unsigned short int sizeY;
        } winDimm;
        /* Stores a character from which the frame is built */
        char frame;
        /* This variable stores "where this object belongs" */
        TerminalWindow* parent=nullptr;
        /* Populates drawingMatrix with spacebars */
        void initMatrix();
        /* Sets window dimmension by values */
        void setDimmensions(const unsigned int _x, const unsigned int _y);
    public:
        InnerWindow();
        ~InnerWindow();
        /* Erases the window's content */
        virtual void clear()=0;
        /* Sets custom window border */
        void setFrame(const char &frameChar);
        /* Adds text to the top of the window */
        void setTitle(const char* winTitle);
        /* Adds a text object to the window */
        virtual void addTextObject(TextObject& textObj)=0;
        /* Sets window position by value */
        void setPos(const unsigned int& _x, const unsigned int& _y);
        /* Removes a TextObject from the window */
        virtual void removeTextObject(TextObject& textObj)=0;
};
