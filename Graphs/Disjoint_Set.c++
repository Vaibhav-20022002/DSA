#include <iostream>
#include <vector>
using namespace std;

// FUNCTION FOR FINDING THE ULTIMATE PARENT:
int findParent(int node, vector<int> &parent)
{
    // IF THE VERTEX IS ITS ULTIMATE PARENT, RETURN THAT VERTEX:
    if (node = parent[node])
        return node;

    // PATH COMPRESSION IS MARKING EVERY VERTEX WITH THEIR ULTIMATE PARENT TO REDUCE THE SEARCHING TIME FOR PARENT :
    // ELSE GO THE PARENT OF THE VERTEX AND UPDATE EVERY VERTEX'S PARENT WITH ITS ULTIMATE PARENT:
    return parent[node] = findParent(parent[node], parent);
}

// FUNCTION TO PERFORM THE UNION OPERATION BY RANK:
void UnionByRank(int u, int v, vector<int> &parent, vector<int> &rank)
{
    // FINDING THE ULTIMATE PARENT OR ROOT OF u AND v:
    u = findParent(u, parent);
    v = findParent(v, parent);

    // IF THEIR ULTIMATE PARENT OR ROOT IS SAME, DO NOTHING AS THEY BELONG TO THE SAME COMPONENT :
    if (u == v)
        return;

    // IF THE RANK OF BOTH VERTICES ARE SAME :
    if (rank[u] == rank[v])
    {
        // MAKE ANY ONE OF THE PARENT OF THE OTHER AND INCREASE THE RANK OF THE PARENT :
        parent[v] = u;
        ++rank[u];
    }

    // IF THE RANK OF u IS GREATER I.E; u HAVE MORE VERTICES AS ITS CHILDREN, THEN MAKE u THE PARENT OF v:
    else if (rank[u] > rank[v])
        parent[v] = u;

    // ELSE IF THE RANK OF v IS GREATER I.E; v HAS MORE VETICES AS ITS CHLDREN, THEN MAKE v AS THE PARENT OF u:
    else
        parent[u] = v;
}
int main(void)
{
    int V = 7;

    // CREATING A ARRAY TO STORE THE ROOT OR ULTIMATE PARENT OF EVERY VERTEX:
    vector<int> parent(V + 1, 0);

    // RANK GIVES A DECENT IDEA ABOUT THE SIZES OF VERTICES TREE OR GRAPH FORMING BY UNION !!!
    // CREATING A ARRAY TO STORE THE RANK OF EVERY VERTEX:
    vector<int> rank(V + 1, 0);

    // PARENT OF VERTEX ZERO WILL BE NO ONE:
    parent[0] = -1;

    // RANK OF VERTEX ZERO WILL BE NOTHING INTIALLY:
    rank[0] = -1;

    // TRAVERSING OVER EVERY VERTEX OF THE GRAPH:
    for (int i = 1; i <= V; ++i)
        // MARKING EVERY VERTEX TO BE ITS ULTIMATE PARENT OR ROOT:
        parent[i] = i;

    UnionByRank(1, 2, parent, rank);
    UnionByRank(2, 3, parent, rank);
    UnionByRank(4, 5, parent, rank);
    if (findParent(4, parent) != findParent(5, parent))
        cout << "DIFFERENT COMPONENTS !\n";
    else
        cout << "SAME COMPONENT !\n";
    if (findParent(6, parent) != findParent(7, parent))
        cout << "DIFFERENT COMPONENTS !\n";
    else
        cout << "SAME COMPONENT !\n";
    UnionByRank(6, 7, parent, rank);
    UnionByRank(5, 6, parent, rank);
    UnionByRank(3, 7, parent, rank);
    return 0;
}