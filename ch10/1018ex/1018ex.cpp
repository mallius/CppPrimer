#include <map>
#include <string>
#include <vector>
#include <iostream>
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
	map<string, vector<string> > svm;
	ifstream infile;
	string name, family;
	if(argc != 2)
	{
		cout << "error ./a.out argv[1]" << endl;
		return -1;
	}
	if(!open_file(infile, argv[1]))	
	{
		cout << "error can not open " << argv[1] << endl;
		return -2;
	}
	while(infile >> name >> family)
	{
		cout << name << " " << family << endl;	

		map<string, vector<string> >::iterator it = svm.find(family);
		if(it != svm.end())
		{
			// 找到家族,加入名字 
			it->second.push_back(name);
		}
		else
		{
			//未找到家族
			string fam = family ;
			vector<string> na;
			na.push_back(name);
			svm.insert(make_pair(fam, na));
		}
	}
	
	// 遍历map
	cout << "遍历map:" << endl;
	for(map<string, vector<string> >::iterator it = svm.begin(); it != svm.end(); ++it)
	{
		cout << "Family: " << it->first << endl;
		cout << "Family members:" << it->second.size() << endl;
		for(vector<string>::iterator itname = it->second.begin(); itname != it->second.end(); ++itname)
		{
			cout << *itname << endl;
		}
	}
	
	return 0;
}
