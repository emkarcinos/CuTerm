#include "TerminalWindow.h"
#include "TextWindow.h"
#include <iostream>

int main(){
    TerminalWindow* terminal = new TerminalWindow('#', " Terminal ");
    terminal->draw();
    TextWindow* win1 = new TextWindow('%', " Random Window ", "Centered Text");
    terminal->append(*win1);
    std::cin.get();
    delete terminal;
    delete win1;    
}