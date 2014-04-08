#pragma once

#include <string>
#include <array>
#include <vector>

#include "FileLoader.h"
#include "Memory.h"

class Interpreter
{
public:

	static std::array<const char, 8> validChar;
	static bool isValidChar(char c);

	Interpreter(const std::string & source);

	bool hasNext() const;
	void doNext();

private:

	void skip();

	std::string m_source;
	size_t m_cursor;
	std::vector<size_t> m_loop;
	Memory m_memory;
};
typedef std::shared_ptr<Interpreter> InterpreterPtr;