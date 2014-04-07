#include "Memory.h"

Memory::Memory(size_t memSize) :
m_memory(memSize, 0),
m_iterator(m_memory.begin())
{

}

unsigned char Memory::getValue()
{
	return *m_iterator;
}

void Memory::setValue(unsigned char value)
{
	(*m_iterator) = value;
}

void Memory::increment()
{
	(*m_iterator)++;
}

void Memory::decrement()
{
	(*m_iterator)--;
}

void Memory::next()
{
	m_iterator++;
}

void Memory::previous()
{
	m_iterator--;
}
