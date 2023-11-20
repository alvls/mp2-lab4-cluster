#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "linked_list.h"

using namespace std;

template<class TELEM>
class Queue {
	LinkedList<TELEM> data;
public:
	Queue();
	void add(const TELEM& el);
	TELEM get();
	TELEM operator[](const size_t index);
	size_t size();
	TELEM& first();
	TELEM& last();
	inline bool empty();
};

template<class TELEM>
inline Queue<TELEM>::Queue(){}

template<class TELEM>
void Queue<TELEM>::add(const TELEM& el) { data.push_back(el); }

template<class TELEM>
TELEM Queue<TELEM>::get() { TELEM res = data.get_front(); data.pop_front(); return res; }

template<class TELEM>
TELEM Queue<TELEM>::operator[](const size_t index) { return data[index]; }

template<class TELEM>
inline size_t Queue<TELEM>::size() { return data.get_size(); }

template<class TELEM>
inline bool Queue<TELEM>::empty(){	return size() == 0; }

template<class TELEM>
inline TELEM& Queue<TELEM>::first() { return data.get_front(); }

template<class TELEM>
inline TELEM& Queue<TELEM>::last() { return data.get_back(); }

#endif