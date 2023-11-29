#include <iostream>
#include "cluster.h"
#include <ctime>
using namespace std;
int main()
{
	int size, tacts, n, k;
	double frequency;
	srand(time(NULL));
	cout << "Enter queue size (from 5 to 100)" << endl;
	cin >> size;
	cout << "Enter the number of program tacts(from 5 to 100)" << endl;
	cin >> tacts;
	cout << "Enter the number of node(from 16 to 64)" << endl;
	cin >> n;
	cout << "Enter how many tasks can appear on each tact (minimum 1) " << endl;
	cin >> k;
	cout << "Enter the frequency of occurrence of the task (from 0 to 1) " << endl;
	cin >> frequency;
	Cluster c(size, tacts, n, k, frequency);
	cout << c.Process() << endl;
	return 0;
}