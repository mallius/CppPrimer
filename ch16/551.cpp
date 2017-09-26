template<int hi, int wid>
class Screen
{
public:
	Screen(): screen(hi * wid, '#'), cursor(0),
				height(hi), width(wid){  }
private:
	std::string screen;
	std::string::size_type cursor;
	std::string::size_type height, width;
};
