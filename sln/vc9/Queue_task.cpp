#pragma once
struct Task
{
	int time;
	int number_of_nodes;
};
struct Node {
	Task date;
	Node* pNext;
	Node(Task _val) : date(_val), pNext(nullptr) {}
};

class Queue_task
{
	size_t size = 0;
	Node* pFirst;
	Node* pLast;
public:
	Node* Pop() {
		size--;
		Node* tmp;
		if (pFirst == nullptr)
			throw "No elements on Queue";
		tmp = pFirst;
		pFirst = pFirst->pNext;
		return pFirst;
	}
	void Push(Task new_task) {
		Node* tmp1 = new Node(new_task);
		if (pFirst == nullptr) {
			pFirst = tmp1;
			pLast = tmp1;
		}
		else {
			pLast->pNext = tmp1;
			pLast = tmp1;
		}
		size++;
	}
	Task WatchFirst() { return pFirst->date; }
	size_t GetSize() { return size; }
};

