struct Base {
	int memfcn() {  };
};

struct Derived : Base {
	int memfcn(int i) {  };
};

int main(void)
{
	Derived d;
	Base b;
	b.memfcn();
	d.memfcn(10);
	d.Base::memfcn();
	// d.memfcn(); 名字已被派生类覆盖无法访问基类成员函数
}
