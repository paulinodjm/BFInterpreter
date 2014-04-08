#include "ArgsParser.h"
#include "Exception.h"

///////////////////////////////////////////////////////////////////////////
ArgsParser::ArgsParser(int argc, char *argv[]) :
m_exit(false)
{
	for (int i = 1; i < argc; i++)
	{
		std::string arg(argv[i]);

		if (arg == "-exit")
		{
			m_exit = true;
		}
		else if (m_inputFilename.empty())
		{
			m_inputFilename = arg;
		}
		else
		{
			throw Exception("Argument error : unknown argument '" + arg + "'!");
		}
	}

	if (m_inputFilename.empty()) throw Exception("Argument error : no input filename!");
}

///////////////////////////////////////////////////////////////////////////
const std::string & ArgsParser::getInputFilename() const
{
	return m_inputFilename;
}

///////////////////////////////////////////////////////////////////////////
bool ArgsParser::getExit() const
{
	return m_exit;
}