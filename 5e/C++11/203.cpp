#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> process()
{
	return {"functionX", "okay"};
}

int main(void)
{
	vector<string> vs = process();
	for(auto &s : vs) {
		cout << s << endl;
	}
	return 0;
}
