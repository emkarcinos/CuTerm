#include "TextObject.h"

void TextObject::initTextArray(){
    for(unsigned int row=0; row<size.y; row++){
        for(unsigned int col=0; col<size.x; col++){
            textArray[row][col]=' ';
        }
    }
}

TextObject::TextObject(){
    size.x=20;
    size.y=5;
    textStr="";
    initTextArray();
}

TextObject::TextObject(const unsigned int& x, const unsigned int& y, const std::string& text){
    size.x=x;
    size.y=y;
    textStr+=text;
    initTextArray();
}

void TextObject::appendString(const std::string& text){
    if(text!="") // If the text isn't empty, add a spacebar after existing string
        textStr+=" ";
    textStr+=text;
}

void format(const std::string& text, const std::string method, const unsigned int spacing=0){

}


