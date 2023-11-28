#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "LinkedList.h"
#include <stdexcept>

template<typename T>
class TQueue : public TLinkedList<T>
{
public:
	T& peek() { return (*this)[0]; };

	T pull()
	{
		if (this->size() == 0)
		{
			throw logic_error("Can't pull the element in empty queue");
		}
		T elem = (*this)[0];
		this->remove(0);
		return elem;
	};
};

#endif