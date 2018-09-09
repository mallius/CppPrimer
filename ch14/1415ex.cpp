#include <iostream>
#include <vector>
using namespace std;

struct Date {
    string date;
    Date& operator=(Date& d) { date = d.date; return *this; }
};

class CheckoutRecord {
public:
    double get_bookId() { return book_id;}
    double set_bookId(double id = 0.00) { book_id = id; }
    CheckoutRecord& operator=(CheckoutRecord& cr);
private:
    double book_id;
    string title;
    Date date_borrowed;
    Date date_due;
    pair<string, string> borrower;
    vector< pair<string, string>* > wait_list;
};

CheckoutRecord& CheckoutRecord::operator=(CheckoutRecord& cr)
{
    book_id = cr.book_id;
    title = cr.title;
    date_borrowed = cr.date_borrowed;
    date_due = cr.date_due;
    borrower = cr.borrower;
    wait_list.clear();
    for(auto it = wait_list.begin(); it != wait_list.end(); ++it){
        auto *ppa = new pair<string, string>;
        *ppa = **it;
        wait_list.push_back(ppa);
    }

    return *this;
}

int main(void)
{
    CheckoutRecord cra, crb;
    cra.set_bookId(100.01);
    crb = cra;
    cout << crb.get_bookId() << endl;
}