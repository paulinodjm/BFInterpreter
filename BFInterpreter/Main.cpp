#include <iostream>
#include <cstdlib>

#include "ArgsParser.h"
#include "FileLoader.h"
#include "Interpreter.h"
#include "Exception.h"

int main(int argc, char *argv[])
{
	try
	{
		ArgsParser argsParser(argc, argv);
		std::cout << argsParser.getInputFilename() << std::endl;
		InterpreterPtr interpreter = FileLoader::load(argsParser.getInputFilename());

		while (interpreter->hasNext())
		{
			interpreter->doNext();
		}

		if (!argsParser.getExit())
			system("pause");
	}
	catch (Exception & exception)
	{
		std::cout << exception.what() << std::endl;
		system("pause");
	}
	return EXIT_SUCCESS;
}