#include "DataFile.h"

#include <iostream>

using std::cerr;
using std::endl;

DataFile::DataFile() : path(nullptr)
{}

DataFile::DataFile(const char* _path) : path(_path)
{}

DataFile::~DataFile()
{
	file.close();
}

void DataFile::open(const char* _openFormat)
{
	if (strcmp(_openFormat, "R") == 0)
		openMode = std::ios_base::in;
	else if (strcmp(_openFormat, "W") == 0)
		openMode = std::ios_base::out;
	else if (strcmp(_openFormat, "RW") == 0)
		openMode = std::ios_base::in | std::ios_base::out;

	file.open(path, openMode | std::ios::binary);
	if (!file) { 
		cerr << "Error: file could not be opened" << endl;
		exit(1);
	}
}

void DataFile::close()
{
	file.close();
}

void DataFile::write(char* _data, unsigned int _position, unsigned int _length)
{
	if (file.is_open())
	{
		file.seekp(_position, std::ios::beg);
		file.write(_data, _length);
	}
}

char* DataFile::read(unsigned int position, unsigned int size)
{
	char* data = new char[size];
	file.seekg(position, std::ios::beg);
	file.read(data, size);

	return data;
}





