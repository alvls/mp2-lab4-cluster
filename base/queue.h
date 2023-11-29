#ifndef __QUEUE_H__
#define __QUEUE_H__

using namespace std;
#include <stdexcept>
const int MaxSize = 100;


template <class T>
class TQueue
{

   T* pMem;
   size_t DataCounter;
   size_t memSize;
   int first;
   int last;

public:

   TQueue(size_t _size = MaxSize) : memSize(_size)
   {
      if (memSize > MaxSize || memSize < 1)
      {
         throw invalid_argument("Invalid size for the queue");
      }
      first = 0;
      last = memSize - 1;
      DataCounter = 0;
      pMem = new T[memSize];
   }

   TQueue(const TQueue& otherQueue) : DataCounter(otherQueue.DataCounter), memSize(otherQueue.memSize), first(otherQueue.first), last(otherQueue.last), pMem(new T[otherQueue.memSize])
   {
      copy(otherQueue.pMem, otherQueue.pMem + memSize, pMem);
   }

   size_t getSize() { return DataCounter; }

   T PeekFront() const
   {
      if (isEmpty())
      {
         throw out_of_range("Queue is empty");
      }

      return pMem[first];
   }

   bool isEmpty() const { return DataCounter == 0; }

   void Enqueue(const T& value)
   {
      if (DataCounter == memSize) {
         memSize *= 2;
         T* newMem = new T[memSize];
         copy(pMem, pMem + memSize, newMem);
         delete[] pMem;
         pMem = newMem;
      }

      last = (last + 1) % memSize;
      pMem[last] = value;
      DataCounter++;
   }

   T Dequeue()
   {
      if (isEmpty())
      {
         throw out_of_range("Queue is empty");
      }

      T removedItem = pMem[first];
      first = (first + 1) % memSize;
      DataCounter--;

      return removedItem;
   }

   ~TQueue() { delete[]pMem; }

   TQueue& operator=(const TQueue& otherQueue)
   {
      if (*this != otherQueue) {
         if (memSize != otherQueue.memSize) {
            delete[] pMem;
            pMem = new T[otherQueue.memSize];
         }
         memSize = otherQueue.memSize;
         first = otherQueue.first;
         last = otherQueue.last;
         DataCounter = otherQueue.DataCounter;

         copy(otherQueue.pMem, otherQueue.pMem + memSize, pMem);
      }
      return *this;
   }
};
#endif