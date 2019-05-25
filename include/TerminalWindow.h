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
        void updateTerminalSize();
    public:
        TerminalWindow();
        virtual void draw(); //this function draws everything from the drawing matrix, "refreshes" the whole terminal window
        virtual void update();
        virtual void append();
};