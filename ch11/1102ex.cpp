#include <vector>
#include <list>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	string result("42");
	vector<string> vec;
	vec.push_back("1");
	vec.push_back("3");
	vec.push_back("5");
	vec.push_back("7");
	vec.push_back("42");
	int result = count(vec.begin(), vec.end(), search_item);
	cout << result << endl;
	
	return 0;
}
