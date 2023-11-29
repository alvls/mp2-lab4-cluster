#include "gtest.h"
#include "C:/venn2713_repos/task_4/mp2-lab4-cluster/Task.h"

// Проверка, что идентификатор задачи корректно устанавливается
TEST(TaskTest, TaskIdIsSetCorrectly) {
  Task task(2, 10, 5);
  EXPECT_EQ(task.id, 2);
}

// Проверка, что количество тактов для выполнения задачи устанавливается корректно
TEST(TaskTest, TicksToCompleteIsSetCorrectly) {
  Task task(3, 15, 5);
  EXPECT_EQ(task.ticksToComplete, 15);
}

// Проверка, что количество необходимых узлов устанавливается корректно
TEST(TaskTest, NodesRequiredIsSetCorrectly) {
  Task task(4, 10, 7);
  EXPECT_EQ(task.nodesRequired, 7);
}

// Проверка на корректное уменьшение количества тактов при выполнении задачи
TEST(TaskTest, DecreaseTicksToComplete) {
  Task task(7, 10, 5);
  task.ticksToComplete--; // Имитация уменьшения количества тактов
  EXPECT_EQ(task.ticksToComplete, 9);
}