#include "Queue.h"

template <class Type> void Queue<Type>::destroy()
{
	while(!empty())
		pop();
}

template <class Type> void Queue<Type>::pop()
{
	QueueItem<Type>* p = head;
	head = head->next;
	delete p;
}

template <class Type> void Queue<Type>::push(const Type &val)
{
	QueueItem<Type> *pt = new QueueItem<Type>(val);
	if(empty())
		head = tail = pt;
	else
	{
		tail->next = pt;
		tail = pt;
	}
}

template <class Type> void Queue<Type>::copy_elems(const Queue &orig)
{
	// copy elements from orig into this Queue 
	// loop stops when pt == 0, which happens when we reac orig.tail 
	for(QueueItem<Type> *pt = orig.head; pt; pt = pt->next)
		push(pt->item); // copy the element
}


// 1632ex练习
template <class Type>
Queue<Type>& Queue<Type>::operator=(const Queue<Type>& Q)
{
	destroy();
	copy_elems(Q);
	return *this;	
}

template <class Type>
std::ostream& operator<<(std::ostream& os, const Queue<Type>& q)
{
	os << "[ ";
	QueueItem<Type> *p;
	for(p = q.head; p; p = p->next)
		os << p->item << " ";
	os << "]";
	return os;
}

// 成员函数是函数模板，包含两个模板形参表
template <class T> template <class Iter>
void Queue<T>::assign(Iter beg, Iter end)
{
	destroy();
	copy_elems(beg, end);
}

template <class Type> template <class It>
void Queue<Type>::copy_elems(It beg, It end)
{
	while(beg != end) {
		push(*beg);
		++beg;
	}
}

/*** 类模板的特化，Queue<const char*> ***/
void Queue<const char*>::push(const char* val)
{
	return real_queue.push(val);
}
