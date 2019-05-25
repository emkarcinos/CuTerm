#include "TerminalWindow.h"
#include <iostream>

int main(){
    TerminalWindow* terminal = new TerminalWindow('#', "Jechane");
    terminal->draw();
    std::cin.get();
    delete terminal;
}