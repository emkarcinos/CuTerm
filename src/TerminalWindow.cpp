#include "TerminalWindow.h"
#include "InnerWindow.h"

#include <unistd.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <iostream>
#include <string.h>

void TerminalWindow::updateTerminalSize(){
    ioctl(STDOUT_FILENO,TIOCGWINSZ, &termDimm);
}

void TerminalWindow::initMatrix(){
    for(int row=0; row<termDimm.ws_row; row++){
        for(int col=0; col<termDimm.ws_col; col++){
            drawingMarix[row][col]=32;
        }
    }
}

void TerminalWindow::setFrame(const char &frameChar){
    for(int row=0; row<termDimm.ws_row; row++){
        for(int col=0; col<termDimm.ws_col; col++){
            if(row==0 || row==termDimm.ws_row-1 || col==0 || col==termDimm.ws_col-1)
                drawingMarix[row][col]=frameChar;
        }
    }
}

void TerminalWindow::setTitle(const char *winTitle){
    const unsigned short int titleLength=strlen(winTitle);
    const unsigned short int writePos=termDimm.ws_col/2 - titleLength/2;
    for(unsigned int i=0; i<titleLength; i++)
        drawingMarix[0][writePos+i]=winTitle[i];
}

void TerminalWindow::draw() const{
    for(int row=0; row<termDimm.ws_row; row++){
        for(int col=0; col<termDimm.ws_col; col++){
            std::cout << drawingMarix[row][col];
        }
        if(row!=termDimm.ws_row-1) // won't put newline after last line
            std::cout << "\n";
    }
    //move the "cursor" to the beginning of the screen
    printf("\033[H");
}

void TerminalWindow::clear() const {
    std::cout << "\033[2J\033[1;1H";
}

TerminalWindow::TerminalWindow(){
    system("setterm -cursor off");
    updateTerminalSize();
    initMatrix();
}

TerminalWindow::TerminalWindow(const char &frameChar, const char* winTitle){
    system("setterm -cursor off");
    updateTerminalSize();
    initMatrix();
    setFrame(frameChar);
    if(winTitle!=nullptr)
        setTitle(winTitle);
}

TerminalWindow::~TerminalWindow(){
    clear();
    system("setterm -cursor on");
}

void TerminalWindow::alterMatrix(){
    for(int row=0; row<termDimm.ws_row; row++){
        for(int col=0; col<termDimm.ws_col; col++){
            drawingMarix[row][col]='a';
        }
    }
}

void TerminalWindow::append(InnerWindow& win){
    // Checks whether the InnerWindow fits inside the terminal
    if(win.winDimm.sizeX>termDimm.ws_col || win.winDimm.sizeY>termDimm.ws_row)
        return;
    win.parent=this;
    const unsigned int startX = termDimm.ws_col/2 - win.winDimm.sizeX/2;
    const unsigned int startY = termDimm.ws_row/2 - win.winDimm.sizeY/2;
    win.setPos(startX, startY); //Sets window position on the terminal
    for(unsigned int row=0; row<win.winDimm.sizeY; row++){
        for(unsigned int col=0; col<win.winDimm.sizeX; col++){
            //std::cout << win.drawingMarix[row][col];
            this->drawingMarix[row+startY][col+startX]=win.drawingMarix[row][col];
        }
    }
    draw();
}

void TerminalWindow::removeWindow(InnerWindow& win){
    const unsigned int startY=win.winDimm.posY;
    const unsigned int startX=win.winDimm.posX;
    for(unsigned int row=0; row<win.winDimm.sizeY; row++){
        for(unsigned int col=0; col<win.winDimm.sizeX; col++){
            drawingMarix[row+startY][col+startX]=' ';
        }
    }
    win.parent=nullptr;
    draw();
}