//模板方法
#include <iostream>
using namespace std;

//PC机，手机，平板
class MakeOrder {
public:
	//virtual void startOrder() =0;第一版
	//钩子函数的模板方法
	virtual void startOrder() {
		cout << "MakeOrder starOrder" << endl;
	}
	virtual void replyStart()=0;
	//.....
	virtual void finishOrder()=0;
	virtual void replyFinish()=0;
	//模板模式
	void make() {
		startOrder();
		replyStart();
		finishOrder();
		replyFinish();
	}
protected:
	MakeOrder(){}
};

class Fanuc :public MakeOrder {
public:
	void startOrder() {
		cout << "Fanuc: starOrder" << endl;
	}
	void replyStart() {
		cout << "Fanuc: replyStart" << endl;
	}
	//.....
	 void finishOrder() {
		 cout << "Fanuc: finishOrder" << endl;
	}
	 void replyFinish() {
		 cout << "Fanuc: replyFinish" << endl;
	 }
};

class Sims :public MakeOrder {
public:
	void startOrder() {
		cout << "Sims: startOrder" << endl;
	}
	void replyStart() {
		cout << "Sims: replyStart" << endl;
	}
	//.....
	void finishOrder() {
		cout << "Sims: finishOrder" << endl;
	}
	void replyFinish() {
		cout << "Sims: replyFinish" << endl;
	}
};

class Mits :public MakeOrder {
public:
	
	void replyStart() {
		cout << "Mits: replyStart" << endl;
	}
	//.....
	void finishOrder() {
		cout << "Mits: finishOrder" << endl;
	}
	void replyFinish() {
		cout << "Mits: replyFinish" << endl;
	}
};

int main(void) {
	MakeOrder* p= new Fanuc;
	p->make();
	MakeOrder* pMakeOrder = new Mits;
	pMakeOrder->make();
	return 0;
}