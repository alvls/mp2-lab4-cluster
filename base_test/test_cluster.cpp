#include "cluster.h"
#include <gtest.h>


TEST(TCluster, can_create_cluster)
{
	ASSERT_NO_THROW(TCluster cluster(32, 100, 0.7));
}

TEST(TCluster, cant_create_cluster_with_invalid_args)
{
	ASSERT_ANY_THROW(TCluster cluster(16, 0, 0.2));
	ASSERT_ANY_THROW(TCluster cluster(40, 100, 0));
	ASSERT_ANY_THROW(TCluster cluster(0, 100, 0.6));
}

TEST(TCluster, can_execute_work)
{
	TCluster cluster(20, 64, 0.7);
	ASSERT_NO_THROW(cluster.exec());
}

TEST(TCluster, can_create_clusters_copy)
{
	TCluster cluster(64, 98, 0.5);
	TCluster cl(cluster);
	EXPECT_EQ(64, cl.get_stats().total_nodes);
	EXPECT_EQ(98, cl.get_stats().cycles);
}

TEST(TCluster, can_add_task)
{
	TCluster cluster(20, 50, 0.6);
	Task t;
	EXPECT_EQ(0, cluster.get_stats().total_tasks);
	cluster.add_task(t);
	EXPECT_EQ(1, cluster.get_stats().total_tasks);
}