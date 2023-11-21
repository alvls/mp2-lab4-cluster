#ifndef __TASK_H__
#define __TASK_H__

#include"queue.h"
#include <ctime>

const size_t MaxTactsOfTask = 6;

using namespace std;

class Task {							
	size_t number, 						// ����� ������
	tacts, 								// ���-�� ������ ��� ����������
	nodes;								// ���-�� ���������� �����
	bool closed;						// ��������� ������
public:									
	Task();								// ����������� �� ���������
	Task(size_t Nodes);					// �����������-�������������
	void work();						// ��������� ������ �� ���� ����
	bool is_closed() const noexcept;	// ��������� �� ������
	                                    // �������
	size_t get_nodes() const noexcept;	
	size_t get_tacts() const noexcept;	
	size_t get_number() const noexcept; 
};

#endif
