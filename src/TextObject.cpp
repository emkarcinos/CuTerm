#include "TextObject.h"
#include "StringTools.h"

TextObject::TextObject(){
    size.x=20;
    size.y=5;
    textStr="";
}

void TextObject::format(const std::string& method, const unsigned int& spacing){
    if(spacing!=9999) size.spacing=spacing;
    std::string result=splitStringToLines(textStr, size.x, size.y, size.spacing);
    if (method=="right")
        finalStr=alignLineRight(result, size.x);
    else if (method=="center")
        finalStr=alignLineCenter(result, size.x);
    else
        finalStr=alignLineLeft(result, size.x);
}

void TextObject::appendString(const std::string& text){
    if(text.length()==0) // If the text isn't empty, add a spacebar after existing string
        textStr+=" ";
    textStr+=text;
    format();
}

std::string TextObject::toString(){
    return finalStr;
}

TextObject::TextObject(const std::string& text, const unsigned int& x, const unsigned int& y, const unsigned int& spacing){
    size.x=x;
    size.y=y;
    size.spacing=spacing;
    appendString(text);
}

TextObject::~TextObject(){
    textStr="";
    finalStr="";
}


