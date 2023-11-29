#pragma once
#ifndef _Cluster_
#define _Cluster_
#include "queue.h"
#include <ctime>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Task {
	int node; // ���������� ����� ��� ����������
	int tact; // ���������� ������ ��� ����������
};

struct Statistics {
	int AllTasks = 0; // ����� ����������� ������� 
	int CompletedTasks = 0; //����� ����������� �������
	int UnfulfilledTasks = 0;// ����� ������������� �������
	int TasksLeftInQueue = 0; // ����� ������� ���������� � �������
	int TasksInProgress = 0; // ���������� ����������� ����� �� ������ ����������
	int �lusterIdleTacts = 0; // ����� ������ ������� ��������
	double AverageClusterLoad = 0.0; // ������� �������� ��������
	int ttime = 0; // ���������� ������ ������ ���������

	friend ostream& operator<< (ostream& out, const Statistics& st); //�������� ������
};

class Cluster {
private:
	int size = 0; // ������ �������
	int N = 0; // ���������� �����
	int K = 0; // ������������ ���������� ����� ������� ����� �������� �� ����� �����
	int tacts = 0; // ���������� ������� ������ ���������
	double frequency = 0.0; // ����������� ��������� ������

public:
	Cluster(int s, int t, int n, int k, double f); //�����������
	Task CreateTask(int n); // �������� ������
	Statistics Process(); // ��������� ������ ��������
};

#endif