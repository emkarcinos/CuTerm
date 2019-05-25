#pragma once

class Window {
    private:
        virtual void setFrame(const char &frameChar)=0;
        virtual void setTitle(const char* winTitle)=0;
        
};