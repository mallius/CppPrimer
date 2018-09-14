#include <iostream>
#include <fstream>
#include <iterator>

using namespace std;

int main(void) 
{
	ofstream oddFile("odd.txt");
	ofstream evenFile("even.txt");

	istream_iterator<int> in_iter(cin);
	istream_iterator<int> eof;
	ostream_iterator<int> oddFile_iter(oddFile, " ");
	ostream_iterator<int> evenFile_iter(evenFile, "\n");

	while(in_iter != eof)
	{
		if(*in_iter%2 != 0)//odd 
		{
			*oddFile_iter = *in_iter;
			++oddFile_iter;
		}
		else 
		{
			*evenFile_iter = *in_iter;
			++evenFile_iter;
		}
		++in_iter;
	}
	oddFile.close();
	evenFile.close();
	return 0;
}
