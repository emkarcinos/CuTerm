#include "TerminalWindow.h"
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <iostream>

void TerminalWindow::updateTerminalSize(){
    ioctl(STDOUT_FILENO,TIOCGWINSZ, &size);
}

void TerminalWindow::draw() {
    for(int row=0; row<size.ws_row; row++){
        for(int col=0; col<size.ws_col; col++){
            std::cout << drawingMarix[row][col];
        }
        std::cout << "\n";
    }
}

TerminalWindow::TerminalWindow(){
    updateTerminalSize();
    draw();
}

void TerminalWindow::update(){};
void TerminalWindow::append(){};