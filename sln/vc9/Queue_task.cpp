#pragma once
struct Task
{
	int time=0;
	int number_of_nodes=0;
};
struct Node {
	Task date;
	Node* pNext;
	Node(Task _val) : date(_val), pNext(nullptr) {}
	Task GetDate() { return date; }
};

class Queue_task
{
	size_t size = 0;
	Node* pFirst=nullptr;
	Node* pLast=nullptr;
public:
	Node* Pop() {
		Node* tmp;
		if (pFirst == nullptr)
			throw "No elements on Queue";
		tmp = pFirst;
		pFirst = pFirst->pNext;
		size--;
		return tmp;
	}
	void Push(Task new_task) {
		Node* tmp1 = new Node(new_task);
		size++;
		if (pFirst == nullptr) {
			pFirst = tmp1;
			pLast = tmp1;
			return;
		}
		pLast->pNext = tmp1;
		pLast = tmp1;
	}
	Task WatchFirst() { return pFirst->date; }
	size_t GetSize() { return size; }
};

