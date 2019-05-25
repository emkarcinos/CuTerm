#pragma once

#define DRAW_X_LIMIT 4096
#define DRAW_Y_LIMIT 2056

class TerminalWindow {
    private:
        struct winsize { //holds info about terminal size
            unsigned short int ws_row;
            unsigned short int ws_col;
        } size;
        char drawingMarix[DRAW_Y_LIMIT][DRAW_X_LIMIT]; //matrix representation of the screen
        /* gets info about terminal dimmensions */
        void updateTerminalSize();
        /* populates drawingMatrix with spacebars */
        void initMatrix();
        /* sets custom border */
        void setFrame(const char &frameChar);
        /* adds text to the top of the window */
        void addTitle(const char *winTitle); 
    public:
        /* initializes empty window */
        TerminalWindow();
        /* initializes window with a border */
        TerminalWindow(const char &frameChar);
        /* initalizes window with a border and a title */
        TerminalWindow(const char &frameChar, const char* winTitle);
        /* flushes the screen */
        ~TerminalWindow();
        /* draws everything from the drawing matrix, "refreshes" the whole terminal window */
        void draw() const;
        /* adds smaller windows to the screnn */
        void append();
        /* basically a clear system funcion */
        void clear() const;

        /* DEBUG FUNCTIONS */

        /* you can manipulate drawingMatrix using this */
        void alterMatrix();
};