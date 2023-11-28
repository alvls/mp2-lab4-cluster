#include "Queue.h"
#include <gtest.h>

TEST(TStackQueue, can_create_queue)
{
    ASSERT_NO_THROW(TStackQueue<int> q);
}

TEST(TStackQueue, can_get_top)
{
    TStackQueue<int> q;
    q.push(2);
    EXPECT_EQ(q.top(), 2);
}

TEST(TStackQueue, can_get_pop)
{
    TStackQueue<int> q;
    q.push(2);
    EXPECT_EQ(q.pop(), 2);
}

TEST(TStackQueue, is_empty_when_created)
{
    TStackQueue<int> q;
    EXPECT_TRUE(q.isEmpty());
    EXPECT_EQ(q.size(), 0);
}

TEST(TStackQueue, can_push_and_pop_elements)
{
    TStackQueue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    EXPECT_EQ(q.top(), 1);
    EXPECT_EQ(q.size(), 3);

    EXPECT_EQ(q.pop(), 1);
    EXPECT_EQ(q.top(), 2);
    EXPECT_EQ(q.size(), 2);

    EXPECT_EQ(q.pop(), 2);
    EXPECT_EQ(q.top(), 3);
    EXPECT_EQ(q.size(), 1);

    EXPECT_EQ(q.pop(), 3);
    EXPECT_TRUE(q.isEmpty());
    EXPECT_EQ(q.size(), 0);
}

TEST(TStackQueue, handles_push_and_pop_alternatively)
{
    TStackQueue<int> q;
    q.push(1);
    q.push(2);
    q.pop();
    q.push(3);

    EXPECT_EQ(q.top(), 2);
    EXPECT_EQ(q.size(), 2);

    EXPECT_EQ(q.pop(), 2);
    EXPECT_EQ(q.top(), 3);
    EXPECT_EQ(q.size(), 1);

    EXPECT_EQ(q.pop(), 3);
    EXPECT_TRUE(q.isEmpty());
    EXPECT_EQ(q.size(), 0);
}

TEST(TStackQueue, size_increases_with_each_push)
{
    TStackQueue<int> q;
    EXPECT_EQ(q.size(), 0);
    q.push(1);
    EXPECT_EQ(q.size(), 1);
    q.push(2);
    EXPECT_EQ(q.size(), 2);
}

TEST(TStackQueue, push_and_pop_negative_numbers)
{
    TStackQueue<int> q;
    q.push(-1);
    q.push(-2);

    EXPECT_EQ(q.top(), -1);
    EXPECT_EQ(q.pop(), -1);
    EXPECT_EQ(q.top(), -2);
    EXPECT_EQ(q.pop(), -2);
    EXPECT_TRUE(q.isEmpty());
}

TEST(TStackQueue, push_and_pop_large_number_of_elements)
{
    TStackQueue<int> q;
    for (int i = 0; i < 1000; ++i) {
        q.push(i);
    }

    EXPECT_EQ(q.size(), 1000);

    for (int i = 0; i < 1000; ++i) {
        EXPECT_EQ(q.pop(), i);
    }

    EXPECT_TRUE(q.isEmpty());
}