#include <gtest.h>
#include "queue.h"

TEST(QueueTest, NewlyCreatedQueueIsEmpty) {
	Queue<int> queue;
	EXPECT_TRUE(queue.isEmpty());
}

TEST(QueueTest, SizeIsCorrectAfterEnqueue) {
	Queue<int> queue;
	queue.enqueue(1);
	queue.enqueue(2);
	EXPECT_EQ(2, queue.getSize());
}

TEST(QueueTest, PeekReturnsFrontElement) {
	Queue<int> queue;
	queue.enqueue(1);
	queue.enqueue(2);
	EXPECT_EQ(1, queue.peek());
}

TEST(QueueTest, DequeueDecreasesSize) {
	Queue<int> queue;
	queue.enqueue(1);
	queue.enqueue(2);
	EXPECT_EQ(2, queue.getSize());
	queue.dequeue();
	EXPECT_EQ(1, queue.getSize());
}

TEST(QueueTest, DequeueReturnsFrontElement) {
	Queue<int> queue;
	queue.enqueue(1);
	queue.enqueue(2);
	EXPECT_EQ(1, queue.dequeue());
}

TEST(QueueTest, DequeueThrowsWhenQueueIsEmpty) {
	Queue<int> queue;
	EXPECT_THROW(queue.dequeue(), std::out_of_range);
}

TEST(QueueTest, PeekThrowsWhenQueueIsEmpty) {
	Queue<int> queue;
	EXPECT_THROW(queue.peek(), std::out_of_range);
}