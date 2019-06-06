#pragma once

#include "InnerWindow.h"
#include "TextObject.h"

#include <string>

class TextWindow : public InnerWindow {
    private:
        /* Sets window dimmension based of the text object */
        void setDimmensionsByObject(const TextObject& textObj);
    public:
        TextWindow();
        TextWindow(const char &frameChar, const char* winName="", const char* text="");
        virtual ~TextWindow();
        /* Adds a text to the window */
        virtual void addText(const char* text) override;
        /* Adds a text object to the window */
        void addTextObject(const TextObject& textObj);
        /* Clears the window's content */
        virtual void clear() override;
};