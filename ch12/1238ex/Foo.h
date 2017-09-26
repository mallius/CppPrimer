class Foo
{
public:
	Foo(){};
	Foo(int i): ival(i){};
	void getival()const
	{
		return ival;
	}
private:
	int ival;
};

