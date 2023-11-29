#include "cluster.h"
#include <vector>
#include <iostream>
#include <ctime>

const int MinN = 16; // ����������� ����� �����
const int MaxN = 64; // ������������ ����� ����� 
const int MinTacts = 5; // ����������� ���������� ������ ������ ��������
const int MaxTacts = 100; // ������������ ���������� ������ ������ ��������
const int MaxDuration = 15; // ������������ ������������ ���������� �������
const int MinSize = 5; // ����������� ������ �������
const int MaxSize = 100; // ������������ ������ �������
const double MinF = 0.0; 
const double MaxF = 1.0; 

using namespace std;

Task Cluster::CreateTask(int n) {
	Task t;
	t.node = 1 + rand() % n;
	t.tact = 1 + rand() % MaxDuration;
	return t;
}

Cluster::Cluster(int s, int t, int n, int k, double f) {
	if (s > MaxSize || s < MinSize) {
		throw "Incorrect size";
	}
	if (t > MaxTacts || t < MinTacts) {
		throw "Incorrect number of tacts";
	}
	if (n > MaxN || n < MinN) {
		throw "Incorrect number of node";
	}
	if (k < 1) {
		throw "At each tact there should be the possibility of at least 1 task appearing";
	}
	if (f > MaxF || f < MinF) {
		throw "Frequency must range from 1 to 0";
	}
	size = s;
	tacts = t;
	N = n;
	K = k;
	frequency = f;
}

Statistics Cluster::Process() {
	Statistics st;
	st.ttime = tacts;
	int freeN = N;
	st.AverageClusterLoad = 0.0;
	TQueue<Task> queue(size);
	vector<Task> InProgress;
	for (int i = 0; i < st.ttime; i++) {
		for (int i = 0; i < K; i++) { // �������� � ���������� ����� � ������� 
			if ((double(rand()) / RAND_MAX) <= frequency) {
				Task t;
				t = CreateTask(N);
				if (!queue.IsFull()) { 
					queue.Push(t);
					st.AllTasks++;
				}
			}
		}

		while (!queue.IsEmpty() && freeN >= queue.ViewFirst().node) { // ���������� � ������ �� ���������� 
			Task tt;
			tt = queue.Pop();
			InProgress.push_back(tt);
			freeN -= tt.node;
		}

		if (InProgress.size() != 0) { // �������� ����� � �������
			int i = 0;
			while (i < InProgress.size()) {
				InProgress[i].tact--;
				if (InProgress[i].tact == 0) {
					freeN += InProgress[i].node;
					InProgress.erase(InProgress.begin() + i);
					st.CompletedTasks++;
				}
				i++;
			}
		}
		if (InProgress.size() == 0) {
			st.�lusterIdleTacts++;
		}
		st.AverageClusterLoad += ((static_cast<double>(N) - freeN) / N);
	}
	st.TasksLeftInQueue = queue.GetSize();
	st.TasksInProgress = InProgress.size();
	st.UnfulfilledTasks = st.AllTasks - st.CompletedTasks;
	st.AverageClusterLoad = (st.AverageClusterLoad / st.ttime) * 100;
	return st;
}
ostream& operator<< (ostream& out, const Statistics& st) { //����� ����������
	cout << "Statistics:" << endl;
	cout << "Number of operating tacts: " << st.ttime << endl;
	cout << "Total tasks created: " << st.AllTasks << endl;
	cout << "Completed tasks: " << st.CompletedTasks << endl;
	cout << "Number of tasks not completed: " << st.UnfulfilledTasks << endl;
	cout << "     -Tasks remaining in the queue: " << st.TasksLeftInQueue << endl;
	cout << "     -Tasks in progress: " << st.TasksInProgress << endl;
	cout << "Number of cluster idle tacts: " << st.�lusterIdleTacts << endl;
	cout << "Average cluster load: " << st.AverageClusterLoad << "%" << endl;
	return out;
}