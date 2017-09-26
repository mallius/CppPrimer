#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <map>
#include <stdexcept>
#include <fstream>
#include <sstream>

using namespace std;

ifstream& open_file(ifstream & in, const string & file)
{
	in.close();
	in.clear();
	in.open(file.c_str());
	return in;
}

int main(int argc, char **argv)
{
	map<string, string> trans_map;
	string key, value;
	if(argc != 3)
		throw runtime_error("wrong number of arguments");

	ifstream map_file;
	if(!open_file(map_file, argv[1]))	
		throw runtime_error("no transformation file");

	while(map_file >> key >> value)
	{
		cout << "key: " << key << ", value: " << value << endl;
		trans_map.insert(make_pair(key, value));
	}
	//ok, now we're ready to do the transformations
	//open the input file and check that the open succeeded

	ifstream input;
	if(!open_file(input, argv[2]))
		throw runtime_error("no input file");

	string line; //hold each line from the inpu
	while(getline(input, line))
	{
		istringstream stream(line); // read the line a word at a time
		string word;
		bool firstword = true;		// controls whether a space is printed

		while(stream >> word)
		{
			//ok: the actual mapwork, this part is the heart of the program
			map<string, string>::const_iterator map_it = trans_map.find(word);
			// if this word is in the transformation map
			if(map_it != trans_map.end())
				//replace it by the transformation value in the map
				word = map_it->second;
			if(firstword)
				firstword = false;
			else
				cout << " ";
			cout << word;
		}
		cout << endl;
	}

	return 0;
}
