#pragma once

#include "Window.h"

class TerminalWindow : public Window{
    private:
        /* Holds info about terminal dimmensions */
        struct winsize {
            unsigned short int ws_row;
            unsigned short int ws_col;
        } termDimm;
        /* Gets info about terminal dimmensions */
        void updateTerminalSize();
        /* Populates drawingMatrix with spacebars */
        void initMatrix();
        /* Sets custom border */
        void setFrame(const char &frameChar);
        /* Adds text to the top of the window */
        void setTitle(const char *winTitle); 
    public:
        /* Initializes empty window */
        TerminalWindow();
        /* Initalizes window with a border and a title */
        TerminalWindow(const char &frameChar=32, const char* winTitle=nullptr);
        /* Flushes the screen */
        virtual ~TerminalWindow();
        /* Draws everything from the drawing matrix, "refreshes" the whole terminal window */
        void draw() const;
        /* Adds smaller windows to the screnn */
        void append();
        /* Basically a clear system funcion */
        void clear() const;

        /* DEBUG FUNCTIONS */

        /* you can manipulate drawingMatrix using this */
        void alterMatrix();
};