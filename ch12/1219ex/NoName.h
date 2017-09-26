class NoName
{
public:
	// constructor(s) go here...
	// 1. 无参构造
	// 2. 3个形参的构造
	NoName()
	{

	}
	NoName(string *p, int i, double d): pstring(p), ival(i), dval(d)
	{

	}
private:
	std::string *pstring;
	int ival;
	double dval;
};
