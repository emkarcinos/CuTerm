#pragma once

#define DRAW_X_LIMIT 4096
#define DRAW_Y_LIMIT 2056

class TerminalWindow {
    private:
        struct winsize {
            unsigned short int ws_row, ws_col;
        } size;
        char drawingMarix[DRAW_Y_LIMIT][DRAW_X_LIMIT];
        void updateTerminalSize();
    public:
        TerminalWindow();
        void draw();
        void update();
        void append();
};