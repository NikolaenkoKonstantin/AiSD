#include "array.h"

using namespace std;

int Set :: N = 10;
int Set :: cnt = 0;

Set :: Set(const Set &B):S('E'), n(B.n), A(new char[N + 1])
{
    char *dst(A), *src(B.A);
    while(*dst++ = *src++);
}


Set :: Set(): n(0), S('E'), A(new char[N + 1]) {A[0] = 0;}


Set :: Set(char c): S(c), n(0), A(new char[N + 1])
{
    for(int i = 0; i < N; i ++)
        if(rand() % 2) A[n++] = i + '0';
    A[n] = 0;
}


Set & Set :: operator &= (const Set &B)
{
    Set C(*this);
    n = 0;
    for(int i = 0; i < C.n; i++)
    {
        for(int j = 0; j < B.n; j++)
            if(C.A[i] == B.A[j]) A[n++] = C.A[i];
    }
    A[n] = 0;
    return *this;
}


Set Set::operator&(const Set &B) const {
    Set C(*this);
    return (C &= B);
}


Set & Set :: operator |= (const Set &B)
{
    for(int i = 0; i < B.n; i++)
    {
        bool f = true;
        for(int j = 0; j < n; j++)
            if(B.A[i] == A[j]) f = false;
        if(f) A[n++] = B.A[i];
    }
    A[n] = 0;
    return *this;
}


Set Set::operator|(const Set &B) const {
    Set C(*this);
    return (C |= B);
}


Set & Set::operator = (const Set &B) {
    if(this != &B)
    {
        char *dst(A), *src(B.A);
        n = B.n;
        while(*dst++ = *src++);
        S = 'E';
    }
    return *this;
}


void Set::show() {
    std :: cout << std :: endl << S << ": ";
    for(int i = 0; i < this->n; i++)
        std :: cout << A[i] << " ";
}
