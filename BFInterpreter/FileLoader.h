#pragma once

#include <string>
#include <memory>

class Interpreter;
typedef std::shared_ptr<Interpreter> InterpreterPtr;

class FileLoader
{
public:

	static InterpreterPtr load(const std::string & filename);

private:

	FileLoader() = delete;
	~FileLoader() = delete;
};