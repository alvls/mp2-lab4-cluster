#include <gtest.h>
#include "queue.h"

TEST(TQueue, can_create_queue)
{
	ASSERT_NO_THROW(TQueue<int> q(5));
}

TEST(TQueue, cant_create_queue_with_negative_size)
{
	ASSERT_ANY_THROW(TQueue<int> q(-4));
}

TEST(TQueue, cant_create_queue_with_big_size)
{
	ASSERT_ANY_THROW(TQueue<int> q(500));
}

TEST(TQueue, can_check_queue_is_empty)
{
	TQueue<int> q(5);
	EXPECT_TRUE(q.IsEmpty());
}

TEST(TQueue, can_get_size)
{
	TQueue<int> q(5);
	q.Put(2);
	q.Put(3);
	q.Put(4);
	EXPECT_EQ(q.GetSize(), 3);
}

TEST(TQueue, can_put_elem)
{
	TQueue<int> q(5);
	ASSERT_NO_THROW(q.Put(2));
}

TEST(TQueue, can_remove_first_elem)
{
	TQueue<int> q(5);
	q.Put(2);
	q.Put(3);
	q.Put(4);
	EXPECT_EQ(q.RemoveFirst(), 2);
}

TEST(TQueue, can_change_size_after_remove_element)
{
	TQueue<int> q(5);
	q.Put(2);
	q.Put(3);
	q.Put(4);
	q.RemoveFirst();
	EXPECT_EQ(q.GetSize(), 2);
}

TEST(TQueue, can_check_first_element_withuot_remove)
{
	TQueue<int> q(5);
	q.Put(2);
	q.Put(3);
	q.Put(4);
	EXPECT_EQ(q.GetFirst(), 2);
}