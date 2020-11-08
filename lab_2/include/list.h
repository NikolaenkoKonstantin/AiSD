#pragma once
#include <random>
#include <iostream>
#include <cstring>

struct node
{
    char el;
    node *next;

    node(char e = 0, node *n = nullptr){
        el = e;
        next = n;
    }
};

class list
{
    private:
        static int N, cnt;
        int n;
        char S;

        node *pH;

    public:
        list(): n(0), S('A' + cnt++), pH(nullptr){}
        list(char);
        list(const list &);
        ~list();

        list & operator &= (const list &);
        list operator & (const list &) const;
        list & operator = (const list &);
        list & operator |= (const list &);
        list operator | (const list &) const;

        void *operator new(size_t size){return malloc(size);}
        void operator delete(void *p){free(p);}

        int power(){ return n;}
        void Show();
};
