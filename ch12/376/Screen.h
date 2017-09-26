#include <string>
class Screen
{
public:
	typedef std::string::size_type index;
	Screen& move(index r, index c);
	Screen& set(char);
	Screen& set(index, index, char);
};
