#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__ 

#include <iostream>
#include <string>

using namespace std;
class Employee
{
private:
	string name;
	int id;
	static int counter;
public:
	Employee():name("Noname"), id(counter)
	{
		counter++;
	}

	Employee(const Employee& emp)
	{
		name = emp.name;
		id = emp.id;
	}

	Employee(const string nm): name(nm), id(counter)
	{
		counter++;
	}

	Employee& operator=(const Employee& emp)
	{
		name = emp.name;
		id = emp.id;
		return *this;
	}

	void show()
	{
		cout << "name: " << name << endl;
		cout << "id: " << id << endl;
	}
};

#endif
