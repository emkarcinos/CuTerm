#include "TextWindow.h"
#include "TextObject.h"
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

TextWindow::~TextWindow(){;
}