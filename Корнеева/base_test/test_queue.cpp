#include <gtest.h>

#include "queue.h"

TEST(TQueue, can_create_queue)
{
	EXPECT_NO_THROW(TQueue<int> queue());
}

TEST(TQueue, can_peek_empty_queue)
{
	TQueue<int> queue;
	ASSERT_ANY_THROW(queue.peek());
}

TEST(TQueue, can_enqueue_and_peek)
{
	TQueue<int> queue;
	queue.enqueue(42);

	int frontElement;
	ASSERT_NO_THROW(frontElement = queue.peek());
	EXPECT_EQ(frontElement, 42);
}

TEST(TQueue, can_enqueue_and_dequeue)
{
	TQueue<int> queue;
	queue.enqueue(42);

	int frontElement;
	ASSERT_NO_THROW(frontElement = queue.dequeue());
	EXPECT_EQ(frontElement, 42);

	ASSERT_ANY_THROW(queue.peek());
}

TEST(TQueue, can_enqueue_multiple_elements)
{
	TQueue<int> queue;
	for (int i = 1; i <= 5; ++i)
	{
		queue.enqueue(i);
	}

	ASSERT_EQ(queue.peek(), 1);
	ASSERT_EQ(queue.size(), 5);
}

TEST(TQueue, dequeue_from_empty_queue_throws_exception)
{
	TQueue<int> queue;
	ASSERT_ANY_THROW(queue.dequeue());
}

TEST(TQueue, enqueue_and_dequeue_alternatively)
{
	TQueue<int> queue;
	queue.enqueue(1);
	queue.dequeue();
	queue.enqueue(2);

	ASSERT_EQ(queue.peek(), 2);
	ASSERT_EQ(queue.size(), 1);
}