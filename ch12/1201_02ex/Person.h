#include <iostream>
#include <string>
using namespace std;
class Person
{
private:
	string name;
	string address;
public:
	Person();
	Person(string name, string address);
	string & getName() { return name; };
	string & getAddress() { return address; };
};
