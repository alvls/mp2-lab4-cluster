#include "cluster.h"
#include "console.h"
#include "visualizer.h"
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
    Console::init();
    Console::textcolor(Console::TColor::GREEN);
    
    system("title Имитация работы кластера");
    Cluster c;
    Visualizer v(c);
    Console::hidecursor();
    Console::set_pixel_foreground(Console::RED);
    c.start([&]() {Console::clear(); v.draw(); Console::flush();});// [&]() {console.clear();  cout << "Такт номер: " << c.get_stat().T << " " << "Выполнено задач: " << c.get_stat().executed_tasks << endl; console.flush(); });
    int i = 0;
   
    /*while (i < 100) {
        Console::clear();
        Console::write(1, 0, L"█");
        v.draw();
        Console::flush();
        i++;
        Sleep(1000);
    }*/
    /*cout << "Выполнено задач: " << c.get_stat().executed_tasks << endl;
    cout << "Не выполнено задач: " << c.get_stat().failed_tasks << endl;
    cout << "Всего задач: " << c.get_stat().summary_tasks << endl;
    cout << "Тактов простоя: " << c.get_stat().free_tacts << endl;
    cout << "Средняя загрузка кластера: " << c.get_stat().I * 100. << "%" << endl;*/
    return 0;
}
