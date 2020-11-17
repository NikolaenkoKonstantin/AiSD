#include <iostream>
#include "tree.h"
#include <ctime>

using namespace std;

int main()
{
    srand(time(nullptr));

    Tree Tr('a', 'z', 8);

    Tr.makeTree();

    if(Tr.exist())
    {
        Tr.outTree();

        cout << endl << "Depth-first search:";

        cout << "Passed nodes: " << Tr.DFS(0) << endl;

        if(Tr.exist2()) cout << "Height of the left subtree = " << Tr.DFS(1) << endl;
        else cout << "Left subtree does not exist!!!" << endl;
    }
    else cout << endl << "Error, tree does not exist!!!" << endl;

    return 0;
}
