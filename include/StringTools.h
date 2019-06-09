#pragma once

#include <string>

#define DELIM " \t,.-\0"

class StringTools {
    public:
        /* Checks whereher the character is a delimeter */
        static bool isDelimeter(const char& ch);
        /* Splits the string into multiple lines */
        static std::string splitStringToLines(const std::string& text, const unsigned int& sizeX, const unsigned int& sizeY, const unsigned int& spacing=0);
        
        /* Formatting functions */
        /* Aligns one line to the center of the textbox */
        static std::string alignLineCenter(const std::string& text, const unsigned int& size);
        /* Aligns one line to the left side of the textbox */
        static std::string alignLineLeft(const std::string& text, const unsigned int& size);
        /* Aligns one line to the right side of the texbox */
        static std::string alignLineRight(const std::string& text, const unsigned int& size);
};