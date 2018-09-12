#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
	vector<string> shortestWord, longestWord;
	string::size_type lenMin = 0;
	string::size_type lenMax = 0;
	string::size_type cnt = 0;

	string line1 = "We were her pride of 10 she named us:";
	string line2 = "Benjamin, Phoenix, the Prodigal";
	string line3 = "and perspicacious pacific Suzanne";

	string sentence = line1 + ' ' + line2 + ' ' + line3;
	string sep(" :,");

	string::size_type startPos = 0;
	string::size_type endPos = 0;

	while((startPos = sentence.find_first_not_of(sep, endPos)) != string::npos)
	{
		if((endPos = sentence.find_first_of(sep, startPos)) != string::npos)
		{
			if(cnt==0)
			{
				lenMin = endPos - startPos;
				lenMax = endPos - startPos;
			}
			else 
			{
				if(endPos-startPos < lenMin)
					lenMin = endPos - startPos;
				if(endPos-startPos > lenMax)
					lenMax = endPos - startPos;
			}
		}
		startPos += (endPos-startPos);
		endPos = startPos;
		cnt++;
	}	
	cout << "lenMin: " << lenMin << endl;
	cout << "lenMax: " << lenMax << endl;
	cout << "Word Count: " << cnt << endl;
	return 0;
}
