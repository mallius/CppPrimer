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

class Bar2
{
public:
	Foo FooVal()
	{
		callsFooval++;
		return fval;
	}
private:
	static int ival;
	static Foo fval;
	static int callsFooval;
};

int Bar2::ival = 20;
Foo Bar2::fval(0);
int Bar2::callsFooval = 0;
