// System include(s)
#include <iostream>
#include <fstream>

// Project include(s)
#include "utils.h"

std::string ReadFile(const std::string& path)
{
	std::string result = "";
	std::string line;
	std::ifstream myfile (path);
	if(myfile.is_open())
	{
		while(getline(myfile,line))
		{
			result += line;
		}
		myfile.close();
	}
	return result;
}
