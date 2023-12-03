#ifndef __QUEUE_H__
#define __QUEUE_H__
#include <stdexcept>


template <typename T>
class MyQueue
{
private:
    struct MyNode
    {
        T value; // ������
        MyNode* next;
        MyNode(T value) : value(value), next(nullptr) {}
    };
    MyNode* front;
    MyNode* end;
    int count;
public:
    MyQueue() : front(nullptr), end(nullptr), count(0) {}
    ~MyQueue();
    void push(const T& element); //  ��������� ����� ������� � ����� �������.
    T pop(); // ������� � ���������� ������� �� ������ �������.
    bool isEmpty() const; // ���������, ����� �� �������(���������� true, ���� front ����� nullptr, ����� false).
    int getSize() const; // ���������� ������� ���������� ��������� � ������� (�������� ���������� count).
    const T& frontValue() const; //���������� �������� �������� � ������ �������, �� �� ������� ���.
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
void MyQueue<T>::push(const T& element) // ����� �������, ����� push ��������� ����� ������� � ����� �������, �������� ��������� front � end, � ����� ���������� ������� ���������.
{
    MyNode* newNode = new MyNode(element); // ��������� ����� ���� � ������ newNode, ������� �������� ���������� � ����� ������� element. 
    //���������� ����������� MyNode, ������� ������������� ���� value ������ ���� ������ element, � ���� next ������ nullptr.
    if (end)
    {
        end->next = newNode;
    }
    end = newNode;
    // �����������, �� �������� �� ������� ������. ���� end �� ����� nullptr, ������, ������� �� �����.
    // ���� ������� �� �����, �� ��������� next ���������� ���� (end->next) ��������������� �� ����� ���� (newNode).
    // ��� ��������� ������� ��������� ���� � ����� �����, �������� ��� � ����� �������.
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
    T value = front->value;// ���������� �������� ������ ������� ���� � ���������� value
    temp = front;// �������� ���������� ��������� �� ������ ����
    front = front->next; // ���������� ��������� front, ����� �� �������� �� ��������� ���� � �������
    if (!front)
    {
        end = nullptr;  // ���� ����� �������� �������� ������� ���������� ������  // ���������� ��������� end �� nullpt
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
