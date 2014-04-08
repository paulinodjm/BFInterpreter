#include "Interpreter.h"
#include "Exception.h"
#include <iostream>

///////////////////////////////////////////////////////////////////////////
std::array<const char, 8> Interpreter::validChar = {
	'>',
	'<',
	'+',
	'-',
	'.',
	',',
	'[',
	']' 
};

///////////////////////////////////////////////////////////////////////////
bool Interpreter::isValidChar(char c)
{
	for (const char & _c : validChar)
	{
		if (_c == c) return true;
	}
	return false;
}

///////////////////////////////////////////////////////////////////////////
Interpreter::Interpreter(const std::string & source) :
m_source(source),
m_cursor(0)
{
}

///////////////////////////////////////////////////////////////////////////
bool Interpreter::hasNext() const
{
	bool theEnd = m_cursor >= m_source.size();
	if (theEnd && m_loop.size() > 0) throw Exception("Syntax error : unexpected eof; missing ']'!");
	return !theEnd;
}

///////////////////////////////////////////////////////////////////////////
void Interpreter::doNext()
{
	switch (m_source[m_cursor])
	{
	case '>':
		m_memory.next();
		break;

	case '<':
		m_memory.previous();
		break;

	case '+':
		m_memory.increment();
		break;

	case '-':
		m_memory.decrement();
		break;

	case '.':
		std::cout << m_memory.getValue();
		std::cout.flush();
		break;

	case ',':
		unsigned char value;
		std::cin >> value;
		m_memory.setValue(value);
		break;

	case '[':
		if (m_memory.getValue() == 0)
		{
			skip();
		}
		else
		{
			m_loop.push_back(m_cursor);
		}
		break;

	case ']':
		if (m_loop.size() == 0) throw Exception("Syntax error : unexpected ']', no opened block!");
		m_cursor = m_loop.at(m_loop.size() - 1) - 1;
		m_loop.pop_back();
		break;

	default:
		throw new Exception("Internal error : unknown character!");
	}
	m_cursor++;
}

///////////////////////////////////////////////////////////////////////////
void Interpreter::skip()
{
	int level = 1;
	do
	{
		if (!hasNext()) throw Exception("Syntax error : unexpected eof; missing ']'!");

		m_cursor++;
		switch (m_source[m_cursor])
		{
		case '[':
			level++;
			break;

		case ']':
			level--;
			break;

		default:
			break;
		}

	} while (level > 0);
}