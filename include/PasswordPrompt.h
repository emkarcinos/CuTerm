#pragma once

#include "InnerWindow.h"

#include <string>

class PasswordPrompt : public InnerWindow {
    private:
        /* Obfuscated */
        PasswordPrompt();
        /* Adds "Password:"" to the window */
        void addPassText();
        /* Moves the cursor to the typing position */
        void moveCursor();
        /* Draws a line that separates the text from the prompt */
        void drawSeparator();
    public:
        /* Returns a PasswordPrompt */
        PasswordPrompt(const char& frameChar=' ', const char* winTitle="");
        /* Input/output mechanism */
        void prompt(std::string output);
        virtual ~PasswordPrompt();
};