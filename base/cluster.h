#ifndef __CLUSTER_H__
#define __CLUSTER_H__

#include "task.h"
#include "queue.h"
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int TASK_ID_IDLE = -1;

class Cluster {
private:

   int tasksInProgress = 0;
   int tasksTotal = 0;
   int tasksCompleted = 0;
   int tasksUncompleted = 0;
   double overallLoadPercent = 0.0;
   int lastTaskId = 0;
   map<int, int> taskStates;

   struct Node {
      int timeToFinish;
      int taskId = TASK_ID_IDLE;
      Node();
      bool isBusy() const { return taskId != TASK_ID_IDLE; }
   };

   vector<Node> Nodes;

public:

   TQueue<Task> TaskQueue;

   Cluster(int totalNodes);

   int getCompletedTaskCount() const;
   int getUncompletedTaskCount() const;
   int getTotalTaskCount() const;
   int getCurrentTaskCount() const;
   int calculateBusyNodeCount() const;

   double getAverageLoadPercent(int T) const;
   double calculateLoadPercentage() const;

   void enqueueTask(const Task& _task);
   void updateLoadPercent(double l);
   void assignTasks();
   void updateTaskStatus();

};

#endif