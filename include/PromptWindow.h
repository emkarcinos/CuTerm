#pragma once

#include "InnerWindow.h"

class TextObject;
class TerminalWindow;

template<class type>
class PromptWindow : public InnerWindow {
    private:
        /* Obfuscated */
        PromptWindow();
        /* Adds a text to the window */
        virtual void addText(const char* text) override;
        /* Moves the cursor to the typing position */
        void moveCursor();
        /* Calls all necesary functons to create the drawingMatrix */
        void drawPromptWindow(const TextObject& textObj, type& output, const char& frameChar=' ', const char* winTitle="");
    public:
        /* Displays a prompt on the TerminalWindow and forwards user input to output (second arg) */
        static type prompt(TerminalWindow& termial, const TextObject& textObj, type& output, const char& frameChar=' ', const char* winTitle="");
        /* Adds a text object to the window */
        virtual void addTextObject(TextObject& textObj) override;
        virtual ~PromptWindow();
};