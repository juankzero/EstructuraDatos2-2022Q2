#include "API.h"


API::Employee::Employee() : code(0), salary(0), status(0)
{
	memcpy(name, "NA", strlen("NA") + 1);
}

API::Employee::Employee(int _code,const char _name[], float _salary) :
	code(_code), salary(_salary)
{
	memcpy(name, _name, strlen(_name) + 1);
	status = 1;
}

int API::Employee::getCode()
{
	return code;
}

char* API::Employee::getName()
{
	return name;
}

float API::Employee::getSalary()
{
	return salary;
}

bool API::Employee::getStatus()
{
	return status;
}

void API::Employee::setName(char _name[])
{
	memcpy(name, _name, strlen(_name) + 1);
}

void API::Employee::setSalary(float _salary)
{
	salary = _salary;
}

void API::Employee::setStatus(bool _status)
{
	status = _status;
}

char* API::Employee::toChar()
{
	char* charResult = new char(getSizeOf());

	memcpy(&charResult[0], &code, sizeof(code));
	memcpy(&charResult[sizeof(code)], name, sizeof(name));
	memcpy(&charResult[sizeof(code) + sizeof(name)], &salary, sizeof(salary));
	memcpy(&charResult[sizeof(code) + sizeof(name) + sizeof(salary)], &status, sizeof(status));

	return charResult;
}

void API::Employee::fromChar(char* charResult)
{
	memcpy(&code, &charResult[0], sizeof(code));
	memcpy(name, &charResult[sizeof(int)], sizeof(name));
	memcpy(&salary, &charResult[sizeof(int) + sizeof(name)], sizeof(salary));
	memcpy(&status, &charResult[sizeof(int) + sizeof(name) + sizeof(salary)], sizeof(status));
}

int API::Employee::getSizeOf()
{
	return sizeof(code) + sizeof(name) + sizeof(salary) + sizeof(status);
}

API::API()
{
	file = new DataFile("myFile.bin");
}

void API::saveEmployee()
{
	file->open("W");
	Employee* newone = new Employee(100, "Juan Zepeda", 1200);
	file->write(newone->toChar(), 0, newone->getSizeOf());

	newone = new Employee(101, "Viena Zepeda", 1200);
	file->write(newone->toChar(), newone->getSizeOf(), newone->getSizeOf());

	newone = new Employee(102, "Manuel Zepeda", 1200);
	file->write(newone->toChar(), newone->getSizeOf() * 2, newone->getSizeOf());

	file->close();
}

void API::readEmployee()
{
	
	file->open("R");

	Employee* another = new Employee();
	another->fromChar(file->read(another->getSizeOf() * 2, another->getSizeOf()));
	std::cout << another->getCode();

	file->close();

}
