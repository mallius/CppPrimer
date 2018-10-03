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
