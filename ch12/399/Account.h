#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__
#include <string>
class Account
{
public:
	void applyint(){amount += amount * interestRate;}
	static double rate(){return interestRate;}
	static void rate(double r){interestRate = r;}
private:
	std::string owner;
	double amount;
	static double interestRate;
	//static double initRate();
};

#endif
