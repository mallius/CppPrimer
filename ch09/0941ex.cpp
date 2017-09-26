#include <iostream>
#include <string>
using namespace std;

string greet(string form, string lastName, string title, string::size_type pos, int length)
{
	form.replace(8, 5, lastName);
	form.replace(5, 2, title.substr(pos, length));
	return form;
}

int main(void)
{
	string generic1("Dear Ms Daisy:");
	string generic2("MrsMsMissPeople");

	string lastName("AnnaP");
	string salute = greet(generic1, lastName, generic2, 5, 4);
	cout << salute << endl;

	return 0;
}
