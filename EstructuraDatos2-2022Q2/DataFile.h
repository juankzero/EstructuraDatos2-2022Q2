#pragma once
#include <iostream>
#include <fstream>

class DataFile 
{
public:
	DataFile();
	DataFile(const char*);
	~DataFile();

	void open(const char*);
	void close();
	void write(char*, unsigned int, unsigned int);
	char* read(unsigned int, unsigned int);
private:
	std::fstream file;
	std::ios_base::openmode openMode;
	const char* path;
};