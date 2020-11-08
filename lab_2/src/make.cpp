#include "make.h"

//WORKING WITH AN ARRAY
using namespace std;

void makeArray()
{
    cout << "\nArray:";
    Set A('A'), B('B'), C('C'), D('D'), E;

    A.show();
    B.show();
    C.show();
    D.show();

    clock_t begin = clock();

    for (long q = 0; q < 1000000; q++)
        E = A & B | C | D;

    clock_t end = clock();

    E.show();

    int power = (A.power() + B.power() + C.power() + D.power() + E.power()) / 5;
    double time = (end - begin) * 0.017;
    cout << "\nMiddle power = " << power << "\nTicks = " << end - begin << "/1000000 ticks/raz" << "\nTime = " << time << " sec" << endl;
}

//WORKING WITH A LIST
void makeList()
{
    cout << "\nList:";
    Set A('A'),B('B'),C('C'),D('D'),E;

    A.show();
    B.show();
    C.show();
    D.show();

    clock_t begin = clock();

    for(long q = 0; q < 1000000; q++){
        E = A & B | C | D;
    }

    clock_t end = clock();

    E.show();

    int power = (A.power() + B.power() + C.power() + D.power() + E.power()) / 5;
    double time = (end - begin) * 0.017;
    cout << "\nMiddle power = " << power << "\nTicks = " << end - begin << "/1000000 ticks/raz" << "\nTime = " << time << " sec" << endl;
}

//WORKING WITH A BINARY
void makeBinary()
{
    binary bA('A'), bB('B'), bC('C'), bD('D'), bE;

    cout << "\nBinary:";
    bA.show();
    bB.show();
    bC.show();
    bD.show();

    clock_t begin = clock();

    for(int i = 0; i < 1000000; i++)
        bE = bA & bB | bC |bD;

    clock_t end = clock();

    bE.show();

    int power = (bA.power() + bB.power() + bC.power() + bD.power() + bE.power()) / 5;
    double time = (end - begin) * 0.017;
    cout << "\nMiddle power = " << power << "\nTicks = " << end - begin << "/1000000 ticks/raz" << "\nTime = " << time << " sec" << endl;
}

//WORKING WITH A MACHIN WORD
void makeMachWord()
{
    cout << "\nMachin Word:";
    machWord mA('A'), mB('B'), mC('C'), mD('D'), mE;
    mA.show();
    mB.show();
    mC.show();
    mD.show();

    clock_t begin = clock();

    for(int i = 0; i < 1000000; i++)
        mE = mA & mB | mC | mD;

    clock_t end = clock();

    mE.show();

    int power = (mA.power() + mB.power() + mC.power() + mD.power() + mE.power()) / 5;
    double time = (end - begin) * 0.017;
    cout << "\nMiddle power = " << power << "\nTicks = " << end - begin << "/1000000 ticks/raz" << "\nTime = " << time << " sec" << endl;
}
