#include "machWord.h"

using namespace std;

machWord::machWord(): n(0), S('E') {
    this->mA = 0;
}


machWord::machWord(char c): n(0), S(c) {
    for (int i = 0; i < 10; ++i) {
        if(rand() % 2)
        {
            mA |= (1 << i);
            n++;
        }

    }
}


void machWord::show() {
    cout << endl << S << ":";

    for (int i = 0; i < 10; ++i) if ((mA >> i) & 1) cout << char(i + '0') << " ";
}


machWord &machWord::operator=(const machWord &B) {
    this->mA = B.mA;
    return *this;
}


machWord &machWord::operator|=(const machWord &B) {
    this->mA |= B.mA;
    return *this;
}


machWord &machWord::operator&=(const machWord &B) {
    this->mA &= B.mA;
    return *this;
}


machWord machWord::operator|(const machWord &B) const {
    machWord C(*this);
    return (C |= B);
}


machWord machWord::operator&(const machWord &B) const {
    machWord C(*this);
    return (C &= B);
}
