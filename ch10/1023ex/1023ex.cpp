#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <fstream>
using namespace std;

ifstream& open_file(ifstream & in, const string & file)
{
	in.close();
	in.clear();
	in.open(file.c_str());
	return in;
}

void restricted_wc(ifstream &remove_file,
                   map<string, int> &word_count)
{
	// 打开文件中的单词，依次插入set集合中
	vector<string> excludedstring;
    string remove_word;
    while (remove_file >> remove_word)
	{
		excludedstring.push_back(remove_word);
	}

	// 打印所有vector集合中的单词
    for (vector<string>::iterator vec_it = excludedstring.begin();
                               vec_it != excludedstring.end();
                               ++vec_it)
         cout << *vec_it << endl;

	// 输入单词如果不在排除集vector中，则map值加
    string word;
	cout << "Enter a word, and # for quit" << endl;
conti:
    while (cin >> word && word != "#")
	{
		// 需要遍历   
	   for(vector<string>::iterator itvec = excludedstring.begin(); itvec != excludedstring.end(); itvec++)
	   {
			if(*itvec == word)
			{
				cout << "The word: " << word << " is in the vector" << endl;
				goto conti;
			}
	   }
	   ++word_count[word]; 
	}
}

// call with the name of the exclusion set file
int main(int argc, char **argv) 
{
    ifstream remove_file;
	if(argc != 2)
	{
		cout << "error: ./a.out 1.txt" << endl;
		return -1;
	}
    if(!open_file(remove_file, argv[1]))
	{
		cout << "error can not open file " << argv[1] << endl;
		return -2;
	}
    map<string, int> word_count;
    restricted_wc(remove_file, word_count);
    // get iterator positioned on the first element
    map<string, int>::iterator map_it = word_count.begin();
    // for each element in the map
    while (map_it != word_count.end()) {
        // print the element key, value pairs
        cout << map_it->first << " occurs "
             << map_it->second << " times" << endl;
        ++map_it;  // increment iterator to denote the next element
    }
    return 0;
}

