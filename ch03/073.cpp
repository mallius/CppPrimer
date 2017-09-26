#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	string st("The\n");
	cout << "The size of " << st << "is " << st.size()
		<< " characters, including the newline" << endl;

	string::size_type len = st.size();
	cout << "st.size(): " << len << endl;
	return 0;
}
