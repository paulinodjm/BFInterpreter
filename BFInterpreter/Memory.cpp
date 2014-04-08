#include "Memory.h"
#include "Exception.h"
#include <sstream>

///////////////////////////////////////////////////////////////////////////
Memory::Memory(size_t memSize) :
m_memory(memSize, 0),
m_iterator(m_memory.begin())
{
	// nothing to do
}

///////////////////////////////////////////////////////////////////////////
unsigned char Memory::getValue()
{
	return *m_iterator;
}

///////////////////////////////////////////////////////////////////////////
void Memory::setValue(unsigned char value)
{
	(*m_iterator) = value;
}

///////////////////////////////////////////////////////////////////////////
void Memory::increment()
{
	(*m_iterator)++;
}

///////////////////////////////////////////////////////////////////////////
void Memory::decrement()
{
	(*m_iterator)--;
}

///////////////////////////////////////////////////////////////////////////
void Memory::next()
{
	m_iterator++;
	if (m_iterator == m_memory.end())
	{
		std::ostringstream sstr;
		sstr << "Logical error : unable to move the pointer after " << UCHAR_MAX << "!";
		throw Exception(sstr.str());
	}
}

///////////////////////////////////////////////////////////////////////////
void Memory::previous()
{
	if (m_iterator == m_memory.begin()) throw Exception("Logical error : unable to move the pointer before 0!");
	m_iterator--;
}
