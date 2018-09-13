// g++ -std=c++11 thisfile.cpp
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool isShorter(const string &s1, const string& s2)
{
	return s1.size() < s2.size();
}

bool GT6(const string& s)
{
	return s.size() >= 6;
}

int main(void)
{
	vector<string> word {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
	vector<string>::size_type wc = 0;

	auto iter = word.begin();
	while((iter = find_if(iter, word.end(), GT6)) != word.end())
	{
		++wc;
		++iter;
	}
	cout << wc << endl;
	return 0;
}
