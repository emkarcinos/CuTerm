#pragma once

#include "InnerWindow.h"

#include <string>

class TextObject;

class PasswordPrompt : public InnerWindow {
    private:
        /* Obfuscated */
        PasswordPrompt();
        /* Adds "Password:"" to the window */
        void addPassText();
        /* Moves the cursor to the typing position */
        void moveCursor();
        /* Draws a line that separates the text from the prompt */
        void drawPromptBox();
        /* Obfuscated */
        virtual void addTextObject(TextObject& obj) override;
        /* Obfuscated */
        virtual void removeTextObject(TextObject& textObj) override;
    public:
        /* Returns a PasswordPrompt */
        PasswordPrompt(const char& frameChar=' ', const char* winTitle="");
        /* Input/output mechanism */
        void prompt(std::string output);
        /* Clears the matrix */
        virtual void clear() override;
        virtual ~PasswordPrompt();
};