#include <gtest.h>

#include "q.h"

TEST(MyQueue, can_create_queue)
{
    EXPECT_NO_THROW(MyQueue<int> Testqueue());
}
TEST(QueueTest, DequeueReturnsFrontElement) 
{
	MyQueue<int> Testqueue;
	Testqueue.push(1);
	Testqueue.push(2);
	EXPECT_EQ(1, Testqueue.pop());
}
TEST(QueueTest, DequeueDecreasesSize) {
	MyQueue<int> Testqueue;
	Testqueue.push(1);
	Testqueue.push(2);
	EXPECT_EQ(2, Testqueue.getSize());
	Testqueue.pop();
	EXPECT_EQ(1, Testqueue.getSize());
}
TEST(QueueTest, DequeueThrowsWhenQueueIsEmpty) {
	MyQueue<int> Testqueue;
	EXPECT_THROW(Testqueue.pop(), std::out_of_range);
}
TEST(QueueTest, PeekThrowsWhenQueueIsEmpty) {
	MyQueue<int> Testqueue;
	EXPECT_THROW(Testqueue.frontValue(), std::out_of_range);
}
TEST(QueueTest, PeekReturnsFrontElement) {
	MyQueue<int> Testqueue;
	Testqueue.push(1);
	Testqueue.push(2);
	EXPECT_EQ(1, Testqueue.frontValue());
}