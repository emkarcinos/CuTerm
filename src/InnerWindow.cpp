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
    frame=frameChar;
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
    winDimm.posX=parent->termDimm.ws_col/2 - winDimm.sizeX/2;
    winDimm.posY=parent->termDimm.ws_row/2 - winDimm.sizeY/2;
}

InnerWindow::InnerWindow(){ }

InnerWindow::~InnerWindow(){
    parent->removeWindow(*this);
}
