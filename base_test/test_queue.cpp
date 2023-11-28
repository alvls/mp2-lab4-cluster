#include "queue.h"
#include <gtest.h>

TEST(Queue, can_create_queue)
{
	ASSERT_NO_THROW(Queue<int> q);
}

TEST(Queue, can_push_back_element_to_empty_queue)
{
	Queue<int> q;

	ASSERT_NO_THROW(q.push_back(13));
}

TEST(Queue, can_check_first_element_of_queue_without_pop)
{
	Queue<int> q;

	q.push_back(13);
	EXPECT_EQ(13, q.get_next());
}

TEST(Queue, can_not_check_first_element_of_empty_queue_without_pop)
{
	Queue<int> q;

	ASSERT_ANY_THROW(q.get_next());
}

TEST(Queue, can_pop_element_from_queue)
{
	Queue<int> q;

	q.push_back(13);
	ASSERT_NO_THROW(q.pop());

	q.push_back(13);
	EXPECT_EQ(13, q.pop());
}

TEST(Queue, can_not_pop_element_from_empty_queue)
{
	Queue<int> q;

	ASSERT_ANY_THROW(q.pop());
}

TEST(Queue, check_if_queue_is_empty)
{
	Queue<int> q;

	EXPECT_EQ(true, q.empty());

	q.push_back(13);
	EXPECT_NE(true, q.empty());
}

TEST(Queue, can_get_size_of_queue)
{
	Queue<int> q;

	EXPECT_EQ(0, q.size());
}

TEST(Queue, size_is_changing_after_push_back)
{
	Queue<int> q;

	EXPECT_EQ(0, q.size());

	q.push_back(13);
	EXPECT_EQ(1, q.size());
}

TEST(Queue, size_is_changing_after_pop)
{
	Queue<int> q;

	q.push_back(13);
	q.push_back(31);
	EXPECT_EQ(2, q.size());

	q.pop();
	EXPECT_EQ(1, q.size());
}

TEST(Queue, size_is_not_changing_after_checking_of_first_element)
{
	Queue<int> q;

	q.push_back(13);
	EXPECT_EQ(1, q.size());

	q.get_next();
	EXPECT_EQ(1, q.size());
}

TEST(Queue, principal_first_in_first_out_is_complied)
{
	Queue<int> q;

	q.push_back(13);
	q.push_back(33);
	q.push_back(31);
	EXPECT_EQ(13, q.pop());
}
