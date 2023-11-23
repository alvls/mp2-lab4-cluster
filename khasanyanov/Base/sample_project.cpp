#include "cluster.h"
#include "console.h"
#include "visualizer.h"
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

void main()
{
    Console::init();
    setlocale(LC_ALL, "ru");
    Console::textcolor(Console::TColor::GREEN);
    system("title Имитация работы кластера");
    cout << "Введите количество узлов кластера:" << endl;
    cout << "Введите количество тактов работы:" << endl;
    cout << "Введите вероятность появления задачи на такте:" << endl;
    size_t nodes, tacts;
    double lambda;
    Console::gotoxy(35, 0);
    cin >> nodes;
    Console::gotoxy(34, 1);
    cin >> tacts;
    Console::gotoxy(47, 2);
    cin >> lambda;
    Cluster c(nodes, tacts, lambda);
    Visualizer v(c);
    Console::hidecursor();
    c.start([&]() {Console::clear(); v.draw(0,0); Console::flush(); Sleep(10); });
    v.draw_result(0, 0);
    Console::gotoxy(0, 6);
}
