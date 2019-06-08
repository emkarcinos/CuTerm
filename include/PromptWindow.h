#pragma once

#include "InnerWindow.h"

class TextObject;
class TerminalWindow;

template<class type>
class PromptWindow : public InnerWindow {
    private:
        /* Obfuscated */
        PromptWindow();
        /* Moves the cursor to the typing position */
        void moveCursor();
        /* Draws a line that separates the text from the prompt */
        void drawSeparator();
    public:
        /* Adds a text object to the window */
        virtual void addTextObject(TextObject& textObj) override;
         /* Removes the text object from the window */
        virtual void removeTextObject(TextObject& textObj) override;
        virtual ~PromptWindow();
};