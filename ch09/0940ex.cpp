#include <string>
#include <iostream>
using namespace std;

int main(void)
{
	string q1("When lilacs last in the dooryard bloom'd");
	string q2("The child is father of the man");
	string sentence;

	sentence.assign(q2.begin(), q2.begin()+13);
	sentence.append(q1.substr(q1.find("in"), 15));
	cout << sentence << endl;

	return 0;
}
