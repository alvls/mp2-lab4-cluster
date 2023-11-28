#include "Cluster.h"
#include <gtest.h>

TEST(Task, can_create_cluster)
{
    ASSERT_NO_THROW(cluster c);
}

TEST(Task, can_create_cluster_with_params)
{
    ASSERT_NO_THROW(cluster c(48, 10000, 3, 5, 0.5));
}

TEST(Task, cant_create_cluster_with_large_node)
{
    ASSERT_ANY_THROW(cluster c(75, 10000, 3, 5, 0.5));
}

TEST(Task, cant_create_cluster_with_small_node)
{
    ASSERT_ANY_THROW(cluster c(5, 10000, 3, 5, 0.5));
}

TEST(Task, cant_create_cluster_with_negative_taskAppearLimit)
{
    ASSERT_ANY_THROW(cluster c(48, 10000, 3, 5, -1.0));
}

TEST(Task, cant_create_cluster_with_large_taskAppearLimit)
{
    ASSERT_ANY_THROW(cluster c(48, 10000, 3, 5, 2.0));
}