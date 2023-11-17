#include "gtest.h"
#include "queue.h"

TEST(Queue, can_create_queue) {
	ASSERT_NO_THROW(Queue<int> q);
}

TEST(Queue, can_add_element) {
	Queue<int> q;
	ASSERT_NO_THROW(q.add(90));
}

TEST(Queue, can_get_element) {
	Queue<int> q;
	q.add(38);
	ASSERT_NO_THROW(q.get());
}

TEST(Queue, can_get_size) {
	Queue<int> q;
	ASSERT_NO_THROW(q.size());
}

TEST(Queue, cant_get_element_from_empty_queue) {
	Queue<int> q;
	ASSERT_ANY_THROW(q.get());
}

TEST(Queue, can_get_element_from_index) {
	Queue<int> q;
	q.add(3);
	ASSERT_NO_THROW(q[0]);
}

TEST(Queue, cant_get_element_from_invalid_index) {
	Queue<int> q;
	q.add(3);
	ASSERT_ANY_THROW(q[2]);
}

TEST(Queue, get_element_from_index_return_true_value) {
	Queue<int> q;
	q.add(3);
	q.add(2);
	ASSERT_NO_THROW(q[1]);
}

TEST(Queue, get_element_return_true_value) {
	Queue<int> q;
	q.add(3);
	q.add(4);
	q.get();
	EXPECT_EQ(4,q.get());
}