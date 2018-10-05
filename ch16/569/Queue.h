#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <iostream>

template <class Type> class Queue;
template <class T> std::ostream& operator<<(std::ostream&, const Queue<T>& );

template <class Type> class QueueItem
{
	friend class Queue<Type>;							// 一个实例为友元(Type)，事先声明
	friend std::ostream& operator<< <Type> (std::ostream&, const Queue<Type>&); //一个实例为友元(Type)，事先声明
	
	QueueItem(const Type &t): item(t), next(0) { }	  
	Type item;
	QueueItem *next;
};

template <class Type> class Queue
{
	friend std::ostream& operator<< <Type> (std::ostream&, const Queue<Type>&);
public:
	// 构造函数为一个函数模板，有自己的类型It
	template <class It>
	Queue(It beg, It end):
			head(0), tail(0) { copy_elems(beg, end); }

	// 普通的构造函数
	Queue(): head(0), tail(0) { }
	Queue(const Queue &Q): head(0), tail(0) { copy_elems(Q); }
	Queue& operator=(const Queue&);
	~Queue() { destroy(); }
	Type& front() { return head->item; }
	const Type& front()const { return head->item; }
	void push(const Type &);
	void pop(); 
	bool empty() const { return head == 0; }

	// 成员函数为一个函数模板，有自己的类型Iter
	template <class Iter> void assign(Iter, Iter);

private:
	QueueItem<Type> *head;
	QueueItem<Type> *tail;
	void destroy();
	void copy_elems(const Queue&);

	// 成员函数为一个函数模板，有自己的类型Iter
	template <class Iter> void copy_elems(Iter, Iter);	
};



/*** 特化成员，而不是特化类 ***/
/*** template <> class Queue<const char*> {
public:	
	void push(const char*);
	void pop() { real_queue.pop(); }
	bool empty() const { return real_queue.empty(); }
	std::string front() { return real_queue.front(); }
	const std::string& front() const { return real_queue.front(); }
private:
	Queue<std::string> real_queue;
}; ***/

#include "Queue.cpp"  // 包含编译

#endif



