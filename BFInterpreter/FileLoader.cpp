#include <fstream>

#include "FileLoader.h"
#include "Interpreter.h"
#include "Exception.h"

///////////////////////////////////////////////////////////////////////////
InterpreterPtr FileLoader::load(const std::string & filename)
{
	// open file
	std::ifstream file(filename);
	if (!file.is_open()) throw Exception("Load error : unable to open file '" + filename + "'!");

	// get the file length
	file.seekg(0, std::ios::end);
	size_t fileSize = file.tellg();
	file.seekg(0, std::ios::beg);
	
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
	if (source.size() == 0) throw Exception("Load error : empty file!");
	return std::make_shared<Interpreter>(source);
}