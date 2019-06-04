#include "TextWindow.h"
#include "string.h"

void TextWindow::addText(const char* text){
    int textSize=strlen(text);
    unsigned int startPos = winDimm.sizeX/2 - textSize/2;
    for(unsigned int pos=0; pos<textSize; pos++){
        if(pos+2==winDimm.sizeX-2)
            return;
        drawingMarix[3][pos+startPos]=text[pos];
    }
}

TextWindow::TextWindow(){
    setDimmensions(5,5);
    initMatrix();
}

TextWindow::TextWindow(const char &frameChar, const char* winName, const char* text){
    setDimmensions(25,8);
    initMatrix();
    setFrame(frameChar);
    setTitle(winName);
    addText(text);
}
void TextWindow::makeDrawingMatrix(){

}

void TextWindow::clear(){

}


TextWindow::~TextWindow(){
    clear();
}