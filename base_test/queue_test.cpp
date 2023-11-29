#include "queue.h"
#include <gtest.h>

TEST(TQueue, can_create_queue)
{
	ASSERT_NO_THROW(TQueue<int> que);
}

TEST(TQueue, cant_create_queue_with_negative_size)
{
	ASSERT_ANY_THROW(TQueue<int> que(-10));
}

TEST(TQueue, can_get_size)
{
	TQueue<int> que(5);
	que.Push(4);
	ASSERT_NO_THROW(que.GetSize());
}

TEST(TQueue, can_get_size_empty_queue)
{
	TQueue<int> que;
	ASSERT_NO_THROW(que.GetSize());
}

TEST(TQueue, can_check_empty)
{
	TQueue<int> que;
	ASSERT_NO_THROW(que.IsEmpty());
}

TEST(TQueue, can_push_element)
{
	TQueue<int> que(5);
	ASSERT_NO_THROW(que.Push(6));
}

TEST(TQueue, can_pop_element)
{
	TQueue<int> que(5);
	que.Push(6);
	ASSERT_NO_THROW(que.Pop());
}

TEST(TQueue, can_view_first_element)
{
	TQueue<int> que(5);
	que.Push(6);
	que.Push(26);
	que.Push(36);
	ASSERT_EQ(6, que.ViewFirst());
}

TEST(TQueue, queue_size_changes_after_push)
{
	TQueue<int> que(5);
	que.Push(6);
	que.Push(12);
	ASSERT_EQ(2, que.GetSize());
}

TEST(TQueue, queue_size_changes_after_pop)
{
	TQueue<int> que(10);
	que.Push(6);
	que.Push(26);
	que.Push(63);
	que.Push(16);
	que.Pop();
	ASSERT_EQ(3, que.GetSize());
}

TEST(TQueue, cant_pop_element_empty_queue)
{
	TQueue<int> que;
	ASSERT_ANY_THROW(que.Pop());
}
