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

TEST(Cluster, cant_create_cluster_with_negative_params) {
	ASSERT_ANY_THROW(Cluster(-2, 0, -3.8));
}

TEST(Cluster, can_start_work) {
	Cluster c;
	ASSERT_NO_THROW(c.start(0));
}

TEST(Cluster, can_get_stat) {
	Cluster c;
	ASSERT_NO_THROW(c.get_stat());
}