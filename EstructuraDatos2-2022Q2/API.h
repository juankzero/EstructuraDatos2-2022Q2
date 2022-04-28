#pragma once

#include "DataFile.h"

class API 
{
private:
	DataFile* file;
	class Employee 
	{
		private:
			int code;
			char name[30];
			float salary;
			bool status;

		public:
			Employee();
			Employee(int, const char[], float);
			int getCode();
			char* getName();
			float getSalary();
			bool getStatus();

			void setName(char[]);
			void setSalary(float);
			void setStatus(bool);

			char* toChar();
			void fromChar(char*);
			int getSizeOf();

	};

public:
	API();

	void saveEmployee();
	void readEmployee();
};