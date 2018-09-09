//
// Created by yuyawei on 18/9/4.
//
#include "Book.h"

ostream& operator<<(ostream &os, Book &book)
{
    cout << book.name << endl;
    return os;
}
int main(void){
    Book book("book");
    cout << book << endl;
}



