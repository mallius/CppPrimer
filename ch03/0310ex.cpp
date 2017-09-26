#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(void)
{
	string temp, result;
	cout << "Enter a string including punctations: ";
	getline(cin, temp);
	
	for(string::size_type index = 0; index != temp.size(); ++index)
	{
		if(!ispunct(temp[index]))
			result = result + temp[index];
	}
	cout << result << endl;

	return 0;
}
