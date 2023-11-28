#include <stack>

using namespace std;


template<typename T>
class TStackQueue {

public:
	TStackQueue() : sz(0) {};

	/* Возращает размер очереди. */
	size_t size() const { return sz; }

	/* Возращает true, если очередь пуста и false, если нет. */
	bool isEmpty() const { return sz == 0; }

	/* Возращает первый элемент очереди. */
	T top() {
		if (rightStack.empty()) {
			while (!leftStack.empty()) {
				rightStack.push(leftStack.top());
				leftStack.pop();
			}
		}
		return rightStack.top();
	}

	/* Добавление элемента в очередь. */
	void push(const T& val) { leftStack.push(val); sz++; }

	/* Удаляет и возращает первый элемент очереди. */
	T pop() {

		if (rightStack.empty())
		{
			while (!leftStack.empty()) { rightStack.push(leftStack.top()); leftStack.pop(); }
		}
		T val = rightStack.top();
		rightStack.pop();
		sz--;
		return val;
	}

private:
	size_t sz;
	stack<T> leftStack;
	stack<T> rightStack;
};