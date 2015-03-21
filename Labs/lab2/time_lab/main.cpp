#include <iostream>
#include "time.h"

using namespace std;

int main(){
    Time time1 = Time();
    
    
    Time time2 = Time(11, 13, 35);
    
    cout << time2.getHour() << " " << time2.getMinute() << " " << time2.getSecond() << endl;
    
    time1.setHour(4);
    time1.setMinute(23);
    time1.setSecond(12);
    
    cout << time1.getHour() << " " << time1.getMinute() << " " << time1.getSecond() << endl;

    time1.PrintAmPm();
    
    return 0;
}