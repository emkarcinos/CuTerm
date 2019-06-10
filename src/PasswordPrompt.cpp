#include "PasswordPrompt.h"
#include "TerminalWindow.h"
#include <string.h>
#include <iostream>

void PasswordPrompt::addPassText(){
    const char* text = "Enter Password:";
    const unsigned int startPos=winDimm.sizeX/2 - strlen(text)/2;
    for(unsigned int pos=0; pos<strlen(text); pos++)
        drawingMarix[1][startPos+pos]=text[pos];
}

void PasswordPrompt::moveCursor(){
    const unsigned int destinationX = winDimm.posX + 3;
    const unsigned int destinationY = winDimm.posY + winDimm.sizeY - 3;
    // Move the cursor down
    for(unsigned int row=0; row<destinationY; row++)
        std::cout << "\033[1B";
    // Move the cursor forward
    for(unsigned int col=0; col<destinationX; col++)
        std::cout << "\033[1C";
}

void PasswordPrompt::drawPromptBox(){
    const unsigned int startX=3;
    const unsigned int startY=winDimm.sizeY-4;
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
    system("setterm -cursor on");
    std::cin >> output;
    system("setterm -cursor off");
}

PasswordPrompt::~PasswordPrompt(){
    
}

void PasswordPrompt::addTextObject(TextObject& obj){ }
void PasswordPrompt::removeTextObject(TextObject& obj){ }
