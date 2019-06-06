#include "StringTools.h"

#include <sstream>

bool isDelimeter(const char& ch){
    for(char del : DELIM) 
        if(ch==del) return 1;
    return 0;
}

std::string splitStringToLines(const std::string& text, const unsigned int& sizeX, const unsigned int& sizeY, const unsigned int& spacing){
    std::string finalStr;
    unsigned int lastEndPos=0; // Position of the ending of the last line
    unsigned int cursorPos=0; 
    unsigned int lastDelimOccurrence=0;
    for(unsigned int line=0; line<sizeY; line++){
        // find where to split the text
        cursorPos=lastEndPos;
        lastDelimOccurrence=cursorPos;
        for(; cursorPos<text.length(); cursorPos++){
            if (isDelimeter(text[cursorPos])){
                if(cursorPos-lastEndPos<sizeX)
                    lastDelimOccurrence=cursorPos;
                else {
                    for(unsigned int i=0; i<lastDelimOccurrence-lastEndPos; i++)
                        finalStr+=text[i+lastEndPos];
                    for(unsigned int spac=0; spac<=spacing; spac++){
                        if(spac>=1) line++;
                        if(line>=sizeY) break;
                        finalStr+="\n";
                    }
                    lastEndPos=lastDelimOccurrence+1;
                    break;
                }
            }
        }
    }
    if(cursorPos==text.length()){
        for(unsigned int i=lastEndPos; i<text.length(); i++)
            finalStr+=text[i];
    }
    return finalStr;
}

std::string alignLineCenter(const std::string& text, const unsigned int& size){
    std::istringstream f(text);
    std::stringstream stream;
    std::string line;
    while(std::getline(f, line)){
        std::string strPredecessor="";
        for(unsigned int ch=line.length()/2; ch<size/2; ch++){
            strPredecessor+=' '; // asterisk just for testing, should be ' ' 
            line+=' ';
        }
        if(size%2==0)
            line.pop_back();
        stream << strPredecessor << line << "\n";
    }
    return stream.str();
}

std::string alignLineLeft(const std::string& text, const unsigned int& size){
    std::istringstream f(text);
    std::stringstream stream;
    std::string line;
    while(std::getline(f, line)){
        for(unsigned int ch=line.length(); ch<size; ch++)
            line+=' '; // asterisk just for testing, should be ' ' 
        stream << line << "\n";
    }
    return stream.str();
}   

std::string alignLineRight(const std::string& text, const unsigned int& size){ 
    std::istringstream f(text);
    std::stringstream stream;
    std::string line;
    while(std::getline(f, line)){
        std::string strPredecessor="";
        for(unsigned int ch=line.length(); ch<size; ch++)
            strPredecessor+=' '; // asterisk just for testing, should be ' ' 
        stream << strPredecessor << line << "\n";
    }
    return stream.str();
}