#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <ctime>
#include <cstring>

template <class Item> class STACK
{
    Item *S;
    int t;
public:
    STACK(int maxt): S(new Item[maxt]), t(0){}
    int empty() const {return t == 0;}
    void push(Item item) {S[t++] = item;}
    Item pop(){return (t ? S[--t] : 0);}
};


class Node
{
    char c;
    int lvl;
    Node * lft;
    Node * rgt;
public:
    Node():lft(nullptr), rgt(nullptr){}
    ~Node(){if(lft) delete lft; if(rgt) delete rgt;}

    friend class Tree;
};


class Tree
{
    Node * root;
    char num, maxNum;
    int maxrow, offset;
    char ** SCREEN;

    void clrscr();
    Node * makeNodes(int depth, int mode, int prevLvl);
    void outNodes(Node *v, int r, int c);

    Tree(const Tree &);
    Tree(Tree&&);

    Tree operator = (const Tree &) const = delete;
    Tree operator = (Tree &&) const = delete;

    public:
        Tree(char num, char maxnum, int maxrow);
        ~Tree();

        void makeTree();
        bool exist() {return (root != nullptr);}
        bool exist2() {return (root->lft != nullptr);}
        int DFS(int mode);
        void outTree();
};


#endif // TREE_H
