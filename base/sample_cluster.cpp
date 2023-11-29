#include <locale>
#include <iostream>
#include "Simulation.h"

using namespace std;

void main() {

   setlocale(LC_ALL, "Russian");

   int k, N, T;
   double L;

   while (true) {

      cout << "Введите количество задач, которое может появится на одном такте - k (1 <= k <= 10): ";
      cin >> k;

      cout << "Введите вероятность появления задачи на очередном такте - L (0 < L < 1): ";
      cin >> L;

      cout << "Введите количество узлов в кластере - N (16 <= N <= 64): ";
      cin >> N;

      cout << "Введите количество тактов работы кластера - T: ";
      cin >> T;

      if (k > 10 || k < 1 || L <= 0 || L >= 1 || N < 16 || N > 64 || T < 1) {
         cerr << "Неверные параметры. Повторите ввод." << endl;
         continue;
      }

      break;

   }

   Simulation simulation(N, L, k);

   for (int i = 0; i < T; ++i) {
      cout << "\n\tТакт " << i + 1 << ":" << endl;
      simulation.processingTact();
      system("pause");
   }

   simulation.showFinalStatistics(T);
}