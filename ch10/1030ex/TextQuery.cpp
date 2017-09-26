#include "TextQuery.h"
#include <sstream>

// public methods
std::set<TextQuery::line_no> TextQuery::run_query(const std::string& s)const
{
	map< string, set<line_no> >::const_iterator it = word_map.find(s);
	if(it == word_map.end())
	{
		return set<line_no>();
	}	
	return it->second;
}

std::string TextQuery::text_line(line_no n)const
{
	return lines_of_text[n];
}

// private methods
void TextQuery::store_file(std::ifstream& infile)
{
	string line;
	while(getline(infile, line))
	{
		lines_of_text.push_back(line);
	}

}
void TextQuery::build_map() 
{
	for(line_no cnt = 0; cnt != lines_of_text.size(); ++cnt)
	{
		istringstream isline(lines_of_text[cnt]);
		string word;
		while(isline >> word)
		{
			word_map[word].insert(cnt);
		}
			
	}
}

int main(void)
{

}
