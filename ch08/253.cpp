#include <iostream>
#include <fstream>
#include <stdexcept>
#include <limits>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

int main(void)
{
	//3.清除文件流的状态
	vector<string> files;
	files.push_back("out");
	files.push_back("in");
	files.push_back("in01");
	files.push_back("in02");

	ifstream input;
	vector<string>::const_iterator it = files.begin();
	while(it != files.end())
	{
		input.open(it->c_str());
		if(!input)
		{
			cerr << "can not open file: " << it->c_str() << endl;
			break;
		}

		string s;
		while(input >> s)
		{
			cout << "process(s): " << s << endl;
		}
		input.close();
		input.clear();
		++it;
	}

	return 0;
}
