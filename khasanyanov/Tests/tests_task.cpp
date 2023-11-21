#include "task.h"
#include "gtest.h"

TEST(Task, can_create_task_default_constructor) {
	ASSERT_NO_THROW(Task t);
}

TEST(Task, can_create_task_one_param_constructor) {
	ASSERT_NO_THROW(Task t(50));
}

TEST(Task, can_work_task) {
	Task t;
	ASSERT_NO_THROW(t.work());
}

TEST(Task, method_work_chhange_value_of_tacts) {
	Task t;
	size_t tact = t.get_tacts();
	t.work();
	EXPECT_EQ(tact - 1, t.get_tacts());
}