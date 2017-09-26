#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <map>
#include <set>
#include <fstream>

using namespace std;
void restricted_wc(ifstream &remove_file,
					map<string, int>  &word_count)
{
	set<string> excluded; // set to hold words we'll ignore
	string remove_word;
	while(remove_file >> remove_word)
		excluded.insert(remove_word);
	//read input and keep a count for words that aren't in the exclusion set
	string word;
	while(cin >> word)
		// increment counter only if the word is not in excluded
		if(!excluded.count(word))
			++word_count[word];
}

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		cout << "./a.out filename" << endl;
		return 0;
	}	
	
	map<string, int> mapStringInt;
	//restricted_wc(argv[1], mapStringInt);

	return 0;
}
