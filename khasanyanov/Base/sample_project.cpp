#include "cluster.h"
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;


int main()
{
    HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_GREEN | 0);
    string expression;
    setlocale(LC_ALL, "ru");
    setlocale(LC_NUMERIC, "en");
    system("title Имитация работы кластера");
    Cluster c;
    c.start();
    cout << c.get_stat().executed_tasks << endl <<  c.get_stat().failed_tasks << endl << c.get_stat().summary_tasks << endl << c.get_stat().I << endl << c.get_stat().free_tacts;
    return 0;
}
