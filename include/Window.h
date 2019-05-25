#pragma once

#define DRAW_X_LIMIT 4096
#define DRAW_Y_LIMIT 2056

class Window {
    protected:
        /* Matrix representation of the window's content */
        char drawingMarix[DRAW_Y_LIMIT][DRAW_X_LIMIT];
    private:
        /* Sets custom window border */
        virtual void setFrame(const char &frameChar)=0;
        /* Adds text to the top of the window */
        virtual void setTitle(const char* winTitle)=0;
        /* Populates drawingMatrix with spacebars */
        virtual void initMatrix()=0;

};