#pragma once

class Window {
    private:
        /* sets custom border */
        virtual void setFrame(const char &frameChar)=0;
        /* adds text to the top of the window */
        virtual void setTitle(const char* winTitle)=0;

};