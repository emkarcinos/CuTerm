#pragma once

#include "InnerWindow.h"

class TextObject;

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
        /* Creates a PromptWindow object, user input will be written to output variable (second arg) NOTE: can be either string, int or double*/
        PromptWindow(TextObject& textObj, const char& frameChar=' ', const char* winTitle="");
        /* Adds a text object to the window */
        virtual void addTextObject(TextObject& textObj) override;
        /* Removes the text object from the window */
        virtual void removeTextObject(TextObject& textObj) override;
        /* Clears the window */
        /* Input/output mechanism */
        void prompt(type& input);
        virtual void clear() override;
        virtual ~PromptWindow();
};