//策略模式
#include <iostream>
using namespace std;

//设计思想：我们父类和子类就是一个扩展的关系？是不是合适
//里氏代换原则：子类对象就应该能完全替代父类的行为
//对于继承这样设计，特别小心，我们：组合大于继承
//把quack和fly抽象成为一个对象，那么这个问题就了解决方案

//完成了将“动作”抽象成“对象”
class QuackBehavior 
{
public:
	virtual void quack() = 0;
	virtual ~QuackBehavior() {}
protected:
	QuackBehavior(){} 
};

class FlyBehavior 
{
public:
	virtual void fly() = 0;
	virtual ~FlyBehavior() {}
protected:
	FlyBehavior(){}
};

class FlyWithRocket :public FlyBehavior {
	void fly() {
		cout << "fly Rocket" << endl;
	}
};

class FlyWithWings :public FlyBehavior {
	void fly() {
		cout << "fly Wings" << endl;
	}
};

class FlyWithNoWay :public FlyBehavior {
	void fly() {
		cout << "fly No way" << endl;
	}
};

class ZhiZhiQuack :public QuackBehavior {
public:	void quack() {
	cout << "quack zhizhi" << endl;
	}
};

class PersonQuack :public QuackBehavior {
public:
	void quack() {
		cout << "quack person" << endl;
	}
};

class WigeonQuack :public QuackBehavior {
public:
	void quack() {
		cout << "quack wigeon" << endl;
	}
};

//Duck has a Quack 
//     has a Fly
class Duck 
{
public:
	virtual void Display() = 0;
	virtual ~Duck()
	{
		if(m_pQuack != nullptr)
		{
			delete m_pQuack;
			m_pQuack = nullptr;
		}
		if(m_pFly != nullptr)
		{
			delete m_pFly;
			m_pFly = nullptr;
		}
	}

	void setFlyBehavior(FlyBehavior* fb) 
	{
		m_pFly = fb;
	}

	void setQuackBehavior(QuackBehavior* qb) 
	{
		m_pQuack = qb;
	}

	virtual void perfomrFly() 
	{
		m_pFly->fly();
	}

	virtual void performQuack() 
	{
		m_pQuack->quack();
	}

protected:
	QuackBehavior *m_pQuack;
	FlyBehavior *m_pFly;
private:
};

//DonaladDuck is Duck
class DonaladDuck :public Duck {
public:
	DonaladDuck() {
		m_pFly = new FlyWithRocket;//某一个FlyBehavior的实例
		m_pQuack = new PersonQuack();
	}
	void Display() {
		perfomrFly();
		performQuack();
	}
	
};

//第一个困境：子类似乎不太那么像父类。。。
class RuberDuck : public Duck {
public:
	RuberDuck() {
		m_pFly = new FlyWithNoWay();
		m_pQuack = new ZhiZhiQuack();
	}
	void Display() {
		perfomrFly();
		performQuack();
	}
};

class WigeonDuck : public Duck {
public:
	WigeonDuck() {
		m_pFly = new FlyWithWings;
		m_pQuack = new WigeonQuack;
	}
	void Display() {
		perfomrFly();
		performQuack();
	}
	
};

int main() {
	DonaladDuck *pDonlad = new DonaladDuck;
	pDonlad->Display();
	return 0;
}