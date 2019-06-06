#include "TextWindow.h"
#include "string.h"

void TextWindow::addText(const char* text){
    unsigned int textSize=strlen(text);
    unsigned int startPos = winDimm.sizeX/2 - textSize/2;
    for(unsigned int pos=0; pos<textSize; pos++){
        if(pos+2==(unsigned)winDimm.sizeX-2)
            return;
        drawingMarix[3][pos+startPos]=text[pos];
    }
}

void TextWindow::addTextObject(const TextObject& textObj){
    if(textObj.size.x > winDimm.sizeX-2 && textObj.size.y > winDimm.sizeY-2) 
    // if the window's dimmensions are not big enoguh, the function will return.
        return;
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

TextWindow::TextWindow(){
    setDimmensions(5,5);
    initMatrix();
}

TextWindow::TextWindow(const char &frameChar, const char* winName, const char* text){
    setDimmensions(70,13);
    initMatrix();
    setFrame(frameChar);
    setTitle(winName);
    addText(text);
}

void TextWindow::clear(){
    for(unsigned int row=0; row<winDimm.sizeY; row++){
        for(unsigned int col=0; col<winDimm.sizeX; col++)
            drawingMarix[row][col]=32; //fills with spacebarss
    }
}

TextWindow::~TextWindow(){
    clear();
}