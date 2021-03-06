#pragma once

#include "Window.h"

#include <string>

class InnerWindow;

class TerminalWindow : public Window{
    friend class InnerWindow;
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
        /* Adds smaller windows to the center of the screen */
        void append(InnerWindow& win);
        /* Basically a clear system funcion */
        void clear() const;
        /* Removes an inner window from the terminal */
        void removeWindow(InnerWindow& win);
        /* DEBUG FUNCTIONS */

        /* you can manipulate drawingMatrix using this */
        void alterMatrix();
};