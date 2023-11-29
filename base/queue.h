#pragma once

const int MaxQueueSize = 100;
const int MinQueueSize = 5;


template <class T>
class TQueue {
	int begin; // индекс начала
	int end; //индекс конца
	size_t size;
	T* pMem;
	int cnt; //количество элементов в очереди

public:
	TQueue() {
		begin = 0;
		end = 0;
		size = 0;
		cnt = 0;
		pMem = new T[size];
	}

	~TQueue() {
		delete[] pMem;
	}

	TQueue(size_t s) {
		if (s < MinQueueSize || s > MaxQueueSize)
			throw "Incorrect queue size";
		size = s;
		begin = 0;
		end = 0;
		cnt = 0;
		pMem = new T[size];
	}

	bool IsEmpty() {
		return cnt == 0;
	}

	bool IsFull() {
		return cnt == (size - 1);
	}

	size_t GetSize() {
		return cnt;
	}

	void Push(T val) {
		if (IsFull())
			throw "Queue is full";
		pMem[end++] = val;
		cnt++;
		end %= size;
	}

	T Pop() {
		if (IsEmpty()) {
			throw "Queue is empty";
		}
		T tmp = pMem[begin];
		begin = (begin + 1) % size;
		cnt--;
		return tmp;
	}

	T ViewFirst() {
		if (IsEmpty()) {
			throw "Queue is empty";
		}
		return pMem[begin];

	}


};