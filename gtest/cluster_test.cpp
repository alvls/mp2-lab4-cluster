#include "gtest.h"
#include "C:/venn2713_repos/task_4/mp2-lab4-cluster/Cluster.h"

// Проверка добавления задачи в кластер и изменения количества используемых узлов
TEST(ClusterTest, AddTaskSuccessfully) {
  Cluster cluster(10);
  Task task1(1, 5, 3);
  EXPECT_TRUE(cluster.addTask(task1));
  EXPECT_EQ(cluster.getUsedNodes(), 3);
}

// Проверка, что задачи не добавляются, если недостаточно ресурсов
TEST(ClusterTest, AddTaskFailsWhenNotEnoughResources) {
  Cluster cluster(4);
  Task task1(1, 5, 3);
  Task task2(2, 5, 3);
  cluster.addTask(task1);
  EXPECT_FALSE(cluster.addTask(task2));
}

// Проверка, что задачи удаляются из кластера после выполнения
TEST(ClusterTest, TasksAreRemovedAfterCompletion) {
  Cluster cluster(10);
  Task task1(1, 1, 3);  // Задача должна завершиться за 1 такт
  cluster.addTask(task1);
  cluster.tick();  // 1 такт прошел
  EXPECT_EQ(cluster.getUsedNodes(), 0);
}

// Проверка вычисления процента загрузки кластера
TEST(ClusterTest, LoadPercentageCalculation) {
  Cluster cluster(10);
  Task task1(1, 1, 5);
  cluster.addTask(task1);
  double expectedLoad = 50.0; // 5 из 10 узлов заняты
  EXPECT_DOUBLE_EQ(cluster.getCurrentLoadPercentage(), expectedLoad);
}

// Проверка, что новый кластер не имеет использованных узлов
TEST(ClusterTest, NewClusterHasNoUsedNodes) {
  Cluster cluster(10);
  EXPECT_EQ(cluster.getUsedNodes(), 0);
}

// Проверка, что задача успешно добавляется, когда есть достаточно ресурсов
TEST(ClusterTest, TaskAddedWhenSufficientResources) {
  Cluster cluster(10);
  Task task(1, 5, 5);
  EXPECT_TRUE(cluster.addTask(task));
  EXPECT_EQ(cluster.getUsedNodes(), 5);
}

// Проверка, что tick уменьшает количество тактов у задачи
TEST(ClusterTest, TickDecrementsTasksTicksToComplete) {
  Cluster cluster(10);
  Task task(1, 2, 5);
  cluster.addTask(task);
  cluster.tick();
  // Задача не должна быть удалена, так как она требует 2 такта для выполнения
  EXPECT_EQ(cluster.getUnfinishedTasksCount(), 1);
}


// Проверка, что задачи, требующие больше узлов, чем доступно, не добавляются
TEST(ClusterTest, TaskRequiringMoreNodesThanAvailableIsNotAdded) {
  Cluster cluster(5);
  Task task(1, 5, 6);
  EXPECT_FALSE(cluster.addTask(task));
  EXPECT_EQ(cluster.getUnfinishedTasksCount(), 0);
}

// Проверка, что несколько задач могут быть добавлены, если есть ресурсы
TEST(ClusterTest, MultipleTasksAddedWhenResourcesAvailable) {
  Cluster cluster(10);
  Task task1(1, 5, 3);
  Task task2(2, 5, 2);
  EXPECT_TRUE(cluster.addTask(task1));
  EXPECT_TRUE(cluster.addTask(task2));
  EXPECT_EQ(cluster.getUsedNodes(), 5);
}

// Проверка, что после выполнения всех задач количество используемых узлов равно нулю
TEST(ClusterTest, AllNodesFreedAfterTasksCompletion) {
  Cluster cluster(10);
  Task task1(1, 1, 3);
  Task task2(2, 1, 2);
  cluster.addTask(task1);
  cluster.addTask(task2);
  cluster.tick(); // Обе задачи должны завершиться
  EXPECT_EQ(cluster.getUsedNodes(), 0);
}
