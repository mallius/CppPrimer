#include "Screen.h"

template <int hi, int wid>
std::ostream& operator<<(std::ostream& os, const Screen<hi, wid>& s)
{
	os << "[" << s.height <<"|" << s.width << "|" << s.cursor;
	os << "]";
	return os;
}
