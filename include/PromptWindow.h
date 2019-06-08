#pragma once

#include "InnerWindow.h"

class TextObject;
class TerminalWindow;

template<class type>

class PromptWindow : public InnerWindow {
template<class type>
    private:
        /* Obfuscated */
        PromptWindow();
        /* Adds a text to the window */
        virtual void addText(const char* text) override;
        /* Moves the cursor to the typing position */
        void moveCursor();
    public:
        static type DisplayPrompt(const TextObject& textObj, type& output const char& frameChar=' ', const char* winTitle="");
        virtual ~PromptWindow();
};