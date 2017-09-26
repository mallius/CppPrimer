#ifndef __Screen_h__
#define __Screen_h__

#include <string>

class Screen
{
public:
	// interface member functions
	typedef std::string::size_type index;

	char get()const
	{ 
		return contents[cursor]; 
	}

	//inline
	inline char get(index ht, index wd)const;
	//inline later
	index get_cursor() const;

private:
	std::string contents;
	index cursor;
	index height, width;
};

char Screen::get(index r, index c)const
{
	index row = r * width;
	return contents[row+c];
}

inline Screen::index Screen::get_cursor()const
{
	return cursor;
}

#endif
