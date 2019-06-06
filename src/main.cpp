
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
    std::string test ="To jest testowy wyraz, powinien zostac podzielony tak jak trzeba.";
    std::string arr=splitStringToLines(test, 21, 10);
    arr=alignLineRight(arr,31);
    std::cout << arr;

}