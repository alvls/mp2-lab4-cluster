#include <gtest.h>
#include "task.h"
#include "task.cpp"
#include "cluster.h"
#include "cluster.cpp"

TEST(Cluster, can_create_cluster)
{
	ASSERT_NO_THROW(Cluster c(100, 50, 64, 3));
}

TEST(Cluster, can_generate_new_task)
{
	Cluster c(100, 100, 64, 3);
	EXPECT_TRUE(c.GenerateNewTask());
}

TEST(Cluster, can_do_task)
{
	Cluster c(200, 50, 64, 3);
	c.ClusterWork();
	EXPECT_NE(c.CountZv(), 0);
}

TEST(Task, can_create_task)
{
	ASSERT_NO_THROW(Task t());
}

TEST(Task, can_copy_task)
{
	Task t;
	ASSERT_NO_THROW(Task tt(t));
}

TEST(Task, can_change_time)
{
	Task T;
	int t1 = T.GetTime();
	T.ChangeT();
	int t2 = T.GetTime();
	EXPECT_EQ(t1, t2 + 1);
}