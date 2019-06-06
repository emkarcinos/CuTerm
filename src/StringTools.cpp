#include "StringTools.h"

bool isDelimeter(const char& ch){
    for(char del : DELIM) 
        if(ch==del) return 1;
    return 0;
}

std::string splitStringToLines(const std::string& text, const unsigned int& sizeX, const unsigned int& sizeY){
    static std::string finalStrArray;
    unsigned int lastEndPos=0; // Position of the ending of the last line
    unsigned int cursorPos=0; 
    unsigned int lastSpaceOccurrence=0;
    for(unsigned int line=0; line<sizeY; line++){
        // find where to split the text
        lastSpaceOccurrence=cursorPos;
        for(cursorPos; cursorPos<text.length(); cursorPos++){
            if (isDelimeter(text[cursorPos])){
                if(cursorPos-lastEndPos<sizeX)
                    lastSpaceOccurrence=cursorPos;
                else {
                    for(unsigned int i=0; i<lastSpaceOccurrence-lastEndPos; i++)
                        finalStrArray+=text[i+lastEndPos];
                    finalStrArray+="\n";
                    lastEndPos=lastSpaceOccurrence+1;
                    break;
                }
            }
        }
        cursorPos=lastEndPos;
    }
    for(unsigned int i=lastEndPos; i<text.length(); i++)
        finalStrArray+=text[i];
    return finalStrArray;
}

std::string alignLineCenter(const std::string& text){

}

std::string alignLineLeft(const std::string& text){

}

std::string alignLineRight(const std::string& text){

}