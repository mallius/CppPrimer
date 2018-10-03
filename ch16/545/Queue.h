#ifndef __QUEUE_H__
#define __QUEUE_H__

template <class Type> class Queue;

template <class Type> class QueueItem
{
	friend class Queue<Type>;
	QueueItem(const Type &t): item(t), next(0) { }	  
	Type item;
	QueueItem *next;
};

template <class Type> class Queue
{
public:
	// empty Queue 
	Queue(): head(0), tail(0) { }
	Queue(const Queue &Q): head(0), tail(0) { copy_elems(Q); }
	Queue& operator=(const Queue&);
	~Queue() { destroy(); }
	Type& front() { return head->item; }
	const Type& front()const { return head->item; }
	void push(const Type &);
	void pop(); 
	bool empty() const { return head == 0; }

private:
	QueueItem<Type> *head;
	QueueItem<Type> *tail;
	void destroy();
	void copy_elems(const Queue&);
};

#include "Queue.cpp"  // 包含编译

#endif
