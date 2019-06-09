#pragma once

#include "InnerWindow.h"

#include <string>

class TextObject;

class TextWindow : public InnerWindow {
    public:
        TextWindow();
        /* This constructor sets the size automatically based on the TextObject dimmensions */
        TextWindow(TextObject& textObj, const char& frameChar='*', const char* winName="");
        virtual ~TextWindow();
        /* Clears the window's content */
        virtual void clear() override;
        /* Adds a text object to the window */
        virtual void addTextObject(TextObject& textObj) override;
        /* Removes the text object from the window */
        virtual void removeTextObject(TextObject& textObj) override;
};