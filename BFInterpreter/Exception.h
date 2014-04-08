#pragma once

#include <exception>
#include <string>

class Exception : std::exception
{
public:

	Exception();
	Exception(const std::string & message);
	
	const char * what() const;

	const std::string & getMessage() const;

protected:

	void setMessage(const std::string & message);

private:

	std::string m_message;
};