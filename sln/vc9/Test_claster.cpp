#include "gtest.h"
#include "Claster.cpp"
TEST(Test_Claster, CanCreateClaster) {
	ASSERT_NO_THROW(Claster tmp());
}
TEST(Test_Claster, CanSetTakt) {
	Claster Cl;
	Task t1, t2;
	t1.number_of_nodes = 3;
	t2.number_of_nodes = 5;
	t1.time = 1;
	t2.time = 1;
	Queue_task tmp;
	tmp.Push(t1);
	tmp.Push(t2);
	tmp = Cl.SetTask(tmp);
	EXPECT_EQ(0, tmp.GetSize());
	EXPECT_EQ(2, Cl.GetSize());
}
TEST(Test_Claster, CanMakeTakt) {
	Claster Cl;
	Task t1, t2;
	t1.number_of_nodes = 3;
	t2.number_of_nodes = 5;
	t1.time = 1;
	t2.time = 1;
	Queue_task tmp;
	tmp.Push(t1);
	tmp.Push(t2);
	tmp = Cl.SetTask(tmp);
	Cl.maketakt();
	EXPECT_EQ(2, Cl.GetMakeTask());
}
TEST(Test_Claster, CanGetMakingTasks) {
	Claster Cl;
	Task t1, t2;
	t1.number_of_nodes = 3;
	t2.number_of_nodes = 5;
	t1.time = 1;
	t2.time = 1;
	Queue_task tmp;
	tmp.Push(t1);
	tmp.Push(t2);
	tmp = Cl.SetTask(tmp);
	Cl.maketakt();
	EXPECT_EQ(2, Cl.GetMakeTask());
}
TEST(Test_Claster, CanGetSize) {
	Claster Cl;
	Task t1, t2;
	t1.number_of_nodes = 3;
	t2.number_of_nodes = 5;
	t1.time = 4;
	t2.time = 4;
	Queue_task tmp;
	tmp.Push(t1);
	tmp.Push(t2);
	tmp = Cl.SetTask(tmp);
	Cl.maketakt();
	EXPECT_EQ(2, Cl.GetSize());
}
TEST(Test_Claster, CanGetWorkload) {
	Claster Cl;
	Task t1, t2;
	t1.number_of_nodes = 31;
	t2.number_of_nodes = 1;
	t1.time = 1;
	t2.time = 1;
	Queue_task tmp;
	tmp.Push(t1);
	tmp.Push(t2);
	tmp = Cl.SetTask(tmp);
	Cl.maketakt();
	EXPECT_EQ(0.5, Cl.GetWorkload());
}
TEST(Test_Claster, CantSetTooBigTask) {
	Claster Cl;
	Task t1, t2;
	t1.number_of_nodes = 100;
	t1.time = 1;
	Queue_task tmp;
	tmp.Push(t1);
	ASSERT_ANY_THROW(Cl.SetTask(tmp));
}