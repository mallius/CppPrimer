//
// Created by yuyawei on 18/9/4.
//

#ifndef BOOK_BOOK_H
#define BOOK_BOOK_H
#include <iostream>
using namespace std;

class Book{
    friend ostream& operator<<(ostream& os , Book& book);
private:
    string name;
public:
    Book(string n):name(n){ }

};

#endif //BOOK_BOOK_H
