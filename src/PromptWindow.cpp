#include "PromptWindow.h"
#include "TextObject.h"
#include "TerminalWindow.h"

#include <string>
#include <iostream>

template<class type>
void PromptWindow<type>::addTextObject(TextObject& textObj){
    if(textObj.size.x > winDimm.sizeX-2 && textObj.size.y > winDimm.sizeY-3) 
    // if the window's dimmensions are not big enoguh, the function will return.
        return;
    textObj.parent=this;
    const unsigned int startX = winDimm.sizeX/2 - textObj.size.x/2;
    const unsigned int startY = (winDimm.sizeY/2 - textObj.size.y/2)-1;
    unsigned int lineCount=0;
    unsigned int ptr=0;
    for(const char& ch : textObj.finalStr){
        if(ch=='\n'){lineCount++; ptr=0;}
        else {
            drawingMarix[startY+lineCount][startX+ptr]=ch;
            ptr++;
        }
    }
}

template<class type>
void PromptWindow<type>::drawSeparator(){
    for(unsigned int pos=1; pos<winDimm.sizeX-1; pos++)
        drawingMarix[winDimm.sizeY-3][pos]=frame;
}

template<class type>
void PromptWindow<type>::moveCursor(){
    const unsigned int destinationX = winDimm.posX+2;
    const unsigned int destinationY = winDimm.posY + winDimm.sizeY - 2;
    // Move the cursor down
    for(unsigned int row=0; row<destinationY; row++)
        std::cout << "\033[1B";
    // Move the cursor forward
    for(unsigned int col=0; col<destinationX; col++)
        std::cout << "\033[1C";
}

template<class type>
void PromptWindow<type>::prompt(type& input){
    moveCursor();
    std::cout << "> ";
    system("setterm -cursor on");
    std::cin >> input;
    std::cout << "\033[2J\033[1;1H"; // Moves the cursor back to the beginning of the window
    system("setterm -cursor off");
}

template<class type>
PromptWindow<type>::PromptWindow(TextObject& textObj, const char& frameChar, const char* winTitle){
    setDimmensions(textObj.size.x+4, textObj.size.y+6);
    initMatrix();
    setFrame(frameChar);
    setTitle(winTitle);
    addTextObject(textObj);
    drawSeparator();
}

template<class type>
void PromptWindow<type>::removeTextObject(TextObject& textObj){
    const unsigned int startY=winDimm.sizeY/2 - textObj.size.y/2;
    const unsigned int startX=(winDimm.sizeX/2 - textObj.size.x/2)-1;
    for(unsigned int row=0; row<textObj.size.y; row++){
        for(unsigned int col=0; col<textObj.size.x; col++){
            drawingMarix[row+startY][col+startX]=' ';
        }
    }
    textObj.parent=nullptr;
}
template<class type>
void PromptWindow<type>::clear(){
    for(unsigned int row=0; row<winDimm.sizeY-2; row++){
        for(unsigned int col=0; col<winDimm.sizeX; col++)
            drawingMarix[row][col]=' ';
    }
}

template<class type>
PromptWindow<type>::~PromptWindow(){
}

template class PromptWindow<int>;
template class PromptWindow<std::string>;
template class PromptWindow<double>;