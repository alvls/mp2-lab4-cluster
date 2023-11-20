#include <iostream>
#include "cluster.h"

using namespace std;

int main()
{
    Cluster c;
    srand(time(0));
    c.start();
    cout << c.get_stat().executed_tasks << endl <<  c.get_stat().failed_tasks << endl << c.get_stat().summary_tasks << endl << c.get_stat().I << endl;
    return 0;
}
