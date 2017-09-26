#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int main(void)
{
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(3);
	vec.push_back(5);
	vec.push_back(7);
	vec.push_back(42);
	int sum = accumulate(vec.begin(), vec.end(), 0); 
	cout << sum << endl;
	
	return 0;
}
