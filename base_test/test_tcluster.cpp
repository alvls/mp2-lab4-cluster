#include <gtest.h>
#include "tcluster.h"
#include "cluster.cpp"
#include "task.h"

TEST(ClusterTest, ClusterInitialization) {
	Cluster cluster(10);
	EXPECT_EQ(0, cluster.getTotalTasks());
	EXPECT_EQ(0, cluster.getBusyNodeCount());
}

TEST(ClusterTest, AddTaskIncreasesTotalTasks) {
	Cluster cluster(10);
	Task task(5, 2);
	cluster.addTask(task);
	EXPECT_EQ(1, cluster.getTotalTasks());
	EXPECT_EQ(0, cluster.getTasksCompleted());
}

TEST(ClusterTest, DistributeTasksWhenSufficientNodes) {
	Cluster cluster(10);
	Task task(5, 3);
	cluster.addTask(task);
	cluster.distributeTasks();
	EXPECT_EQ(1, cluster.getCurrentTaskCount());
	EXPECT_EQ(3, cluster.getBusyNodeCount());
}

TEST(ClusterTest, DistributeTasksWhenInsufficientNodes) {
	Cluster cluster(2);
	Task task(5, 3);
	cluster.addTask(task);
	cluster.distributeTasks();
	EXPECT_EQ(0, cluster.getCurrentTaskCount());
	EXPECT_EQ(0, cluster.getBusyNodeCount());
}

TEST(ClusterTest, UpdateTasksAndCompleteTask) {
	Cluster cluster(10);
	Task task(1, 1);
	cluster.addTask(task);
	cluster.distributeTasks();
	cluster.updateTasks();
	EXPECT_EQ(0, cluster.getCurrentTaskCount());
	EXPECT_EQ(1, cluster.getTasksCompleted());
	EXPECT_EQ(0, cluster.getBusyNodeCount());
}

TEST(ClusterTest, CalculateLoadPercentage) {
	Cluster cluster(10);
	Task task(5, 5);
	cluster.addTask(task);
	cluster.distributeTasks();
	EXPECT_EQ(50.0, cluster.getLoadPercentage());
}