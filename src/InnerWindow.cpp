#include "InnerWindow.h"
#include "TextObject.h"
#include "TerminalWindow.h"

#include <string.h>

void InnerWindow::initMatrix(){
    for(unsigned int row=0; row<winDimm.sizeY; row++){
        for(unsigned int col=0; col<winDimm.sizeX; col++){
            drawingMarix[row][col]=32;
        }
    }
}

void InnerWindow::setFrame(const char &frameChar){
    for(int row=0; row<winDimm.sizeY; row++){
        for(int col=0; col<winDimm.sizeX; col++){
            if(row==0 || row==winDimm.sizeY-1 || col==0 || col==winDimm.sizeX-1)
                drawingMarix[row][col]=frameChar;
        }
    }
}

void InnerWindow::setTitle(const char *winTitle){
    unsigned short int titleLength=strlen(winTitle);
    unsigned short int writePos=winDimm.sizeX/2 - titleLength/2;
    for(unsigned int i=0; i<titleLength; i++)
        drawingMarix[0][writePos+i]=winTitle[i];
}

void InnerWindow::setDimmensions(const unsigned int _x, const unsigned int _y){
    winDimm.sizeX=_x;
    winDimm.sizeY=_y;
}

void InnerWindow::setPos(){
    winDimm.align="center";
}

void InnerWindow::setPos(const unsigned int _x, const unsigned int _y){
    winDimm.posX=_x;
    winDimm.posY=_y;
}

InnerWindow::InnerWindow(){ }

void InnerWindow::addTextObject(TextObject& textObj){
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

void InnerWindow::removeTextObject(TextObject& textObj){
    unsigned int startY=winDimm.sizeY/2 - textObj.size.x/2;
    unsigned int startX=winDimm.sizeX/2 - textObj.size.y/2;
    for(unsigned int row=0; row<textObj.size.y; row++){
        for(unsigned int col=0; col<textObj.size.x; col++){
            drawingMarix[row+startY][col+startX]=' ';
        }
    }
    textObj.parent=nullptr;
}

InnerWindow::~InnerWindow(){
    parent->removeWindow(*this);
 }
