#include <iostream>
using namespace std;
class NoDerived final {  };
class Base {  };
class Last final : Base {  };
// class Bad : NoDerived {  };
// class Bad2 : NoDerived {  };
int main(void)
{

	return 0;
}
