#pragma once

#include <string>

#define DELIM " \n\t,.-\0"

/* Checks whereher the character is a delimeter */
bool isDelimeter(const char& ch);
/* Splits the string into multiple lines */
std::string splitStringToLines(const std::string& text, const unsigned int& sizeX, const unsigned int& sizeY);

/* Formatting functions */
/* Aligns one line to the center of the textbox */
std::string alignLineCenter(const std::string& text);
/* Aligns one line to the left side of the textbox */
std::string alignLineLeft(const std::string& text);
/* Aligns one line to the right side of the texbox */
std::string alignLineRight(const std::string& text);