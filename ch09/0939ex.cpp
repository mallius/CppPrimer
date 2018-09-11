#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<string> svec;
	string word;

	string line1 = "We were her pride of 10 she named us:";
	string line2 = "Benjamin, Phoenix, the Prodigal";
	string line3 = "and perspicacious pacific Suzanne";

	string sentence = line1 + ' ' + line2 + ' ' + line3;
	string del(" :,");
	string::size_type startPos = sentence.find_first_not_of(del);
	string::size_type endPos = sentence.find_first_of(del);

	cout << "startPos: " << startPos << endl;
	cout << "endPos: " << endPos << endl;
	

	return 0;
}
