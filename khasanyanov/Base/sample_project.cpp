#include "cluster.h"
#include "console.h"
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
    Console console;
    console.textcolor(Console::TColor::GREEN);
    setlocale(LC_ALL, "ru");
    setlocale(LC_NUMERIC, "en");
    system("title Имитация работы кластера");
    Cluster c;
    console.hidecursor();
    //c.start([&]() {console.clear();  cout << "Такт номер: " << c.get_stat().T << " " << "Выполнено задач: " << c.get_stat().executed_tasks << endl; console.flush(); });
    int i = 0;
    console.set_pixel_foreground(Console::RED);
    while (i < 100) {
        console.clear();
        console.set_pixel(1, 0, '▇');
        console.flush();
        i++;
        Sleep(1000);
    }
    /*cout << "Выполнено задач: " << c.get_stat().executed_tasks << endl;
    cout << "Не выполнено задач: " << c.get_stat().failed_tasks << endl;
    cout << "Всего задач: " << c.get_stat().summary_tasks << endl;
    cout << "Тактов простоя: " << c.get_stat().free_tacts << endl;
    cout << "Средняя загрузка кластера: " << c.get_stat().I * 100. << "%" << endl;*/
    return 0;
}
