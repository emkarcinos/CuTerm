#include "TextWindow.h"
#include "TextObject.h"
#include "string.h"

TextWindow::TextWindow(TextObject& textObj, const char& frameChar, const char* winName){
    setDimmensions(textObj.size.x+4, textObj.size.y+4);
    initMatrix();
    setFrame(frameChar);
    setTitle(winName);
    addTextObject(textObj);
}

TextWindow::TextWindow(){
    setDimmensions(5,5);
    initMatrix();
}

void TextWindow::addTextObject(TextObject& textObj){
    if(textObj.size.x > winDimm.sizeX-2 && textObj.size.y > winDimm.sizeY-2) 
    // if the window's dimmensions are not big enoguh, the function will return.
        return;
    textObj.parent=this;
    unsigned int startX = winDimm.sizeX/2 - textObj.size.x/2;
    unsigned int startY = winDimm.sizeY/2 - textObj.size.y/2;
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

void TextWindow::clear(){
    for(unsigned int row=0; row<winDimm.sizeY; row++){
        for(unsigned int col=0; col<winDimm.sizeX; col++)
            drawingMarix[row][col]=32; //fills with spacebarss
    }
}

void TextWindow::removeTextObject(TextObject& textObj){
    unsigned int startY=winDimm.sizeY/2 - textObj.size.x/2;
    unsigned int startX=winDimm.sizeX/2 - textObj.size.y/2;
    for(unsigned int row=0; row<textObj.size.y; row++){
        for(unsigned int col=0; col<textObj.size.x; col++){
            drawingMarix[row+startY][col+startX]=' ';
        }
    }
    textObj.parent=nullptr;
}

TextWindow::~TextWindow(){;
}