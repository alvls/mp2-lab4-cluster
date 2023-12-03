#ifndef __QUEUE_H__
#define __QUEUE_H__
#include <stdexcept>


template <typename T>
class MyQueue
{
private:
    struct MyNode
    {
        T value; // данные
        MyNode* next;
        MyNode(T value) : value(value), next(nullptr) {}
    };
    MyNode* front;
    MyNode* end;
    int count;
public:
    MyQueue() : front(nullptr), end(nullptr), count(0) {}
    ~MyQueue();
    void push(const T& element); //  добавляет новый элемент в конец очереди.
    T pop(); // удаляет и возвращает элемент из начала очереди.
    bool isEmpty() const; // проверяет, пуста ли очередь(возвращает true, если front равен nullptr, иначе false).
    int getSize() const; // возвращает текущее количество элементов в очереди (значение переменной count).
    const T& frontValue() const; //возвращает значение элемента в начале очереди, но не удаляет его.
};
template <typename T>
MyQueue<T>::~MyQueue()
{
    while (!isEmpty())
    {
        pop();
    }
}
template <typename T>
void MyQueue<T>::push(const T& element) // Таким образом, метод push добавляет новый элемент в конец очереди, обновляя указатели front и end, а также увеличивая счетчик элементов.
{
    MyNode* newNode = new MyNode(element); // Создается новый узел с именем newNode, который содержит переданный в метод элемент element. 
    //Вызывается конструктор MyNode, который устанавливает поле value нового узла равным element, а поле next равным nullptr.
    if (end)
    {
        end->next = newNode;
    }
    end = newNode;
    // Проверяется, не является ли очередь пустой. Если end не равно nullptr, значит, очередь не пуста.
    // Если очередь не пуста, то указатель next последнего узла (end->next) устанавливается на новый узел (newNode).
    // Это связывает текущий последний узел с новым узлом, добавляя его в конец очереди.
    if (!front)
    {
        front = newNode;
    }
    count++;
}
template <typename T>
T MyQueue<T>::pop()
{
    if (isEmpty())
    {
        throw std::out_of_range("Queue is empty");
    }
    MyNode* temp = front;
    T value = front->value;// Сохранение значения данных первого узла в переменной value
    temp = front;// Создание временного указателя на первый узел
    front = front->next; // Обновление указателя front, чтобы он указывал на следующий узел в очереди
    if (!front)
    {
        end = nullptr;  // Если после удаления элемента очередь становится пустой  // обновление указателя end на nullpt
    }
    delete temp;
    count--;
    return value;
}
template <typename T>
bool MyQueue<T>::isEmpty() const
{
    return front == nullptr;
}
template <typename T>
int MyQueue<T>::getSize() const
{
    return count;
}
template <typename T>
const T& MyQueue<T>::frontValue() const {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    return front->value;
}
#endif
