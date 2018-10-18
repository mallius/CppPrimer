#include <iostream>
#include <vector>

class Screen {
public:
	typedef std::string::size_type pos;
	Screen() = default;
	Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c) {  }
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
};

class Window_mgr {
private:
	std::vector<Screen> screens{Screen(24, 80, ' ')};

};

int main(void)
{
	Window_mgr win;
	return 0;
}
