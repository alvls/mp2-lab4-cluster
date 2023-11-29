#include <gtest.h>
#include "cluster.h"
#include "cluster.cpp"
#include "task.h"

TEST(ClusterTest, clusterInitialization) {
   Cluster cluster(5);

   EXPECT_EQ(0, cluster.calculateBusyNodeCount());
   EXPECT_EQ(0, cluster.getTotalTaskCount());
}

TEST(ClusterTest, enqueueTaskIncreasesTotalNumberTasks) {
   Cluster cluster(5);
   Task task(5, 5);
   cluster.enqueueTask(task);

   EXPECT_EQ(1, cluster.getTotalTaskCount());
   EXPECT_EQ(0, cluster.getCompletedTaskCount());
}

TEST(ClusterTest, updateTheTasksAndFinishTheTask) {
   Cluster cluster(5);
   Task task(1, 1);
   cluster.enqueueTask(task);
   cluster.assignTasks();
   cluster.updateTaskStatus();

   EXPECT_EQ(1, cluster.getCompletedTaskCount());
   EXPECT_EQ(0, cluster.getCurrentTaskCount());
   EXPECT_EQ(0, cluster.calculateBusyNodeCount());
}

TEST(ClusterTest, calculateThePercentageOfLoad) {
   Cluster cluster(10);
   Task task(2, 2);
   cluster.enqueueTask(task);
   cluster.assignTasks();

   EXPECT_EQ(20.0, cluster.calculateLoadPercentage());
}

TEST(ClusterTest, assignTasksWhenThereEnoughNodes) {
   Cluster cluster(5);
   Task task(5, 5);
   cluster.enqueueTask(task);
   cluster.assignTasks();

   EXPECT_EQ(5, cluster.calculateBusyNodeCount());
   EXPECT_EQ(1, cluster.getCurrentTaskCount());
}

TEST(ClusterTest, assignTasksWhenThereNotEnoughNodes) {
   Cluster cluster(3);
   Task task(5, 5);
   cluster.enqueueTask(task);
   cluster.assignTasks();

   EXPECT_EQ(0, cluster.getCurrentTaskCount());
   EXPECT_EQ(0, cluster.calculateBusyNodeCount());
}
