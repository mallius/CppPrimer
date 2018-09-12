// g++ -std=c++11 thisfile.cpp
#include <iostream>
#include <set>

using namespace std;

int main(void)
{
	set<string> excluded {"class", "success"};
	set<string> words {"boys","girls","class","success","babys"};
	set<string> results;
	string temp;
	string word;

	for(auto iter = words.begin(); iter != words.end(); ++iter)
	{
		temp = *iter;
		if(!excluded.count(temp))
		{
			word.assign(temp.begin(), temp.end()-1);
			results.insert(word);
		}
	}
	//result
	for(auto &x : results)
	{
		cout << x << endl;
	}
}
