#include <iostream>
#include <stdlib.h>
#include "TextQuery.h"

using namespace std;

ifstream& open_file(ifstream & in, const string & file)
{
	in.close();
	in.clear();
	in.open(file.c_str());
	return in;
}

string make_plural(size_t ctr, const string &word,
								const string &ending)
{
	return (ctr == 1)?word:word+ending;
}

void print_results(const set<TextQuery::line_no>& locs,
				   const string& sought, const TextQuery& file)
{
	//if the word was found, then print count and all occurrences
	typedef set<TextQuery::line_no> line_nums;
	line_nums::size_type size = locs.size();
	cout << "\n" << sought << " occurs "
		<< size << " " 
		<< make_plural(size, "time", "s") << endl;
}


int main(int argc, char **argv)
{
	//open the file from which user will query words
	ifstream infile;
	if(argc < 2||!open_file(infile, argv[1]))
	{
		cerr << "No input file!" << endl;
		return EXIT_FAILURE;
	}
	TextQuery tq;
	tq.read_file(infile);	//builds query map
	//iterate with the user: prompt for a word to find and print results
	//loop indefinitely; the loop 
	while(true)
	{
		cout << "enter word to look for, or q to quit: ";
		string s;
		cin >> s;
		//stop if hit eof on input or a 'q' is entered
		if(!cin || s=="q")
			break;
		//get the set of line numbers on which this word appears
		set<TextQuery::line_no> locs = tq.run_query(s);
		print_results(locs, s, tq);
	}
	return 0;
}
