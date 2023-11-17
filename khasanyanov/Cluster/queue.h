#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "linked_list.h"

using namespace std;

template<class TELEM>
class Queue {
	LinkedList<TELEM> queue;
public:
	Queue();
	void add(const TELEM& el);
	TELEM get();
	TELEM operator[](const size_t index);
	size_t size();
	inline bool empty();
};

template<class TELEM>
inline Queue<TELEM>::Queue(){}

template<class TELEM>
void Queue<TELEM>::add(const TELEM& el) { queue.push_back(el); }

template<class TELEM>
TELEM Queue<TELEM>::get() { TELEM res = queue.get_front(); queue.pop_front(); return res; }

template<class TELEM>
TELEM Queue<TELEM>::operator[](const size_t index) { return queue[index]; }

template<class TELEM>
inline size_t Queue<TELEM>::size() { return queue.get_size(); }

template<class TELEM>
inline bool Queue<TELEM>::empty(){	return size == 0;}

#endif