#ifndef TASK_H
#define TASK_H

// Определение класса Task
class Task {
public:
  int id;             // Идентификатор задачи
  int ticksToComplete; // Количество тактов для выполнения
  int nodesRequired;   // Количество узлов, необходимых для выполнения задачи

  Task(int id, int duration, int nodes); // Конструктор
};

#endif // TASK_H
