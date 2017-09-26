#include <stack>
#include <iostream>

using namespace std;

int main(void)
{
	string temp;
	int ix = 0;
	int flag = 0;
	stack<string> st;

	while(cin >> temp && temp != ")")
	{
		st.push(temp);	
		if(temp == "(")
			flag = 1;
		if(flag == 1)
			ix++;
	}
	while(ix > 0)
	{
		st.pop();
		ix--;
	}
	cout << st.top() << endl;
	return 0;
}
