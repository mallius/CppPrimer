class Screen{
public:
	typedef std::string::size_type index;
	Screen(string &s, std::string::size_type h, std::string::size_type w);
private:
	std::string contents;
	index cursor;
	index height, width;
};

inline Screen(string &s, std::string::size_type h, std::string::size_type w)
	: contents(s), height(h), width(w)
{

}
