#pragma once

#include <string>

/* Splits the string into multiple lines */
std::string* splitStringToLines(const std::string& text);

/* Formatting functions */
/* Aligns one line to the center of the textbox */
std::string alignLineCenter(const std::string& text);
/* Aligns one line to the left side of the textbox */
std::string alignLineLeft(const std::string& text);
/* Aligns one line to the right side of the texbox */
std::string alignLineRight(const std::string& text);