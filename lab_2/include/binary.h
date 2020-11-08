#pragma once
#include <random>
#include <iostream>

class binary {
private:
    char S;
    int n;
    bool bA[10];
public:
    binary();
    binary(char c);

    binary operator | (const binary &B) const;
    binary operator & (const binary &B) const;

    binary & operator = (const binary &B);
    binary & operator &=(const binary &B);
    binary & operator |=(const binary &B);

    void show();
    int power(){return n;}
};
