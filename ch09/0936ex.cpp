#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main(void)
{
	vector<char> cvec(10, 'a');
	for(vector<char>::iterator cit = cvec.begin(); cit != cvec.end(); ++cit)
	{
		cout << *cit << endl;
	}
	string str(cvec.begin(), cvec.end());
	cout << str << endl;
	return 0;
}
