#include <iostream>
#include <vector>
#include <string>

using namespace std;

pair<string, int> process(vector<string>& v)
{
	if(!v.empty()) {
		return {v.back(), v.back().size()};
	}
	else {
		return pair<string, int>();
	}
}

int main(void)
{
	pair<string, string> author{"James", "Joyce"};
	return 0;
}
