#include "cluster_manager.cpp"
#include <iostream>
#include <locale>

using namespace std;

int main(){
	setlocale(LC_ALL, "rus");
	int Tmax;
	cout << "Укажите сколько тактов будет работать программа: ";
	cin >> Tmax;
	Cluster_manager cl(Tmax);
	while (!cl.Finish()) {
		cl.Computation();
		cout << cl;
		system("pause");
		system("cls");
	}
	cout << "Выполненных заданий " << cl.finishedTasks() << endl;
	cout << "Невыполненных заданий " << cl.failedTasks();
	return 0;
}