#include "Interpretor.h"
#include <iostream>

std::array<const char, 8> Interpretor::validChar = {
	'>',
	'<',
	'+',
	'-',
	'.',
	',',
	'[',
	']' 
};

bool Interpretor::isValidChar(char c)
{
	for (const char & _c : validChar)
	{
		if (_c == c) return true;
	}
	return false;
}

Interpretor::Interpretor(const std::string & source) :
m_source(source),
m_cursor(0),
m_loopStart(-1)
{
}

bool Interpretor::hasNext() const
{
	return m_cursor < m_source.size();
}

void Interpretor::doNext()
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
		m_loopStart = m_cursor;
		break;

	case ']':
		if (m_memory.getValue() != 0)
		{
			m_cursor = m_loopStart - 1;
		}
		break;

	default:
		break;
	}
	m_cursor++;
}