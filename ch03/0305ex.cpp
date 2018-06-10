#include <iostream>
#include <string>
using std::cin;
using std::string;
using std::cout;
using std::endl;
int main(void)
{
	/*string word;
	while(cin >> word)
		cout << word << endl;
	return 0;
	*/ 
	string line;
	while(getline(cin, line))
		cout << line << endl;
	return 0;
}
