#include "TextObject.h"
#include "StringTools.h"

TextObject::TextObject(){
    size.x=20;
    size.y=5;
    textStr="";
}

TextObject::TextObject(const unsigned int& x, const unsigned int& y, const std::string& text){
    size.x=x;
    size.y=y;
    textStr+=text;
}

void TextObject::appendString(const std::string& text){
    if(text!="") // If the text isn't empty, add a spacebar after existing string
        textStr+=" ";
    textStr+=text;
}

void TextObject::format(const std::string& text, const std::string& method, const unsigned int& spacing){
    std::string result=splitStringToLines(text, size.x, size.y, spacing);
}


