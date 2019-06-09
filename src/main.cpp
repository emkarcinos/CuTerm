#include "CuTerm.h"
#include <iostream>
#include <unistd.h>
 
void showcase(){
    // Create TerminalWindow object

    // Out terminal will have a border made from hashes "#", and will have a title of " Terminal Window ".
    TerminalWindow* terminal = new TerminalWindow('#', " Terminal Window ");
    // Lets first create a text that will be parsed to be used later.

    const std::string sampleText = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
    // Now, we can create our TextObject. We have to give it a size, so it can be appended to the terminal.
    // We can also specify the spacing between the lines.
    TextObject* textObj = new TextObject(sampleText, 61, 11);
    // Now we can align the text by using format() method.
    // We can again specify the spacing between the lines.
    textObj->format("center", 1);

    // Now lets create a plain text window that will have our text inside it.
    TextWindow* win1 = new TextWindow(*textObj, '*', " Lorem ipsum ");
    // All we need to do to see our window inside a terminal is to add it to it!
    terminal->append(*win1);
    // Lets wait for an enter key, and lets close our window by calling its destructor.
    std::cin.get();
    delete win1;

    // Now lets give the user some space to type.
    // We need to have some variable that will store user input. Let it be a string for now.
    std::string userInput;
    // We have to create an instance of PromptWindow that will be used with the output type we specified. Here is std::string.
    PromptWindow<std::string>* winPrompt = new PromptWindow<std::string>(*textObj, '*', " How about that? ");
    terminal->append(*winPrompt);
    // All we need to do now is to call prompt method and give it an output variable.
    winPrompt->prompt(userInput);
    sleep(0.2);
    std::cin.get();
    delete winPrompt;
    // Lets see what we typed!
    TextObject* textObj2 = new TextObject(userInput, 61, 1);
    TextWindow* win2 = new TextWindow(*textObj2, '*', " You: ");
    terminal->append(*win2);
    std::cin.get();
    delete win2;

    // PasswordPrompt is a work in progress though.
    std::string password;
    PasswordPrompt* passwrdWin = new PasswordPrompt('*');
    terminal->append(*passwrdWin);
    passwrdWin->prompt(password);
    sleep(0.2);
    std::cin.get();
    delete passwrdWin;
    delete terminal;
}

int main(){
    showcase();
    return 0;
}