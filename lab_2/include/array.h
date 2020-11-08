#pragma once
#include <random>
#include <iostream>

class Set {
private:
    static int N, cnt;
    int n;
    char S, *A;
public:
    Set operator | (const Set &B) const;
    Set operator & (const Set &B) const;

    Set & operator = (const Set &B);
    Set & operator &=(const Set &B);
    Set & operator |=(const Set &B);

    void show();
    int power(){return n;}

    Set(char);
    Set();
    Set(const Set &B);
    ~Set(){delete[]A;}
};
