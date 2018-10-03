#ifndef __SCREEN_H__
#define __SCREEN_H__ 

#include <string>
#include <iostream>

template <int, int> class Screen;
template <int hi, int wid>
std::ostream& operator<<(std::ostream& , const Screen<hi, wid>& );

template<int hi, int wid>
class Screen
{
	friend std::ostream& operator<< <hi, wid> (std::ostream&, const Screen<hi, wid>&);
public:
	Screen(): screen(hi * wid, '#'), cursor(0),
				height(hi), width(wid){  }
private:
	std::string screen;
	std::string::size_type cursor;
	std::string::size_type height, width;
};

#include "Screen.cpp"

#endif

