#include <iostream>
#include <fstream>
#include <cstdlib>

#include "ArgsParser.h"
#include "FileLoader.h"
#include "Interpretor.h"

int main(int argc, char *argv[])
{
	ArgsParser argsParser(argc, argv);
	InterpretorPtr interpretor = FileLoader::load(argsParser.getInputFilename());
	if (!interpretor) return EXIT_FAILURE;

	while (interpretor->hasNext())
	{
		interpretor->doNext();
	}

	system("pause");
	return EXIT_SUCCESS;
}