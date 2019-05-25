#include "TerminalWindow.h"
#include <unistd.h>
#include <sys/ioctl.h>
#include <iostream>

void TerminalWindow::updateTerminalSize(){
    ioctl(STDOUT_FILENO,TIOCGWINSZ,&size);
}

TerminalWindow::TerminalWindow(){
    updateTerminalSize();
}

void TerminalWindow::draw() {
    for(unsigned int row=0; row<size.ws_row; row++){
        for(unsigned int col=0; row<size.ws_col; col++){
            std::cout << drawingMarix[col][row];
        }
        std::cout << "\n";
    }
}
void TerminalWindow::update(){};
void TerminalWindow::append(){};