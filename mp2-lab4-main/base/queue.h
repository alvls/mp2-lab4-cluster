#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <algorithm>
using namespace std;
const int MaxSize = 200;

template <class T>
class TQueue
{
	int first;
	int last;
	size_t count;
	size_t MemSize;
	T* pMem;
public:
	TQueue(size_t _size = MaxSize)
	{
		MemSize = _size;
		if ((_size < 1) || (_size > MaxSize))
			throw "invalid size";
		pMem = new T[MemSize];
		count = 0;
		first = 0;
		last = MemSize - 1;
	}
	~TQueue() { delete[]pMem; }
	bool IsEmpty()
	{
		if (count == 0)
			return true;
		return false;
	}
	void Put(const T& val)
	{
		if (count == MemSize)
		{
			T* tmp = new T[MemSize * 2]();
			copy(pMem, pMem + MemSize, tmp);
			delete[] pMem;
			MemSize *= 2;
			pMem = tmp;
		}
		last = (last + 1) % MemSize;
		pMem[last] = val;
		count++;
	}
	T RemoveFirst()
	{
		if (IsEmpty())
			throw "queue is empty";
		T tmp = pMem[first];
		first = (first + 1) % MemSize;
		count--;
		return tmp;
	}
	T GetFirst()
	{
		if (IsEmpty())
			throw "queue is empty";
		return pMem[first];
	}
	size_t GetSize() { return count; }
};
#endif