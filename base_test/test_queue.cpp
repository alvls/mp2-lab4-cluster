#include <gtest.h>
#include "queue.h"

TEST(TQueue, can_create_queue_with_positive_size)
{
   ASSERT_NO_THROW(TQueue<int> q(10));
}

TEST(TQueue, cant_create_queue_with_negative_size)
{
   ASSERT_ANY_THROW(TQueue<int> q(-5));
}

TEST(TQueue, cant_create_too_large_queue)
{
   ASSERT_ANY_THROW(TQueue<int> q(400));
}

TEST(TQueue, can_enqueue_element)
{
   TQueue<int> q(10);
   ASSERT_NO_THROW(q.Enqueue(5));
}

TEST(TQueue, queue_is_empty)
{
   TQueue<int> q(10);
   EXPECT_TRUE(q.isEmpty());
}

TEST(TQueue, can_get_size)
{
   TQueue<int> q(10);
   q.Enqueue(1);
   q.Enqueue(5);

   EXPECT_EQ(q.getSize(), 2);
}

TEST(TQueue, can_dequeue_first_element)
{
   TQueue<int> q(10);
   q.Enqueue(1);
   q.Enqueue(2);
   q.Enqueue(3);

   EXPECT_EQ(q.Dequeue(), 1);
}

TEST(TQueue, can_check_first_element)
{
   TQueue<int> q(10);
   q.Enqueue(1);
   q.Enqueue(2);
   q.Enqueue(3);

   EXPECT_EQ(q.PeekFront(), 1);
}

TEST(TQueue, PeekFront_does_not_remove_element)
{
   TQueue<int> q(1);
   q.Enqueue(3);
   q.PeekFront();

   ASSERT_FALSE(q.isEmpty());
}

TEST(TQueue, cant_dequeue_element_from_empty_queue)
{
   TQueue<int> q(1);
   ASSERT_ANY_THROW(q.Dequeue());
}

TEST(TQueue, cant_check_first_element_from_empty_queue)
{
   TQueue<int> q(1);
   ASSERT_ANY_THROW(q.PeekFront());
}

TEST(TQueue, can_change_size_after_dequeue_element)
{
   TQueue<int> q(10);
   q.Enqueue(1);
   q.Enqueue(2);
   q.Enqueue(3);
   q.Enqueue(4);
   q.Dequeue();

   EXPECT_EQ(q.getSize(), 3);
}
