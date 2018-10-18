#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(void)
{
	map<string, size_t> word_count;
	string word("word");

	word_count.insert({word, 1});
	word_count.insert(make_pair(word, 1));
	word_count.insert(pair<string, size_t>(word, 1));
	word_count.insert(map<string, size_t>::value_type(word, 1));

	return 0;
}
