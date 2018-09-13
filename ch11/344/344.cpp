#include <vector>
#include <iostream>
#include <algorithm>
#include "mk_plural2.h"

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
	vector<string> word;
	word.push_back("the");
	word.push_back("quick");
	word.push_back("red");
	word.push_back("fox");
	word.push_back("jumps");
	word.push_back("over");
	word.push_back("the");
	word.push_back("slow");
	word.push_back("red");
	word.push_back("turtle");
	word.push_back("sevenseven");

	for(vector<string>::iterator it = word.begin(); it != word.end(); ++it)
	{
		cout << *it  << " ";
	}
	cout << endl;

	// 1.sort
	sort(word.begin(), word.end());

	for(vector<string>::iterator it = word.begin(); it != word.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	// 2.unique, erase
	vector<string>::iterator end_unique = unique(word.begin(), word.end());
	word.erase(end_unique, word.end());

	for(vector<string>::iterator it = word.begin(); it != word.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	// 3.stable_sort
	stable_sort(word.begin(), word.end(), isShorter);

	for(vector<string>::iterator it = word.begin(); it != word.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	// 4.count_if 
	vector<string>::size_type wc = count_if(word.begin(), word.end(), GT6);
	cout << wc << " "<< make_plural(wc, "word", "s") << " 6 characters or longer" << endl;
	return 0;
}
