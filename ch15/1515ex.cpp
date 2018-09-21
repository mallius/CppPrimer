#include <iostream>
using namespace std;

class Book {
public:
	Book(double d=1): bookDiscount(d) {  }
protected:
	double bookDiscount;
};

class AudioBook : public Book {
public:
	AudioBook(double d1=1, double d2=1): Book(d1), audioBookDiscount(d2) {  }
protected:
	double audioBookDiscount;

};

class CdromBook : public AudioBook {
public:
	CdromBook(double d1=1, double d2=1, double d3=1): AudioBook(d1, d2), cdromBookDiscount(d3) {  }
	double totalDiscount() const { return cdromBookDiscount * audioBookDiscount * bookDiscount; }
protected:
	double cdromBookDiscount;
};


int main(void)
{
	CdromBook cd(0.8, 0.7, 0.1);
	cout << cd.totalDiscount() << endl;
	return 0;
}
