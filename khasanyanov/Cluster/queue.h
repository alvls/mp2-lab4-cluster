#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "linked_list.h"

using namespace std;

template<class TELEM>
class Queue {							   
	LinkedList<TELEM> data;				  // данные 
public:									  
	Queue();							  // конструктор по умолчанию
	void add(const TELEM& el);			  // добавить элемент (в конец очереди)
	TELEM get();						  // получить елемент (первый из очереди)
	TELEM operator[](const size_t index); // получить значение элемента по индексу
	size_t size();						  // получить размер очереди (кол-во элементов)
	TELEM& first();						  // ссылка на первый элемент
	TELEM& last();						  // ссылка на последний элемент
	inline bool empty();                  // проверка на отсутствие элементов в очереди
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