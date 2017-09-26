struct NoName
{
	NoName(): pstring(new std::string), i(0), d(0){}
	NoName(const & NoName);
	~NoName()
	{
		delete pstring;
	}
private:
	std::string *pstring;
	int i;
	double d;
};
