#include "cluster.h"
#include "gtest.h"

TEST(Cluster, can_create_cluster_default_constructor) {
	ASSERT_NO_THROW(Cluster c);
}

TEST(Cluster, can_create_cluster_two_params_constructor) {
	ASSERT_NO_THROW(Cluster c(43, 100));
}

TEST(Cluster, can_create_cluster_three_params_constructor) {
	ASSERT_NO_THROW(Cluster c(64, 1000, 0.56));
}

TEST(Cluster, can_start_work) {
	Cluster c;
	ASSERT_NO_THROW(c.start());
}

TEST(Cluster, can_get_stat) {
	Cluster c;
	ASSERT_NO_THROW(c.get_stat());
}