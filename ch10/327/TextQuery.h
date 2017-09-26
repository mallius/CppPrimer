#ifndef __TEXTQUERY_H__
#define __TEXTQUERY_H__

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

class TextQuery
{
public:
	//typedef to make declarations easier
	typedef std::vector<std::string>::size_type line_no;
	/* interface:
	 * read_file builds internal data structures for the given file
	 * run_query finds the given word and returns set of lines on which it appears
	 * text_line returns a requested line from the input file
	 */
	void read_file(std::ifstream &is)
	{
		store_file(is);
		build_map();
	}
	std::set<line_no> run_query(const std::string&)const;
	std::string text_line(line_no)const;
private:
	void store_file(std::ifstream&); //store input file
	void build_map();				 //associated each word with a set of line
	
	//remember the whole input file
	std::vector<std::string> lines_of_text;
	//map word to set of the lines on which it occurs
	std::map<std::string, std::set<line_no> > word_map;
};



#endif
