#include "cluster_manager.cpp"
#include "gtest/gtest.h"

TEST(Cluster_manager, can_create_cluster_manager) {
	ASSERT_NO_THROW(Cluster_manager cl(10));
}

TEST(Cluster_manager, can_finished_any_tasks) {
	Cluster_manager cl(50);
	cl.Computation();
	ASSERT_NO_THROW(cl.finishedTasks());
}

TEST(Cluster_manager, throw_when_incorrect_tacts) {
	ASSERT_ANY_THROW(Cluster_manager cl(-10));
}

TEST(Cluster_manager, can_create_cluster_manager_with_too_many_tacts) {
	ASSERT_NO_THROW(Cluster_manager cl(1000));
}

TEST(Cluster_manager, can_compute_cluster_manager_with_too_many_tacts) {
	Cluster_manager cl(1000);
	ASSERT_NO_THROW(cl.Computation());
}

