#ifndef TASK_H
#define TASK_H

// ����������� ������ Task
class Task {
public:
  int id;             // ������������� ������
  int ticksToComplete; // ���������� ������ ��� ����������
  int nodesRequired;   // ���������� �����, ����������� ��� ���������� ������

  Task(int id, int duration, int nodes); // �����������
};

#endif // TASK_H
