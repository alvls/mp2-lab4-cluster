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
    system("title Имитация работы кластера");
    size_t nodes, tacts;
    double lambda;
    bool flag = false;
    while (!flag) {
        Console::textcolor(Console::TColor::GREEN);
        cout << "Введите количество узлов кластера:" << endl;
        cout << "Введите количество тактов работы:" << endl;
        cout << "Введите вероятность появления задачи на такте:" << endl;
        Console::showcursor();
        Console::gotoxy(35, 0);
        cin >> nodes;
        Console::gotoxy(34, 1);
        cin >> tacts;
        Console::gotoxy(47, 2);
        cin >> lambda;
        try {
            Cluster{ nodes, tacts, lambda };
            flag = true;
        }
        catch (invalid_argument) {
            Console::set_pixel_foreground(Console::LIGHTRED);
            Console::clear();
            Console::write(0, 0, L"Неверные данные");
            Console::flush();
            Console::gotoxy(0, 1);
            system("PAUSE");
            Console::clrscr();
        }
    }
    Cluster c(nodes, tacts, lambda);
    Visualizer v(c);
    Console::hidecursor();
    c.start([&]() {Console::clear(); v.draw(0,0); Console::flush(); Sleep(50); });
    v.draw_result(0, 0);
    Console::gotoxy(0, 7);
    Console::free();
}
