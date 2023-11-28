#include "cluster.h"

Cluster::Cluster(double _Tmax, int _alpha, double _N, int _k)
{
	Tmax = _Tmax;
	T = 0;
	alpha = _alpha;
	N = _N;
	n = _N;
	k = _k;
	busy = 0.0;
	zv = 0;
	zn = 0;
}
bool Cluster::GenerateNewTask()
{
	if (1 + rand() % 100 <= alpha)
		return true;
	return false;
}
void Cluster::ClusterWork()
{
	TQueue<Task> q;
	vector<Task> work;
	for (int i = 0; i < Tmax; i++)
	{
		for (int j = 0;j < k;j++)
		{
			if (GenerateNewTask())
			{
				Task ttmp;
				q.Put(ttmp);
			}
		}
		for (int j = 0;j < work.size();j++)
		{
			work[j].ChangeT();
			if (work[j].GetTime() == 0)
			{
				n += work[j].GetNode();
				work.erase(work.begin() + j);
				zv++;
			}
		}
		if (!q.IsEmpty())
		{
			for (int j = 0;j < q.GetSize();j++)
			{
				Task tmp(q.GetFirst());
				if (tmp.GetNode() <= n)
				{
					n -= tmp.GetNode();
					work.push_back(tmp);
					q.RemoveFirst();
				}
				else
					break;
			}
		}
		busy += n / N;
		T++;
	}
	busy = (busy / Tmax) * 100;
	zn = q.GetSize() + work.size();
}