#pragma once
#include <random>
#include <iostream>

class machWord {
private:
    long mA;
    int n;
    char S;
public:
    machWord();
    machWord(char c);

    void show();
    int power(){return n;}

    machWord operator | (const machWord &B) const;
    machWord operator & (const machWord &B) const;

    machWord & operator = (const machWord &B);
    machWord & operator &=(const machWord &B);
    machWord & operator |=(const machWord &B);
};
