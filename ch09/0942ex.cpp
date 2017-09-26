#include <stack>
#include <iostream>

using namespace std;

int main(void)
{
	string temp;
	stack<string> st;

	cin >> temp;
	st.push(temp);
	cin >> temp;
	st.push(temp);
	cin >> temp;
	st.push(temp);
	cout << "Last is: " << st.top() << endl;
	return 0;
}
