#include "ArgsParser.h"

///////////////////////////////////////////////////////////////////////////
ArgsParser::ArgsParser(int argc, char *argv[])
{
	if (argc == 2)
	{
		m_inputFilename = argv[1];
	}
}

///////////////////////////////////////////////////////////////////////////
const std::string & ArgsParser::getInputFilename() const
{
	return m_inputFilename;
}