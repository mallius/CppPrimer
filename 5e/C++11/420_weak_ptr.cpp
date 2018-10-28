#include <vector>
#include <iostream>
#include <memory>
using namespace std;

int main(void)
{
	auto p = make_shared<int>(42);
	weak_ptr<int> wp{p};	
    return 0;
}
