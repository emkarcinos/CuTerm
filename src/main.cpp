
#include "TerminalWindow.h"
#include "TextWindow.h"
#include "TextObject.h"
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
    std::string text="To jest przykladowy tekst, jakis tam sobie istnieje.";
    TextObject textObject = TextObject(text, 15, 25, 1);
    textObject.format("center");
    std::cout << textObject.toString();

}