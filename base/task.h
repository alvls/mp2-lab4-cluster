#ifndef __TASK_H__
#define __TASK_H__

struct Task {

   int p; // Кол-во узлов для выполнения
   int t; // Время выполнения(в тактах)

   Task() : p(0), t(0) {}
   Task(int _p, int _t) : p(_p), t(_t) {}

};
#endif