#pragma once

#include <string>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

/**
 *	@brief Reads and returns the content of a file
 *	@param path The path of the file to read.
 *	@return The content of the file in a string.
 */
std::string ReadFile(const std::string& path);
