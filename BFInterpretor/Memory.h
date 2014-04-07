#pragma once

#include <vector>

class Memory
{
public:

	Memory(size_t memSize = 254);

	unsigned char getValue();
	void setValue(unsigned char value);
	void increment();
	void decrement();

	void next();
	void previous();

private:

	std::vector<unsigned char> m_memory;
	std::vector<unsigned char>::iterator m_iterator;
};