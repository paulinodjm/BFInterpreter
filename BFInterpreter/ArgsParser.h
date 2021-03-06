#pragma once

#include <string>
#include <vector>

class ArgsParser
{
public:

	ArgsParser(int argc, char *argv[]);

	const std::string & getInputFilename() const;
	bool getExit() const;

private:

	std::string m_inputFilename;
	bool m_exit;
};