#include <cstdlib>
#include <ctime>
class Task
{
private:
	int p; //кол-во узлов для выполнения
	int tz; //время выполнения в тактах
public:
	Task() {};
	Task(int N) {
		srand(time(NULL));
		p = 1 + rand() % (N - 1);
		tz = 1 + rand() % 25;
	}
	int getNode() { return p; }
	int getTaсt() { return tz; }
	void eraseTacts() { tz--; }
};

