#pragma once

#include "InnerWindow.h"

#include <string>

class TextObject;

class TextWindow : public InnerWindow {
    private:
        /* Sets window dimmension based of the text object */
        void setDimmensionsByObject(const TextObject& textObj);
    public:
        TextWindow();
        /* This constructor sets the size automatically based on the TextObject dimmensions */
        TextWindow(TextObject& textObj, const char& frameChar='*', const char* winName="");
        /* Obfuscated constructor */
        TextWindow(const char &frameChar, const char* winName="", const char* text="");
        virtual ~TextWindow();
        /* Adds a text to the window */
        virtual void addText(const char* text) override;
        /* Clears the window's content */
        virtual void clear() override;
};