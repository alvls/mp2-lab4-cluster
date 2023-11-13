#ifndef __LINKED_LIST__
#define __LINKED_LIST__

#include <stdexcept>

using namespace std;

template <class TELEM>
class LinkedList {
	class Node {
		Node* next, * prev;
		TELEM data;
	public:
		Node() = delete;
		Node(TELEM d) : datd(d) {next = prev = nullptr;}
	};
private:
	Node* front, * back;
public:
	LinkedList();
	~LinkedList();
	void empty();
	void push_front(TELEM el);
	void push_back(TELEM el);
	void pop_front();
	void pop_back();
	Node* get_front() const;
	Node* get_back() const;
	void erase(size_t index);
	void insert(size_t index, TELEM el);
	Node* operator[](const size_t index);
};

template <class TELEM>
LinkedList<TELEM>::LinkedList() { front = back = nullptr; }

template <class TELEM>
void LinkedList<TELEM>::empty() { return (front == nullptr && back == nullptr); }

template <class TELEM>
void LinkedList<TELEM>::push_front(TELEM el) {
	Node* tmp = new Node(el);
	tmp->next = front;
	if (front != nullptr)
		front->prev = ptr;
	if (back == nullptr)
		back = ptr;
	front = ptr;
}

template <class TELEM>
void LinkedList<TELEM>::push_back(TELEM el) {
	Node* tmp = new Node(el);
	tmp->prev = back;
	if (back != nullptr)
		back->next = tmp;
	if (front == nullptr)
		front = tmp;
	back = tmp;

}

template <class TELEM>
void LinkedList<TELEM>::pop_front() {
	if (empty()) throw out_of_range("List is empty");
	Node* tmp = front->next;
	if (tmp != nullptr)
		tmp->prev = nullptr;
	else
		back = nullptr;
	delete front;
	front = tmp;
}

template <class TELEM>
void LinkedList<TELEM>::pop_back() {
	if (empty()) throw out_of_range("List is empty");
	Node* tmp = back->prev;
	if (tmp != nullptr)
		tmp->next = nullptr;
	else
		front = nullptr;
	delete back;
	back = tmp;
}

template <class TELEM>
LinkedList<TELEM>::Node* LinkedList<TELEM>::get_front() const { return front; }

template <class TELEM>
LinkedList<TELEM>::Node* LinkedList<TELEM>::get_back() const { return back; }

template <class TELEM>
void LinkedList<TELEM>::erase(size_t index) {
	Node* tmp = *this[index];
	if (tmp == nullptr) return;
	if (tmp->prev == nullptr) {
		pop_front();
		return;
	}
	else if (tmp->next == nullptr){
		pop_back();
		return;
	}
	Node* left = tmp->prev;
	Node* right = tmp->next;
	left->next = right;
	right->prev = left;
	delete tmp;
}

template <class TELEM>
void LinkedList<TELEM>::insert(size_t index, TELEM el) {
	Node* right = *this[index];
	if (right == nullptr)
		push_back(el);
	Node* left = right->prev;
	if (left == nullptr)
		push_front(el);
	Node* tmp = new Node(el);
	tmp->next = right;
	tmp->prev = left;
	left->next = tmp;
	right->prev = tmp;
}

template <class TELEM>
LinkedList<TELEM>::Node* LinkedList<TELEM>::operator[](const size_t index) {
	Node* tmp = front;
	for (size_t i = 0; i != index; i++) {
		if (tmp == nullptr)
			return tmp;
		tmp = tmp->next;
	}
	return tmp;
}

template <class TELEM>
LinkedList<TELEM>::~LinkedList() { }
#endif