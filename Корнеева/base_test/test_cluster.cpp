#include <gtest.h>
#include "cluster.h"

TEST(TCluster, can_create_cluster)
{
	EXPECT_NO_THROW(TCluster cluster(16));
}


TEST(TCluster, can_not_create_cluster_with_too_many_computing_nodes)
{
	ASSERT_ANY_THROW(TCluster cluster(65));
}

TEST(TCluster, cant_create_cluster_with_less_than_minimum_nodes) 
{
	ASSERT_ANY_THROW(TCluster cluster(15));
}

TEST(TCluster, can_not_create_cluster_with_too_small_probability_threshold)
{
	TCluster cluster(32);
	ASSERT_ANY_THROW(cluster.generate_tasks(0.0, 2, 20));
}

TEST(TCluster, can_not_create_cluster_with_too_big_probability_threshold)
{
	TCluster cluster(32);
	ASSERT_ANY_THROW(cluster.generate_tasks(1.0, 2, 20));
}

TEST(TCluster, can_not_create_cluster_with_too_small_max_count_of_new_tasks)
{
	TCluster cluster(32);
	ASSERT_ANY_THROW(cluster.generate_tasks(0.5, 0, 20));
}

TEST(TCluster, can_not_create_cluster_with_too_small_max_time_for_one_task)
{
	TCluster cluster(32);
	ASSERT_ANY_THROW(cluster.generate_tasks(0.5, 2, 0));
}

