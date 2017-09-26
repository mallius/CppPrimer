#include <iostream>
#include <fstream>
#include <stdexcept>
#include <limits>
#include <string>
#include <cstring>

using namespace std;

ifstream& open_file(ifstream &in, const string &file)
{
	in.close(); //close in case it was already open
	in.clear(); //clear any existing errors
	//if the opne fails, the stream will be in an invalid state
	in.open(file.c_str());	//open the file we were given
	return in;				//condition state is good if open succeeded
}

int main(void)
{
	ifstream in;
	string file("in");
	open_file(in, file);

	if(in)
	{
		cout << "ok: open file in " << endl;
	}

	return 0;
}
