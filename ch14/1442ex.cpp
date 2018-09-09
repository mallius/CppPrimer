#include <iostream>
#include <vector>
using namespace std;

struct Date {
    string date;
};

class CheckoutRecord {
public:
    double get_bookId() { return book_id;}
    double set_bookId(double id = 0.00) { book_id = id; }
private:
    double book_id;
    string title;
    Date date_borrowed;
    Date date_due;
    pair<string, string> borrower;
    vector< pair<string, string>* > wait_list;
};

class BoolCheckoutRecord {
public:
    BoolCheckoutRecord(CheckoutRecord check) { r = check; }
    operator bool() { return r.get_bookId(); }
private:
    CheckoutRecord r;
};

int main(void)
{
    CheckoutRecord r;
    r.set_bookId(1.00);
    BoolCheckoutRecord boolreck(r);
    bool ret = bool(boolreck);
    cout << ret << endl;
}