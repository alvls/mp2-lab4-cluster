#include "cluster.h"
#include "gtest.h"

TEST(Cluster, test) {
	Cluster c;
	int count = 0;
	while (count < 10) {
		c.generate_tasks();
		cout << "tasks generated" << endl;
		c.process_tasks();
		cout << "tasks working" << endl;
		cout << c.get_stat().executed_tasks << endl;
		cout << c.get_stat().failed_tasks << endl;
		cout << c.get_stat().I << endl;
		count++;
	}
	ASSERT_NO_THROW(c.start());
}