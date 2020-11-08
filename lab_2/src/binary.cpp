#include "binary.h"

using namespace std;

char U[11] = { "0123456789" }; // Universum

binary::binary(char c): S(c), n(0) {
    for (int i = 0; i < 10; ++i) {
        bA[i] = false;
    }

    for (int i = 0; i < 10; ++i) {
        if(rand() % 2)
        {
            bA[i] = 1;
            n++;
        }

    }
}


void binary::show() {
    using namespace std;
    cout << endl << S << ": ";
    for (int i = 0; i < 10; ++i) {
        if (bA[i]) cout << U[i] << " ";
    }
}


binary::binary(): S('E'), n(0) {
    for (int i = 0; i < 10; ++i) {
        bA[i] = false;
    }
}


binary binary::operator|(const binary &B) const {
    binary C(*this);
    return (C |= B);
}


binary binary::operator&(const binary &B) const {
    binary C(*this);
    return (C &= B);
}


binary & binary::operator=(const binary &B) {
    for(int i = 0; i < 10; i++)
        this->bA[i] = B.bA[i];
    return *this;
}


binary & binary::operator|=(const binary &B) {
    for (int i = 0; i < 10; ++i) {
        this->bA[i] = this->bA[i] || B.bA[i];
    }
    return *this;
}


binary & binary::operator&=(const binary &B){
    for (int i = 0; i < 10; ++i) {
        this->bA[i] = this->bA[i] && B.bA[i];
    }
    return *this;
}
