#include "cluster.h"
#include "cluster.cpp"
#include <gtest.h>

TEST(Cluster, can_create_cluster)
{
	ASSERT_NO_THROW(Cluster cl(10, 20, 40, 2, 0.4));
}

TEST(Cluster, cant_create_clluster_with_too_large_queue_size)
{
	ASSERT_ANY_THROW(Cluster cl(MaxSize+1, 20, 40, 2, 0.4));
}

TEST(Cluster, cant_create_clluster_with_too_small_queue_size)
{
	ASSERT_ANY_THROW(Cluster cl(MinSize - 1, 20, 40, 2, 0.4));
}

TEST(Cluster, cant_create_cluster_with_too_few_tacts)
{
	ASSERT_ANY_THROW(Cluster cl(10, MinTacts - 1, 40, 2, 0.4));
}
TEST(Cluster, cant_create_cluster_too_many_tacts)
{
	ASSERT_ANY_THROW(Cluster cl(10, MaxTacts + 1, 40, 2, 0.4));
}
TEST(Cluster, cant_create_cluster_with_too_few_nodes)
{
	ASSERT_ANY_THROW(Cluster cl(10, 20, MinN-1, 2, 0.4));
}
TEST(Cluster, cant_create_cluster_with_too_many_nodes)
{
	ASSERT_ANY_THROW(Cluster cl(10, 20, MaxN + 1, 2, 0.4));
}
TEST(Cluster, cant_create_cluster_with_too_few_parametr_k)
{
	ASSERT_ANY_THROW(Cluster cl(10, 20, 40, -2, 0.4));
}

TEST(Cluster, cant_create_cluster_with_too_large_parametr_frequency)
{
	ASSERT_ANY_THROW(Cluster cl(10, 20, 40, 2, MaxF + 0.3));
}

TEST(Cluster, cant_create_cluster_with_too_small_parametr_frequency)
{
	ASSERT_ANY_THROW(Cluster cl(10, 20, 40, 2, MinF - 0.3));
}
