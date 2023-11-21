#define TQUEUE 
#ifdef TQUEUE

const int MaxQueueSize = 1000;

template<class T> 
class TQueue {
private:

	T* pMem;
	size_t size;
	int front;
	int count;
	int rear;

public:

	TQueue() : size(MaxQueueSize), front(0), count(0), rear(-1) {
		pMem = new T[size]();
	}

	TQueue(size_t _size) {
		if (_size < 0 || _size > MaxQueueSize)
			throw "_size more than MaxQueueSize";
		size = _size;
		front = 0;
		count = 0;
		rear = -1;
		pMem = new T[size]();
	}

	bool IsEmpty() {
		return (Size() == 0);
	}

	bool IsFull() {
		return (Size() == size - 1);
	}

	void enqueue(const T& val){
		if (IsFull()) {
			T* tmp = new T[size*2]();
			std::copy(pMem, pMem + size, tmp);
			delete[] pMem;
			size *= 2;
			pMem = tmp;
		}
		rear = (rear + 1) % size;
		pMem[rear] = val;
		count++;
	}

	T dequeue() {
		if (IsEmpty()) {
			throw "Queue is empty";
		}

		T x = pMem[front];
		
		front = (front + 1) % size;
		count--;

		return x;
	}

	T peek() {
		if (IsEmpty()) {
			throw "Queue is empty";
		}
		return pMem[front];
	}

	size_t Size() {
		return count;
	}

	~TQueue() {
		delete[] pMem;
	}
};
#endif