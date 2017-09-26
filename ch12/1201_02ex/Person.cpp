#include "Person.h"

Person::Person()
{

}

Person::Person(string n, string a)
{
	name = n;
	address = a;
}

int main(void)
{
	Person p("Yuyawei", "Changdao");
	cout << p.getName() << endl;	
	cout << p.getAddress() << endl;
}
