//
// Created by yuyawei on 18/9/5.
//

#include <iostream>
#include <vector>
using namespace std;
struct Date{
    string date;
};

class CheckoutRecord {
    friend istream& operator>>(istream& in, CheckoutRecord& checkoutRecord);
    friend ostream& operator<<(ostream& out, CheckoutRecord& checkoutRecord);
public:
    //
private:
    double book_id;
    string title;
    Date date_borrowed;
    Date date_due;
    pair<string,string> borrower;
    vector< pair<string, string> *> wait_list;
};

istream& operator>>(istream& in, CheckoutRecord& check)
{
    in >> check.book_id >> check.title >> check.date_borrowed.date >> check.date_due.date;
    if(in)
    {
        in >> check.borrower.first >> check.borrower.second;

    }
    else
    {
        check = CheckoutRecord();
    }
}


ostream& operator<<(ostream& out, CheckoutRecord& check)
{
    cout << check.book_id << endl;
    cout << check.title << endl;
    cout << check.date_borrowed.date << endl;
    cout << check.date_due.date << endl;
    cout << check.borrower.first << endl;
    cout << check.borrower.second << endl;
}

int main(void)
{
    CheckoutRecord check;
    cin >> check;
    cout << check;
}