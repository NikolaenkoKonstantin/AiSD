#include <iostream>
#include <ctime>
#include "graf.h"

using namespace std;

int main()
{
    srand(time(nullptr));
    int a = rand() % 10 + 1;

    graf gr(a);

    cout << "\n Generated graph: \n\n";

    gr.PrintGraph();

    cout << "\n Graph coloring:\n\n";

    gr.Set1();

    cout << "\n Bipartite components of the graph: \n\n";

    gr.Search();

    return 0;
}
