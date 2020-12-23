#ifndef GRAF_H
#define GRAF_H
#include <iostream>

class graf
{
    static const int gSize = 10;
    bool g[gSize][gSize]{};
    int color[gSize]{};

public:
    graf(int a);

    void PrintGraph();

    void SetColor(int s, int col, int t);

    void Set1();

    void Print(int& count, int color2[gSize], int* result, int s, int col, int t);

    void Search();
};

#endif // GRAF_H
