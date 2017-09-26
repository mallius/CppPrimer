ifstream inFile("test.txt");

class Foo
{
public:
	Foo():sval("Noname"), ival(0), dval(0), infile(inFile){}
private:
	const string sval;
	int ival;
	double *dval;
	ifstream& infile;

};
