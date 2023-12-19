#include "cluster_manager.cpp"
#include <iostream>
#include <locale>

using namespace std;

int main(){
	setlocale(LC_ALL, "rus");
	int Tmax;
	double alph;
	cout << "Óêàæèòå ñêîëüêî òàêòîâ áóäåò ðàáîòàòü ïðîãðàììà: ";
	cin >> Tmax;
	cout << "Введите порог появления задачи: "; //задача будет появляться, если сгенерированное 
						//значение в кластере превысит порог
	cin >> alph;
	Cluster_manager cl(Tmax);
	while (!cl.Finish()) {
		cl.Computation(alph);
		cout << cl;
		system("pause");
		system("cls");
	}
	cout << "Âûïîëíåííûõ çàäàíèé " << cl.finishedTasks() << endl;
	cout << "Íåâûïîëíåííûõ çàäàíèé " << cl.failedTasks();
	return 0;
}
