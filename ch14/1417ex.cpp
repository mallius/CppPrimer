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
    void set_bookId(double id = 0.00) { book_id = id; }
    void set_wait_list(pair<string, string>& wait);

    CheckoutRecord& operator=(CheckoutRecord& cr);
    pair<string, string>& operator[](const size_t);
    const pair<string, string>& operator[](const size_t) const;
private:
    double book_id;
    string title;
    Date date_borrowed;
    Date date_due;
    pair<string, string> borrower;
    vector< pair<string, string>* > wait_list;
};

void CheckoutRecord::set_wait_list(pair<string, string> &wait)
{
   auto *ppa = new pair<string, string>;
    *ppa = wait;
    wait_list.push_back(ppa);
}

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

pair<string, string>& CheckoutRecord::operator[](const size_t index)
{
    pair<string, string> spair;
    pair<string, string>* sp = wait_list[index];
    spair.first = sp->first;
    spair.second = sp->second;
    return spair;
}

const pair<string, string>& CheckoutRecord::operator[](const size_t index) const
{
    pair<string, string> spair;
    pair<string, string>* sp = wait_list[index];
    spair.first = sp->first;
    spair.second = sp->second;
    return spair;
}

int main(void)
{
    CheckoutRecord cra, crb;
    pair<string, string> pa("abc","def");
    pair<string, string> ret;

    cra.set_bookId(100.01);
    cra.set_wait_list(pa);

    ret.first = cra[0].first;
    ret.second = cra[0].second;

    cout << ret.first << endl;
    cout << ret.second << endl;

    //crb = cra;
    //cout << crb.get_bookId() << endl;

}