#include "cluster.h"

Cluster::Node::Node() : timeToFinish(0) {}

Cluster::Cluster(int totalNodes) : Nodes(totalNodes) {}

void Cluster::enqueueTask(const Task& _task) {
   TaskQueue.Enqueue(_task);
   tasksTotal++;
   tasksUncompleted++;
}

void Cluster::assignTasks() {
   while (!TaskQueue.isEmpty()) {
      Task task = TaskQueue.PeekFront();
      int freeNodes = 0;

      for (auto& node : Nodes) {
         if (!node.isBusy()) {
            freeNodes++;
         }
      }

      if (!(freeNodes >= task.p)) break;
      int taskId = lastTaskId++;
      taskStates[taskId] = task.p;
      int nodesToAssign = task.p;
      for (auto& node : Nodes) {
         if (!node.isBusy() && nodesToAssign > 0) {
            node.taskId = taskId;
            node.timeToFinish = task.t;
            nodesToAssign--;
         }
      }

      tasksInProgress++;
      TaskQueue.Dequeue();
   }
}

void Cluster::updateTaskStatus() {
   vector<int> completedNodeCounts;

   for (auto& node : Nodes) {
      if (node.isBusy()) {
         node.timeToFinish--;

         if (node.timeToFinish <= 0) {
            taskStates[node.taskId]--;
            if (taskStates[node.taskId] == 0) {
               tasksCompleted++;
               tasksInProgress--;
               taskStates.erase(node.taskId);
            }
            node.taskId = TASK_ID_IDLE;
         }
      }
   }

   tasksUncompleted = tasksTotal - tasksCompleted;
}

double Cluster::calculateLoadPercentage() const {
   int busyNodeCount = count_if(Nodes.begin(), Nodes.end(), [](const auto& node) { return node.isBusy(); });
   return static_cast<double>(busyNodeCount) / Nodes.size() * 100.0;
}

int Cluster::calculateBusyNodeCount() const {
   return count_if(Nodes.begin(), Nodes.end(), [](const auto& node) { return node.isBusy(); });
}


int Cluster::getCurrentTaskCount() const { return tasksInProgress; }
int Cluster::getCompletedTaskCount() const { return tasksCompleted; }
int Cluster::getUncompletedTaskCount() const { return tasksUncompleted; }
int Cluster::getTotalTaskCount() const { return tasksTotal; }
double Cluster::getAverageLoadPercent(int T) const { return overallLoadPercent / T; }
void Cluster::updateLoadPercent(double l) { overallLoadPercent += l; }