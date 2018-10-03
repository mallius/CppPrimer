template <class T> class A;
template <class T> class B {
	friend class A<T>;                 // 只有一个实例是友元，需要可见
	friend class C;                 
	template <class S> friend class D; // 所有实例都是友元，无需可见
};

int main(void)
{

}
