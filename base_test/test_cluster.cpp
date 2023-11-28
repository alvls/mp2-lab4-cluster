#include "Cluster.h"
#include <gtest.h>

TEST(Cluster, can_create_cluster)
{
	ASSERT_NO_THROW(Cluster c(16, 0.5, 2, 20));
}

TEST(Cluster, can_create_cluster_with_list_of_tasks)
{
	vector<pair<int, Task>> tz;

	ASSERT_NO_THROW(Cluster c(32, 0.5, 2, 20, tz));
}

TEST(Cluster, can_not_create_cluster_with_too_few_computing_nodes)
{
	ASSERT_ANY_THROW(Cluster c(15, 0.5, 2, 20));
}

TEST(Cluster, can_not_create_cluster_with_too_many_computing_nodes)
{
	ASSERT_ANY_THROW(Cluster c(65, 0.5, 2, 20));
}
 
TEST(Cluster, can_not_create_cluster_with_too_small_probability_threshold)
{
	ASSERT_ANY_THROW(Cluster c(32, 0, 2, 20));
}

TEST(Cluster, can_not_create_cluster_with_too_big_probability_threshold)
{
	ASSERT_ANY_THROW(Cluster c(32, 1, 2, 20));
}

TEST(Cluster, can_not_create_cluster_with_too_small_max_count_of_new_tasks)
{
	ASSERT_ANY_THROW(Cluster c(32, 0.5, 0, 20));
}

TEST(Cluster, can_not_create_cluster_with_too_small_max_time_for_one_task)
{
	ASSERT_ANY_THROW(Cluster c(32, 0.5, 2, 0));
}

TEST(Cluster, can_not_do_implementetion_with_too_small_time_of_working)
{
	Cluster c(32, 0.5, 2, 10);

	ASSERT_ANY_THROW(c.Implementation(0));
}

TEST(Cluster, can_create_statistics)
{
	vector<pair<int, Task>> tz;

	tz.push_back({ 1, Task{8, 16} });
	tz.push_back({ 1, Task{7, 8} });
	tz.push_back({ 4, Task{15, 32} });

	Statistics s1(25, 3, 0, (7.0 * 24.0 / 32.0 + 16.0 / 32.0 + 15.0) / 25 * 100);
	Cluster c(32, 0.5, 2, 20, tz);
	Statistics s2 = c.Implementation(25);

	EXPECT_EQ(s1.time_of_working, s2.time_of_working);
	EXPECT_EQ(s1.count_of_completed, s2.count_of_completed);
	EXPECT_EQ(s1.count_of_incompleted, s2.count_of_incompleted);
	EXPECT_EQ(s1.cluster_load, s2.cluster_load);
}