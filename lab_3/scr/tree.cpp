#include "tree.h"


using namespace std;


//Depth-first search
int Tree :: DFS(int mode)
{
    const int maxS = 20;
    int height = 0;
    int count1 = 0;
    STACK <Node *> S(maxS);

    if(mode) S.push(root->lft);
    else S.push(root);
    while(!S.empty())
    {
        Node *v = S.pop();
        if(!mode) cout << v->c << ' ';
        count1++;

        if(v->lvl > height) height = v->lvl;

        if(v->rgt) S.push(v->rgt);
        if(v->lft) S.push(v->lft);
    }

    if(mode) return height - 1;
    else return count1;
}


//creating tree
void Tree :: makeTree()
{
    int mode;

    cout << "0)Random\n1)Manually\nInput mode: ";
    cin >> mode;

    root = makeNodes(0, mode, -1);
}


//creating nodes
Node * Tree :: makeNodes(int depth, int mode, int prevLvl)
{
    Node *v = nullptr;
    int Y;

    if(mode){
        cout << "Node(" << num << ',' << depth << ") 1/0:";
        cin >> Y;
    }
    else Y = (depth < rand() % 6 + 1) && (num <= 'z');

    if(Y)
    {
        v = new Node;

        v->lvl = prevLvl + 1;

        v->lft = makeNodes(depth + 1, mode, v->lvl);

        v->rgt = makeNodes(depth + 1, mode, v->lvl);

        v->c = num++;
    }

    return v;
}


//tree constructor
Tree::Tree(char nm, char mnm, int mxr): num(nm), maxNum(mnm), maxrow(mxr), SCREEN(new char * [maxrow]), offset(40), root(nullptr)
{
    for(int i = 0; i < maxrow; i++) SCREEN[i] = new char[80];
}


//destructor of tree
Tree::~Tree()
{
    for(int i = 0; i < maxrow; i++) delete[] SCREEN[i];

    delete[] SCREEN;

    delete root;
}


//output nodes
void Tree :: outNodes(Node *v, int r, int c)
{
    if(r && c && (c < 80)) SCREEN[r - 1][c - 1] = v->c;
    if(r < maxrow)
    {
        if(v->lft) outNodes(v->lft, r+1, c - (offset >> r));
        if(v->rgt) outNodes(v->rgt, r+1, c + (offset >> r));
    }
}


//function for output
void Tree :: clrscr()
{
    for(int i = 0; i < maxrow; i++)
        memset(SCREEN[i], '.', 80);
}


//output tree
void Tree :: outTree()
{
    clrscr();
    outNodes(root, 1, offset);
    for(int i = 0; i < maxrow; i++)
    {
        SCREEN[i][79] = 0;
        cout << endl << SCREEN[i];
    }

    cout << endl;
}
