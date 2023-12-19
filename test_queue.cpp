#include "TQueue.h"
#include "gtest/gtest.h"

TEST(TQueue, can_create_queue_with_positive_length) {
	ASSERT_NO_THROW(TQueue<int> qu(10));
}

TEST(TQueue, can_push_elem) {
	TQueue<int> qu(5);
	ASSERT_NO_THROW(qu.enqueue(5));
}

TEST(TQueue, can_pop_elem) {
	TQueue<int> qu(5);
	qu.enqueue(5);
	qu.enqueue(4);
	EXPECT_EQ(5, qu.dequeue());
}
TEST(TQueue, can_get_count_of_elem) {
	TQueue<int> qu(5);
	qu.enqueue(5);
	qu.enqueue(4);
	EXPECT_EQ(2, qu.Size());
}

TEST(TQueue, throw_when_the_length_too_much) {
	ASSERT_ANY_THROW(TQueue<int> qu(100000));
}

TEST(TQueue, dequeue_throws_when_queue_isEmpty) {
	TQueue<int> qu;
	EXPECT_ANY_THROW(qu.dequeue());
}

TEST(TQueue, peek_throw_when_queue_isEmpty) {
	TQueue<int> qu;
	EXPECT_ANY_THROW(qu.peek());
}

TEST(TQueue, size_is_changing_after_enqueue) {
	TQueue<int> qu;
	EXPECT_EQ(0, qu.Size());
	qu.enqueue(1);
	EXPECT_EQ(1, qu.Size());
}

TEST(TQueue, size_is_changing_after_dequeue) {
	TQueue<int> qu;
	qu.enqueue(1);
	qu.enqueue(2);
	EXPECT_EQ(2, qu.Size());
	qu.dequeue();
	EXPECT_EQ(1, qu.Size());
}
