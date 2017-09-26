#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::string;
using std::cin;

int main(void)
{
	string word;
	vector<string> text;
	int i = 0;
	while(cin >> word)
	{
		text.push_back(word);
		if(++i > 2)
			break;
	}
	
	for(vector<string>::size_type ix = 0; ix != text.size(); ++ix)
		std::cout << text[ix] << std::endl;

	return 0;
}
