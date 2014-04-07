#include <fstream>
#include <iostream>

#include "FileLoader.h"
#include "Interpreter.h"

InterpreterPtr FileLoader::load(const std::string & filename)
{
	// open file
	std::ifstream file(filename);
	if (!file.is_open())
	{
		return InterpreterPtr();
	}

	// get the file length
	file.seekg(0, std::ios::end);
	size_t fileSize = file.tellg();
	file.seekg(0, std::ios::beg);
	if (fileSize == 0)
	{
		return InterpreterPtr();
	}

	// create the Interpreter
	std::string source;
	for (int i = 0; i < fileSize; i++)
	{
		char nextChar = file.get();
		if (Interpreter::isValidChar(nextChar))
		{
			source.push_back(nextChar);
		}
	}
	return std::make_shared<Interpreter>(source);
}