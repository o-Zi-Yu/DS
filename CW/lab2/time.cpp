#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#include "time.h"

Time::Time(){
    hour = 0;
    minute = 0;
    second = 0;
}

Time::Time(int ahour, int aminute, int asecond) {
    hour = ahour;
    minute = aminute;
    second = asecond;
}

int Time::getHour() const {
    return hour;
}
int Time::getMinute() const {
    return minute;
}
int Time::getSecond() const {
    return second;
}

void Time::setSecond(int s_second) {
    second = s_second;
}

void Time::setMinute(int s_minute) {
    minute = s_minute;
}

void Time::setHour(int s_hour) {
    hour = s_hour;
}

void Time::PrintAMPM() const {
    if (hour > 12) {
        if (second >= 0 && second < 10){
            if (minute >= 0 && minute < 10) {
                std::cout << hour - 12 << ":0" << minute << ":0" << second << " pm" << std::endl;
            }
            else {
                std::cout << hour - 12 << ":" << minute << ":0" << second << " pm" << std::endl;
            }
        }
        else if (minute >= 0 && minute < 10) {
            std::cout << hour - 12 << ":0" << minute << ':' << second << " pm" << std::endl;
        }
        else {
            std::cout << hour -12 << ':' << minute << ':' << second << " pm" << std::endl;
        }
    }

    if (hour == 12) {
        if (second >= 0 && second < 10){
            if (minute >= 0 && minute < 10) {
                std::cout << "12:0" << minute << ":0" << second << " pm" << std::endl;
            }
            else {
                std::cout << "12:" << minute << ":0" << second << " pm" << std::endl;
            }
        }
        else if (minute >= 0 && minute < 10) {
            std::cout << "12:0" << minute << ':' << second << " pm" << std::endl;
        }
        else {
            std::cout << "12:" << minute << ':' << second << " pm" << std::endl;
        }
    }

    if (hour < 12 && hour > 0) {
        if (second >= 0 && second < 10){
            if (minute >= 0 && minute < 10) {
                std::cout << hour << ":0" << minute << ":0" << second << " am" << std::endl;
            }
            else {
                std::cout << hour << ":" << minute << ":0" << second << " am" << std::endl;
            }
        }
        else if (minute >= 0 && minute < 10) {
            std::cout << hour << ":0" << minute << ':' << second << " am" << std::endl;
        }
        else {
            std::cout << hour << ':' << minute << ':' << second << " am" << std::endl;
        }
    }

    if (hour == 0) {
        if (second >= 0 && second < 10){
            if (minute >= 0 && minute < 10) {
                std::cout << "12:0" << minute << ":0" << second << " am" << std::endl;
            }
            else {
                std::cout << "12:" << minute << ":0" << second << " am" << std::endl;
            }
        }
        else if (minute >= 0 && minute < 10) {
            std::cout << "12:0" << minute << ':' << second << " am" << std::endl;
        }
        else {
            std::cout << "12:" << minute << ':' << second << " am" << std::endl;
        }
    }
}


bool IsEarlierThan(const Time& t1, const Time& t2){
    if (t1.getHour() < t2.getHour() ||
        (t1.getHour() == t2.getHour() && t1.getMinute() < t2.getMinute()) ||
        (t1.getHour() == t2.getHour() && t1.getMinute() == t2.getMinute() && t1.getSecond() < t2.getSecond())){
        return true;
    }
    else {
        return false;
    }
}