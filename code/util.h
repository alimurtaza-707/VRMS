#ifndef UTIL_H
#define UTIL_H
#include <iostream>
#include <string>
using namespace std;

struct NumberPlate {
    string state;
    int number;
    NumberPlate(string s, int n) : state(s), number(n) {}
    NumberPlate() : state(""), number(0) {}
    bool operator==(const NumberPlate& other) const {
        return state == other.state && number == other.number;
    }
    bool operator!=(const NumberPlate& other) const {
        return !(*this == other);
    }
    friend ostream& operator<<(ostream& os, const NumberPlate& np) {
        os << np.state << "-" << np.number;
        return os;
    }
};

struct date{
    int day;
    int month;
    int year;
    date(int d, int m, int y) : day(d), month(m), year(y) {}
    date() : day(0), month(0), year(0) {}
    bool operator==(const date& other) const {
        return day == other.day && month == other.month && year == other.year;
    }
    bool operator!=(const date& other) const {
        return !(*this == other);
    }
    friend ostream& operator<<(ostream& os, const date& d) {
        os << d.day << "/" << d.month << "/" << d.year;
        return os;
    }
};

#endif