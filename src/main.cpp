
#include "TerminalWindow.h"
#include "TextWindow.h"
#include "StringTools.h"
#include <iostream>

int main(){
    // TerminalWindow* terminal = new TerminalWindow('#', " Terminal ");
    // terminal->draw();
    // TextWindow* win1 = new TextWindow('%', " Random Window ", "Centered Text");
    // win1->setFrame('*');
    // win1->setTitle(" New Title ");
    // terminal->append(*win1);
    // delete win1;    
    // std::cin.get();
    // delete terminal;
    std::string test ="To jest testowy wyraz, powinien zostać podzielony tak jak trzeba.";
    std::string arr=splitStringToLines(test, 150, 10);
    std::cout << arr;

}