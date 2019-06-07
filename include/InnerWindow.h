#pragma once

#include "Window.h"
#include "TerminalWindow.h"

class InnerWindow : public Window {
    friend class TerminalWindow;
    protected:
        struct Dimmensions {
            unsigned short int posX;
            unsigned short int posY;
            unsigned short int sizeX;
            unsigned short int sizeY;
            char* align;
        } winDimm;
        /* This variable stores "where this object belongs" */
        TerminalWindow* parent;
        /* Populates drawingMatrix with spacebars */
        void initMatrix();
        /* Sets window dimmension by values */
        void setDimmensions(const unsigned int _x, const unsigned int _y);
        /* Sets window position to center*/
        void setPos();
        /* Sets window position by value */
        void setPos(const unsigned int _x, const unsigned int _y);
    public:
        InnerWindow();
        ~InnerWindow();
        /* Adds a text object to the window */
        virtual void addText(const char* text)=0;
        /* Clears the window's content */
        virtual void clear()=0;
        /* Sets custom window border */
        void setFrame(const char &frameChar);
        /* Adds text to the top of the window */
        void setTitle(const char* winTitle);
};
