#include "graf.h"

using namespace std;

graf :: graf(int a)
{
    for (int t = 0; t < a; t++)
    {
        int x = rand() % gSize;
        int y = rand() % gSize;

        if (x == y) y++;

        if (g[x][y] != 0) t--;

        g[x][y] = 1;
        g[y][x] = g[x][y];
    }
}


void graf :: PrintGraph()
{
    cout << "     ";

    for (int i = 0; i < gSize; i++) printf("%3c", 'A' + i);

    cout << "\n      ";
    cout << "-------------------------------\n";

    for (int i = 0; i < gSize; i++)
    {
        printf("  %c  ", 'A' + i);

        cout << "|";

        for (int j = 0; j < gSize; j++) printf("%3d", g[i][j]);

        cout << "\n";
    }
}


void graf :: SetColor(int s, int col, int t)
{
    color[s] = col;

    for (int j = 0; j < gSize; j++)
        if ((j != t) && (color[j] == 0) && (g[s][j] != 0))
            SetColor(j, col * -1, s);
}


void graf :: Set1()
{
    int col = 1;
    for (int i = 0; i < gSize; i++)
        if (color[i] == 0)
            SetColor(i, col, i);

    for (int i = 0; i < gSize; i++)
    {
        printf(" Color [%c] - ", 'A' + i);

        if (color[i] == 1) cout << "RED\n";

        if (color[i] == -1) cout << "BLACK\n";
    }
}


void graf :: Print(int& count, int color2[gSize], int* result, int s, int col, int t)
{
    bool flag = true;
    color2[s] = 0;

    for (int j = 0; j < gSize; j++)
        if ((j != t) && (g[s][j] != 0))
            if (color[j] != col * -1)
                flag = false;

    if (flag)
        for (int j = 0; j < gSize; j++)
            if ((j != t) && (g[s][j] != 0))
                if (color2[j] != 0)
                    Print(count, color2, result, j, col * -1, s);

    if (flag == false) count = -10;

    if (count >= 0)
    {
        result[count] = s;
        count++;
    }
}


void graf :: Search()
{
    int col = 1;
    int count = 0;
    int count2 = 1;
    int color2[gSize];
    int kod = 0;

    for (int i = 0; i < gSize; i++) color2[i] = 2;

    int result[gSize];

    for (int i = 0; i < gSize; i++)
    {
        if (color2[i] != 0)
            Print(count, color2, result, i, col, i);

        if (count > 1)
        {
            kod = 1;
            printf(" %d.", count2);
            cout << "[";

            for (int t = 0; t < count; t++)
                printf("%1c", 'A' + result[t]);

            cout << "]";
            cout << '\n';

            count2++;
        }
        count = 0;
    }

    if(!kod) cout << " NO!" << endl;
}
