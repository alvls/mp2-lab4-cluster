#include "queue.h"
#include <gtest.h>
#include <Cluster.h>

TEST(TQueue, can_create_queue)
{
	EXPECT_NO_THROW(TQueue<int> queue());
}

TEST(TQueue, can_create_queues_copies)
{
	TQueue<Task> queue;
	TQueue<Task> q(queue);

	EXPECT_EQ(0, q.size());

}

TEST(TQueue, new_queue_is_empty)
{
	TQueue<int> queue;
	EXPECT_EQ(true, queue.is_empty());
}

TEST(TQueue, cant_pull_from_empty_queue)
{
	TQueue<Task> queue;
	ASSERT_ANY_THROW(queue.pull());
}

TEST(TQueue, can_push_element)
{
	TQueue<int> queue;
	ASSERT_NO_THROW(queue.push_back(2));
	EXPECT_EQ(1, queue.size());
	EXPECT_EQ(2, queue.peek());
}

TEST(TQueue, can_remove_element)
{
	TQueue<int> queue;
	EXPECT_EQ(0, queue.size());
	queue.push_back(5);
	EXPECT_EQ(1, queue.size());
	ASSERT_NO_THROW(queue.remove(0)); // remove по индексу элемента
	EXPECT_EQ(0, queue.size());
}