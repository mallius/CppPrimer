#include "Queue.h"
#include <string>
#include <iostream>
using namespace std;

int main(void)
{
	Queue<string> qs;
	qs.push("hello");

	Queue<int> qi;
	short s = 42;
	int i = 42;
	qi.push(s);
	qi.push(i);

	return 0;
}
