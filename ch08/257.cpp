#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <limits>
#include <string>
#include <cstring>

using namespace std;

int main(void)
{
	//1.stringstream对象的使用
	string line, word;
	while(getline(cin, line))
	{
		istringstream stream(line);

		while(stream >> word)
		{
			cout << "word: " << word 
				<< ", do per-word processing" << endl;
		}
	}
	return 0;
}
