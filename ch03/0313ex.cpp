#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
int main(void)
{
	vector<int> ivec;
	int ival;
	for(int i = 1; i <= 5; ++i)
	{
		ival = i;
		ivec.push_back(ival);
	}
	if(ivec.size() % 2 != 0)
	{
		cout << "Last: " << ivec[ivec.size()-1] << endl;
	}
	for(vector<int>::size_type ix = 0; ix < ivec.size(); ix+=2)
	{
		cout << ivec[ix]+ivec[ix+1] << " " ;
		if(ix+2>=ivec.size()-1 && ivec.size() % 2 !=0)
			break;
	}
	cout << endl;
	
	if(ivec.size()%2 != 0)
	{
		cout << "Mid: " << ivec[ivec.size()/2] << endl;
	}
	for(vector<int>::size_type ix = 0; ix <= ivec.size()/2; ++ix)
	{
		if(ix+1<=ivec.size()/2)
			cout << ivec[ix] + ivec[ivec.size()-1-ix] << " ";
			
	}
	cout << endl;

	return 0;
}
