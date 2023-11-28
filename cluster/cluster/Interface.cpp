#include <iostream>
#include <string>
#include "Interface.h"
#include "Console.h"

using namespace std;


cluster_interface::cluster_interface() { 
	
	system("mode con cols=93 lines=23"); 
	system("title Cluster");
	hidecursor();
}

void cluster_interface::label(string label, int x, int y) { gotoxy(x, y); cout << label; }

void cluster_interface::drawProcess(task newTask, int x, int y) {

	string progressLine = "====================";
	string emptyLine = "....................";
	int symb = 20 / (newTask.getTañts() + 1);
	
	gotoxy(x, y);
	cout << "Çàäà÷à ¹" << newTask.getId() << " [" << progressLine.substr(0, symb) + emptyLine.substr(symb, 20) << "]";
}

void cluster_interface::drawField() {

	for (int i = 0; i < 20; i++)
	{
		gotoxy(2, 1 + i);
		cout << '|';
		gotoxy(43, 1 + i);
		cout << '|';
		gotoxy(90, 1 + i);
		cout << '|';
	}
	for (int i = 0; i < 88; i++)
	{
		gotoxy(3 + i, 1);
		cout << '|';
		gotoxy(3 + i, 20);
		cout << '|';
	}
}
