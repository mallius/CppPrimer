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

class Bar
{
private:
	static int ival;
	static Foo fval;
};
