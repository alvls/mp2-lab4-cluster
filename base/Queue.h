#pragma once

template <class T>
class Queue
{
	struct Node
	{
		T elem;
		Node* pNext;
	};
	Node* pFirst;
	Node* pLast;
	int size_of;

public:
	Queue();
	Queue(const Queue&) = delete;
	void operator=(const Queue&) = delete;

	bool empty();
	int size();
	void push_back(T elem);
	T get_next();
	T pop();

	~Queue();
};

template <class T>
Queue<T>::Queue() : pFirst(nullptr), pLast(nullptr), size_of(0) {};

template <class T>
Queue<T>::~Queue()
{
	while (!empty())
		pop();
}

template <class T>
bool Queue<T>::empty()
{
	return (size_of < 1);
}

template <class T>
int Queue<T>::size()
{
	return size_of;
}

template <class T>
void Queue<T>::push_back(T elem)
{
	if (pFirst == nullptr)
		pFirst = pLast = new Node{ elem, nullptr };
	else
	{
		pLast->pNext = new Node{ elem, nullptr };
		pLast = pLast->pNext;
	}
	size_of++;
}

template <class T>
T Queue<T>::get_next()
{
	if (empty())
		throw "Queue is empty";

	return pFirst->elem;
}

template <class T>
T Queue<T>::pop()
{
	if (empty())
		throw "Queue is empty";

	size_of--;
	Node* del = pFirst;
	T elem = pFirst->elem;
	pFirst = pFirst->pNext;
	delete del;

	return elem;
}