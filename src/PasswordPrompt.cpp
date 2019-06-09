#include "PasswordPrompt.h"
#include "TerminalWindow.h"
#include <string.h>
#include <iostream>

void PasswordPrompt::addPassText(){
    const char* text = "Enter Password:";
    unsigned int startPos=winDimm.sizeX/2 - strlen(text)/2;
    for(unsigned int pos=0; pos<strlen(text); pos++)
        drawingMarix[1][startPos+pos]=text[pos];
}

void PasswordPrompt::moveCursor(){
    unsigned int destinationX = parent->termDimm.ws_col/2 - winDimm.sizeX/2 + 4;
    unsigned int destinationY = (parent->termDimm.ws_row/2 - winDimm.sizeY/2) + winDimm.sizeY - 3;
    // Move the cursor down
    for(unsigned int row=0; row<destinationY; row++)
        std::cout << "\033[1B";
    // Move the cursor forward
    for(unsigned int col=0; col<destinationX; col++)
        std::cout << "\033[1C";
}

void PasswordPrompt::drawPromptBox(){
    unsigned int startX=3;
    unsigned int startY=winDimm.sizeY-4;
    for(unsigned int row=0; row<3; row++){
        for(unsigned int col=0; col<winDimm.sizeX-5; col++)
            if(row!=1)
                drawingMarix[row+startY][col+startX]=frame;
    }
}

PasswordPrompt::PasswordPrompt(const char& frameChar, const char* winTitle){
    setDimmensions(51, 6);
    initMatrix();
    setFrame(frameChar);
    setTitle(winTitle);
    addPassText();
    drawPromptBox();
}

void PasswordPrompt::clear(){

}

void PasswordPrompt::prompt(std::string output){
    moveCursor();
    std::cout << "> ";
    std::cin >> output;
}

PasswordPrompt::~PasswordPrompt(){
    
}

void PasswordPrompt::addTextObject(TextObject& obj){ }
void PasswordPrompt::removeTextObject(TextObject& obj){ }
