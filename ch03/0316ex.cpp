#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
int main(void)
{
	vector<int> ivec;
	int ival;
	int sum = 0;
	for(int i = 1; i <= 5; ++i)
	{
		ival = i;
		ivec.push_back(ival);
	}
	int icnt = 0;
	for(vector<int>::iterator it = ivec.begin(); it != ivec.end(); ++it)
	{
		icnt++;
		if(icnt%2 != 0)
		{
			sum = 0;
		}	
		sum += *it;
		if(icnt%2 == 0)
		{
			cout << sum << " ";
		}
		if(icnt==ivec.size())
		{
			cout << endl;
			cout << "Last: " << *it << endl;
		}
	}
	cout << endl;
	
	/*if(ivec.size()%2 != 0)
	{
		cout << "Mid: " << ivec[ivec.size()/2] << endl;
	}
	for(vector<int>::size_type ix = 0; ix <= ivec.size()/2; ++ix)
	{
		if(ix+1<=ivec.size()/2)
			cout << ivec[ix] + ivec[ivec.size()-1-ix] << " ";
			
	}
	cout << endl;
	*/

	return 0;
}

