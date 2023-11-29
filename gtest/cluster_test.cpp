#include "gtest.h"
#include "C:/venn2713_repos/task_4/mp2-lab4-cluster/Cluster.h"

// �������� ���������� ������ � ������� � ��������� ���������� ������������ �����
TEST(ClusterTest, AddTaskSuccessfully) {
  Cluster cluster(10);
  Task task1(1, 5, 3);
  EXPECT_TRUE(cluster.addTask(task1));
  EXPECT_EQ(cluster.getUsedNodes(), 3);
}

// ��������, ��� ������ �� �����������, ���� ������������ ��������
TEST(ClusterTest, AddTaskFailsWhenNotEnoughResources) {
  Cluster cluster(4);
  Task task1(1, 5, 3);
  Task task2(2, 5, 3);
  cluster.addTask(task1);
  EXPECT_FALSE(cluster.addTask(task2));
}

// ��������, ��� ������ ��������� �� �������� ����� ����������
TEST(ClusterTest, TasksAreRemovedAfterCompletion) {
  Cluster cluster(10);
  Task task1(1, 1, 3);  // ������ ������ ����������� �� 1 ����
  cluster.addTask(task1);
  cluster.tick();  // 1 ���� ������
  EXPECT_EQ(cluster.getUsedNodes(), 0);
}

// �������� ���������� �������� �������� ��������
TEST(ClusterTest, LoadPercentageCalculation) {
  Cluster cluster(10);
  Task task1(1, 1, 5);
  cluster.addTask(task1);
  double expectedLoad = 50.0; // 5 �� 10 ����� ������
  EXPECT_DOUBLE_EQ(cluster.getCurrentLoadPercentage(), expectedLoad);
}

// ��������, ��� ����� ������� �� ����� �������������� �����
TEST(ClusterTest, NewClusterHasNoUsedNodes) {
  Cluster cluster(10);
  EXPECT_EQ(cluster.getUsedNodes(), 0);
}

// ��������, ��� ������ ������� �����������, ����� ���� ���������� ��������
TEST(ClusterTest, TaskAddedWhenSufficientResources) {
  Cluster cluster(10);
  Task task(1, 5, 5);
  EXPECT_TRUE(cluster.addTask(task));
  EXPECT_EQ(cluster.getUsedNodes(), 5);
}

// ��������, ��� tick ��������� ���������� ������ � ������
TEST(ClusterTest, TickDecrementsTasksTicksToComplete) {
  Cluster cluster(10);
  Task task(1, 2, 5);
  cluster.addTask(task);
  cluster.tick();
  // ������ �� ������ ���� �������, ��� ��� ��� ������� 2 ����� ��� ����������
  EXPECT_EQ(cluster.getUnfinishedTasksCount(), 1);
}


// ��������, ��� ������, ��������� ������ �����, ��� ��������, �� �����������
TEST(ClusterTest, TaskRequiringMoreNodesThanAvailableIsNotAdded) {
  Cluster cluster(5);
  Task task(1, 5, 6);
  EXPECT_FALSE(cluster.addTask(task));
  EXPECT_EQ(cluster.getUnfinishedTasksCount(), 0);
}

// ��������, ��� ��������� ����� ����� ���� ���������, ���� ���� �������
TEST(ClusterTest, MultipleTasksAddedWhenResourcesAvailable) {
  Cluster cluster(10);
  Task task1(1, 5, 3);
  Task task2(2, 5, 2);
  EXPECT_TRUE(cluster.addTask(task1));
  EXPECT_TRUE(cluster.addTask(task2));
  EXPECT_EQ(cluster.getUsedNodes(), 5);
}

// ��������, ��� ����� ���������� ���� ����� ���������� ������������ ����� ����� ����
TEST(ClusterTest, AllNodesFreedAfterTasksCompletion) {
  Cluster cluster(10);
  Task task1(1, 1, 3);
  Task task2(2, 1, 2);
  cluster.addTask(task1);
  cluster.addTask(task2);
  cluster.tick(); // ��� ������ ������ �����������
  EXPECT_EQ(cluster.getUsedNodes(), 0);
}
