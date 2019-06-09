#include "PromptWindow.h"
#include "TerminalWindow.h"
#include "TextWindow.h"
#include "TextObject.h"
#include "PasswordPrompt.h"
#include <iostream>

int main(){
    TerminalWindow* terminal = new TerminalWindow('#', " Terminal ");
    terminal->draw();
    
    std::string textRaw = "Lorem ipsum dolor sit amet ligula. Cras ac diam. Suspendisse a quam molestie a, laoreet nisl eu wisi. Morbi ligula quis mauris. Etiam vestibulum vehicula. Nunc viverra, enim urna, placerat tempus, neque auctor congue eu, odio. Morbi bibendum. Nulla consequat urna vitae ornare a, diam. Vestibulum nibh ultricies lobortis quis, accumsan lorem. Etiam tempor vitae, ipsum. Suspendisse molestie. Donec elementum vitae, semper magna ac eros quis ante. Curabitur placerat, nulla pellentesque quis, eleifend ac, ultricies eu, neque. Maecenas viverra venenatis";
    TextObject* textObj = new TextObject(textRaw, 61,7);
    textObj->format("left", 1);
    //delete textObj;
    std::string pass;
    PasswordPrompt* win1 = new PasswordPrompt('*', " Test ");
    terminal->append(*win1);
    win1->prompt(pass);  
    delete win1;
    std::cin.get();
    std::cin.get();
    delete terminal;
}