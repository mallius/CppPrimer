#include <iostream>
#include <fstream>
#include <stdexcept>
#include <limits>
#include <string>
#include <cstring>

using namespace std;

int main(void)
{
	/**
	string ifile = "intext.txt";
	string ofile = "outtext.txt";
	ifstream infile(ifile.c_str());
	ofstream outfile(ofile.c_str());
	**/

	ifstream infile;
	ofstream outfile;
	infile.open("in");
	outfile.open("out");

	//1.检查文件打开是否成功
	if(outfile) //true
	{
		cout << "ok: out is ok" << endl;
	}

	if(!outfile)
	{
		cerr << "error: unable to open output file: "
			<< outfile << endl;
		return -1;
	}

	if(infile)
	{
		cout << "ok: input file is ok" << endl;
	}

	if(!infile)
	{
		cerr << "error: unable to open input file: "
			<< infile << endl;
		return -1;
	}

	//2.将文件流与新文件重新捆绑
	infile.close();
	infile.open("next");
	if(infile)
	{
		cout << "ok: infile open other file [next]" << endl;
	}

	return 0;
}
