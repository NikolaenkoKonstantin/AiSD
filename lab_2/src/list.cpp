#include "list.h"

using namespace std;

int list :: N = 10;
int list :: cnt = 0;

list :: list(char):n(0), S('A' + cnt++), pH(nullptr)
{
    pH = new node();
    node *tmp = pH;

    for(int i = 0; i < N; i++){
        if(rand() % 2) {
            tmp->next = new node('0' + i);
            tmp = tmp->next;
            n++;
        }
    }
}


list :: list(const list& B):n(B.n), S('A' + cnt ++)
{
    pH = new node(B.pH->el);
    node *tmp = pH, *tmp1 = B.pH->next;

    for(int i = 1; i < B.n; i++){
        tmp->next = new node(tmp1->el);
        tmp = tmp->next;
        tmp1 = tmp1->next;
    }
}


bool is_belong(node *l, char el)
{
    for(node *pL = l; pL; pL = pL->next){
        if(pL->el == el) return true;
    }

    return false;

}


list & list :: operator &= (const list &B)
{
    list C(*this);

    node *i = pH->next;
    while(i){
        node * t = i;
        i = i->next;
        delete t;
    }

    delete pH;

    n = 0;

    node *pA = C.pH;
    for(node *pB = B.pH; pB; pB = pB->next) {
        if(is_belong(pA,pB->el)){
            if(n == 0) {pH = new node(pB->el);}
            else {
                node *tmp1 = pH;
                while(tmp1->next) tmp1 = tmp1->next;
                tmp1->next = new node(pB->el);
            }
            n++;
        }
    }

    return *this;
}


list list :: operator & (const list &B) const
{
    list C(*this);

    return (C &= B);
}


list & list :: operator |= (const list &B)
{
    for(node *pB = B.pH; pB; pB = pB->next){
        if(!is_belong(pH, pB->el)){
            node *tmp = pH;
            while(tmp->next) tmp = tmp->next;
            tmp->next = new node(pB->el);
            n++;
        }
    }
    n--;

    return *this;
}


list list :: operator | (const list &B) const
{
    list C(*this);

    return (C|=B);
}


list & list :: operator = (const list &B)
{
    if(this != &B){
        S = 'A' + cnt++;

        if(n == 0) pH = new node(B.pH->el);
        node *tmp2 = B.pH->next;

        for(int i = 1; i < B.n; i++){
            node *tmp1 = pH;
            while(tmp1->next) tmp1 = tmp1->next;
            tmp1->next = new node(tmp2->el);
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }

        n = B.n;
    }

    return *this;
}


void list :: Show()
{
    using namespace std;

    node *tmp = pH;

    cout << S << ": ";

    for(int i = 0; i < n; i++, tmp = tmp->next) cout << tmp->el << " ";
}


list :: ~list()
{
    node *tmp = pH, *tmp1;

    for(int i = 0; i < n; i++){
        tmp1 = tmp->next;
        delete tmp;
        tmp = tmp1;
    }

    delete tmp;
}
