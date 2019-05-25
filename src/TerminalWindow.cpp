#include "TerminalWindow.h"
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <iostream>

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
    unsigned short int titleLength=sizeof(winTitle)/sizeof(char)-1;
    unsigned short int writePos=termDimm.ws_col/2 - titleLength/2;
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

void TerminalWindow::append(){};

void TerminalWindow::alterMatrix(){
    for(int row=0; row<termDimm.ws_row; row++){
        for(int col=0; col<termDimm.ws_col; col++){
            drawingMarix[row][col]='a';
        }
    }
}