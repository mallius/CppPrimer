
#ifndef SCREEN5_H
#define SCREEN5_H
#include <string>
#include <iostream>

class Screen {
public:
// interface member functions
    typedef std::string::size_type index;
    char get() const { return contents[cursor]; }
    inline char get(index ht, index wd) const;
    Screen(index ht = 0, index wd = 0): 
       contents(ht * wd, ' '), cursor(0), height(ht), width(wd), access_ctr(0) { }
    Screen& move(index r, index c) 
              { do_move(r, c); return *this; }
    const Screen& move(index r, index c) const 
              { do_move(r, c); return *this; }
private:
    void do_move(index r, index c) const;
    void do_display(std::ostream &os) const;
public:
    Screen& set(char);
    Screen& set(index, index, char);
    const Screen& display(std::ostream& os) const;
    // as before
private:
    mutable size_t access_ctr; // may change in a const members
    // other data members as before
    std::string contents;
    index cursor;  
    index height, width;
};

void Screen::do_display(std::ostream& os) const
{	
	++access_ctr;    // keep count of calls to any member function
	os << contents;
}

Screen& Screen::set(char c) 
{ 
	contents[cursor] = c; 
	return *this; 
}

Screen& Screen::set(index r, index c, char ch)
{
	index row = r * width; // row location
	contents[row + c] = ch;
	return *this;
}

char Screen::get(index r, index c) const
{
	index row = r * width; // row location
	return contents[row + c];
}
#endif
