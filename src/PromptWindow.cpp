#include "PromptWindow.h"
#include "TextObject.h"

#include <string>

template<class type>
void PromptWindow<type>::addTextObject(TextObject& textObj){
    if(textObj.size.x > winDimm.sizeX-2 && textObj.size.y > winDimm.sizeY-3) 
    // if the window's dimmensions are not big enoguh, the function will return.
        return;
    textObj.parent=this;
    unsigned int startX = winDimm.sizeX/2 - textObj.size.x/2;
    unsigned int startY = (winDimm.sizeY/2 - textObj.size.y/2)-1;
    unsigned int lineCount=0;
    unsigned int ptr=0;
    for(const char& ch : textObj.finalStr){
        if(ch=='\n'){lineCount++; ptr=0;}
        else {
            drawingMarix[startY+lineCount][startX+ptr]=ch;
            ptr++;
        }
    }
}

template<class type>
void PromptWindow<type>::drawSeparator(){
    for(unsigned int pos=1; pos<winDimm.sizeX-1; pos++)
        drawingMarix[winDimm.sizeY-3][pos]=frame;
}

template<class type>
void PromptWindow<type>::moveCursor(){

}

template<class type>
PromptWindow<type>::PromptWindow(TextObject& textObj, const type& output, const char& frameChar, const char* winTitle){
    setDimmensions(textObj.size.x+4, textObj.size.y+6);
    initMatrix();
    setFrame(frameChar);
    setTitle(winTitle);
    addTextObject(textObj);
    drawSeparator();
}

template<class type>
void PromptWindow<type>::removeTextObject(TextObject& textObj){

}
template<class type>
void PromptWindow<type>::clear(){

}

template<class type>
PromptWindow<type>::~PromptWindow(){

}

template class PromptWindow<int>;
template class PromptWindow<std::string>;
template class PromptWindow<double>;