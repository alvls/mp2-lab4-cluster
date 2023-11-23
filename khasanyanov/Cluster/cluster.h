#ifndef __CLUSTER_H__
#define __CLUSTER_H__

#include "task.h"
#include "queue.h"
#include <vector>
#include <functional>



using namespace std;

class Cluster {
	struct Statistic {						// ���������� ������ ��������
		size_t executed_tasks = 0;			// ����������� ������
		size_t failed_tasks = 0;			// ������������� ������
		size_t summary_tasks = 0;			// ����� ���-�� �����
		size_t free_tacts = 0;				// ����� �������
		size_t T = 1;
		double I = 0.0;                     // ������� ��������
	};										 
private:									 
	const double MinValueOfLambda = 0.333;	// ������ ������� ������
	const size_t MaxTasksForTact = 3;		// ������������ ���������� ����� ����� �� ����
	size_t nodes;							// ���-�� �����
	size_t tacts;							// ���-�� ������ ������ ��������
	size_t busy_nodes;						// ������� ����
	Queue<Task> queue;						// ������� �����
	vector<Task> tasks;						// ����������� ������
	double lambda;							// ����������� ��������� ������ �� �����
	Statistic statistic;					// ����������
	void process_tasks();					// ���������� �����
	void generate_tasks();					// ��������� �����
	void update_stat();						// ������� ����������
public:
	Cluster();								// ����������� �� ���������
	Cluster(size_t N, size_t T);			// �����������-�������������
	Cluster(size_t N, size_t T, double L);	// �����������-�������������
	void start(const function<void(void)>& f);	// ������ ������ ��������
											//�������
	size_t get_nodes() const noexcept;		
	size_t get_tacts() const noexcept;		
	size_t get_busy_nodes() const noexcept; 
	double get_lambda() const noexcept;
	vector<Task> get_tasks() const;
	Queue<Task> get_queue() const; 
	Statistic get_stat() const;
};

#endif
