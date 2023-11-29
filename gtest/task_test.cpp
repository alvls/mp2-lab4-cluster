#include "gtest.h"
#include "C:/venn2713_repos/task_4/mp2-lab4-cluster/Task.h"

// ��������, ��� ������������� ������ ��������� ���������������
TEST(TaskTest, TaskIdIsSetCorrectly) {
  Task task(2, 10, 5);
  EXPECT_EQ(task.id, 2);
}

// ��������, ��� ���������� ������ ��� ���������� ������ ��������������� ���������
TEST(TaskTest, TicksToCompleteIsSetCorrectly) {
  Task task(3, 15, 5);
  EXPECT_EQ(task.ticksToComplete, 15);
}

// ��������, ��� ���������� ����������� ����� ��������������� ���������
TEST(TaskTest, NodesRequiredIsSetCorrectly) {
  Task task(4, 10, 7);
  EXPECT_EQ(task.nodesRequired, 7);
}

// �������� �� ���������� ���������� ���������� ������ ��� ���������� ������
TEST(TaskTest, DecreaseTicksToComplete) {
  Task task(7, 10, 5);
  task.ticksToComplete--; // �������� ���������� ���������� ������
  EXPECT_EQ(task.ticksToComplete, 9);
}