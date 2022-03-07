#include <unistd.h>
#include <iostream>
#include "Timer.h"
using namespace std;

int main()
{
    Timer timer;
    cout << "Created a timer with default time of 120 seconds." << endl;
    sleep(3);
    cout << "Time left: " << timer.getTime() << " seconds." << endl;
    sleep(1);
    cout << "Setting new time of 5 seconds." << endl;
    timer.setTime(5);
    sleep(6);
    cout << "Timer should be done. Time left on timer: " << timer.getTime() << " seconds." << endl;
    timer.setTime(100);
    cout << "Setting new time of 100 seconds." << endl;
    sleep(2);
    cout << "Time left: " << timer.getTime() << " seconds. Program will end when the timer finishes."  << endl;
    return 0;
}
