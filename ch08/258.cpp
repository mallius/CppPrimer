#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <limits>
#include <string>
#include <cstring>

using namespace std;

int main(void)
{
	//2.stringstream提供的转换和/或格式化
	int val1 = 512, val2 = 1024;
	ostringstream format_message;
	format_message << "val1: " << val1 << "\n"
				<< "val2: " << val2 << "\n";

	istringstream input_istring(format_message.str());
	string dump;
	input_istring >> dump >> val1 >> dump >> val2;
	cout << val1 << " " << val2 << endl;
	return 0;
}
