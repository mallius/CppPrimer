#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main(void)
{
	string line;
	vector<string> svec;
	ifstream infile("1.txt");

	if(!infile)
	{
		cout << "open 1.txt error." << endl;
	}
	while(getline(infile, line))
	{
		svec.push_back(line);
	}

	string stringline , word;
	istringstream stream;
	for(vector<string>::iterator it = svec.begin(); it != svec.end(); ++it )
	{
		stream.str(*it);
		while(stream >> word)
		{
			cout << "word: " << word << endl;
		}
		stream.clear();	
	}

	return 0;
}
