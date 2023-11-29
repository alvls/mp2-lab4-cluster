#include "gtest.h"
#include "Queue_task.cpp"

TEST(Test_Queue_task, CanCreateQeue_task) {
	ASSERT_NO_THROW(Queue_task tmp());
}
TEST(Test_Queue_task, NewQeue_taskHaveZeroSize) {
	Queue_task tmp;
	EXPECT_EQ(0, tmp.GetSize());
}
TEST(Test_Queue_task, PushChangeSize) {
	Queue_task tmp;
	Task t;
	t.time = 2;
	t.number_of_nodes = 3;
	tmp.Push(t);
	EXPECT_EQ(1, tmp.GetSize());
}
TEST(Test_Queue_task, canPop) {
	Queue_task tmp;
	Task t,t3;
	t.time = 2;
	t.number_of_nodes = 3;
	tmp.Push(t);
	t3 = tmp.Pop()->date;
	EXPECT_EQ(3,t3.number_of_nodes);
	EXPECT_EQ(2, t3.time);
}
TEST(Test_Queue_task, CantPopIfSize0) {
	Queue_task tmp;
	ASSERT_ANY_THROW(tmp.Pop());
}
TEST(Test_Queue_task, canWatch) {
	Queue_task tmp;
	Task t, t3;
	t.time = 2;
	t.number_of_nodes = 3;
	tmp.Push(t);
	t3 = tmp.WatchFirst();
	EXPECT_EQ(3, t3.number_of_nodes);
	EXPECT_EQ(2, t3.time);
}
TEST(Test_Queue_task, PopChangeSize) {
	Queue_task tmp;
	Task t;
	t.time = 2;
	t.number_of_nodes = 3;
	tmp.Push(t);
	tmp.Pop();
	EXPECT_EQ(0, tmp.GetSize());
}
TEST(Test_Queue_task, WatchfirstdontChangeSize) {
	Queue_task tmp;
	Task t;
	t.time = 2;
	t.number_of_nodes = 3;
	tmp.Push(t);
	tmp.WatchFirst();
	EXPECT_EQ(1, tmp.GetSize());
}