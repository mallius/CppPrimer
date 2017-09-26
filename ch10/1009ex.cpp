#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <map>

using namespace std;
int main(void)
{
	map<string, int> stringInt;
	string temp;
	for(int i = 0; i < 3; i++)
	{
		cin >> temp;
		++stringInt[temp];
	}
	cout << temp << ": " << stringInt[temp] << endl;
	return 0;
}
