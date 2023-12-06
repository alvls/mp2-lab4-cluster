#include <gtest.h>
#include "cluster.h"
#include "cluster.cpp"
#include "task.h"

TEST(Cluster, cluster_initialization) {
   Cluster cluster(5);

   EXPECT_EQ(0, cluster.calculateBusyNodeCount());
   EXPECT_EQ(0, cluster.getTotalTaskCount());
}

TEST(Cluster, enqueue_task_increases_total_number_tasks) {
   Cluster cluster(5);
   Task task(5, 5);
   cluster.enqueueTask(task);

   EXPECT_EQ(1, cluster.getTotalTaskCount());
   EXPECT_EQ(0, cluster.getCompletedTaskCount());
}

TEST(Cluster, update_the_tasks_and_finish_the_task) {
   Cluster cluster(5);
   Task task(1, 1);
   cluster.enqueueTask(task);
   cluster.assignTasks();
   cluster.updateTaskStatus();

   EXPECT_EQ(1, cluster.getCompletedTaskCount());
   EXPECT_EQ(0, cluster.getCurrentTaskCount());
   EXPECT_EQ(0, cluster.calculateBusyNodeCount());
}

TEST(Cluster, calculate_the_percentage_of_load) {
   Cluster cluster(10);
   Task task(2, 2);
   cluster.enqueueTask(task);
   cluster.assignTasks();

   EXPECT_EQ(20.0, cluster.calculateLoadPercentage());
}

TEST(Cluster, assign_tasks_when_there_enough_nodes) {
   Cluster cluster(5);
   Task task(5, 5);
   cluster.enqueueTask(task);
   cluster.assignTasks();

   EXPECT_EQ(5, cluster.calculateBusyNodeCount());
   EXPECT_EQ(1, cluster.getCurrentTaskCount());
}

TEST(Cluster, assign_tasks_when_there_not_enough_nodes) {
   Cluster cluster(3);
   Task task(5, 5);
   cluster.enqueueTask(task);
   cluster.assignTasks();

   EXPECT_EQ(0, cluster.getCurrentTaskCount());
   EXPECT_EQ(0, cluster.calculateBusyNodeCount());
}
