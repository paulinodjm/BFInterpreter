#include <iostream>
#include <fstream>
#include <cstdlib>

#include "ArgsParser.h"
#include "FileLoader.h"
#include "Interpreter.h"


int main(int argc, char *argv[])
{
	ArgsParser argsParser(argc, argv);
	InterpreterPtr interpreter = FileLoader::load(argsParser.getInputFilename());
	if (!interpreter) return EXIT_FAILURE;

	while (interpreter->hasNext())
	{
		interpreter->doNext();
	}

	system("pause");
	return EXIT_SUCCESS;
}