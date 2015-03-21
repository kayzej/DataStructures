#include <iostream>
#include "time.h"

using namespace std;

Time::Time(){
    hour = 0;
    minute = 0;
    second = 0;
}

Time::Time(int aHour, int aMinute, int aSecond){
    hour = aHour;
    minute = aMinute;
    second = aSecond;
}

int Time::getMinute() const{
    return minute;
}

int Time::getHour() const{
    return hour;
}

int Time::getSecond() const{
    return second;
}

void Time::setMinute(int m){
    minute = m;
}

void Time::setHour(int h){
    hour = h;
}

void Time::setSecond(int s){
    second = s;
}

void Time::PrintAmPm(){
    bool am = true;
    int hour = this->hour;
    int minute = this->minute;
    int second = this->second;
    
    if (hour > 12){
        cout << hour - 12;
        am = false;
    }
    else{
        cout << hour;
    }
    
    cout << ":" << minute << ":" << second;
    
    if (am){
        cout << " am";
    }
    else{
        cout << " pm";
    }
    cout << endl;
}