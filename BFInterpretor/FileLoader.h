#pragma once

#include <string>
#include <memory>

class Interpretor;
typedef std::shared_ptr<Interpretor> InterpretorPtr;

class FileLoader
{
public:

	static InterpretorPtr load(const std::string & filename);

private:

	FileLoader() = delete;
	~FileLoader() = delete;
};