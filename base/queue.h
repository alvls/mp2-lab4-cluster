#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdexcept>

template <typename T>
class Queue {
private:
	struct Node {
		T data;
		Node* next;
		Node(T data) : data(data), next(nullptr) {}
	};
	Node* head;
	Node* tail;
	int size;

public:
	Queue() : head(nullptr), tail(nullptr), size(0) {}
	~Queue();
	void enqueue(const T& element);
	T dequeue();
	bool isEmpty() const;
	int getSize() const;
	const T& peek() const;
};

template <typename T>
Queue<T>::~Queue() {
	while (!isEmpty()) {
		dequeue();
	}
}

template <typename T>
void Queue<T>::enqueue(const T& element) {
	Node* newNode = new Node(element);
	if (tail) {
		tail->next = newNode;
	}
	tail = newNode;
	if (!head) {
		head = newNode;
	}
	size++;
}

template <typename T>
T Queue<T>::dequeue() {
	if (isEmpty()) {
		throw std::out_of_range("Queue is empty");
	}
	Node* temp = head;
	T data = head->data;
	head = head->next;
	if (!head) {
		tail = nullptr;
	}
	delete temp;
	size--;
	return data;
}

template <typename T>
bool Queue<T>::isEmpty() const {
	return head == nullptr;
}

template <typename T>
int Queue<T>::getSize() const {
	return size;
}

template <typename T>
const T& Queue<T>::peek() const {
	if (isEmpty()) {
		throw std::out_of_range("Queue is empty");
	}
	return head->data;
}

#endif