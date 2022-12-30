#include <iostream>
#include <vector>
#include <algorithm>
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
    int V = 6;
    // <weight, {u, v}>:
    vector<pair<int, pair<int, int>>> graph = {{1, {1, 4}}, {2, {1, 2}}, {3, {2, 3}}, {4, {1, 5}}, {5, {3, 4}}, {7, {2, 6}}, {8, {3, 6}}, {9, {4, 5}}};
    
    // SORT THE GIVEN EDGES OR GRAPH ACCORDING TO THE EDGE WEIGHT:
    sort(graph.begin(), graph.end());
    vector<int> parent(V + 1);
    vector<int> rank(V + 1, 0);
    parent[0] = -1;
    rank[0] = -1;
    for (int i = 1; i <= V; ++i)
        parent[i] = i;
    
    // TAKING A VARIABLE TO STORE THE MINIMUM COST OF A MINIMUM SPANNING TREE:
    int cost = 0;

    // CREATING A MST ARRAY :
    // <u, v> :
    vector<pair<int, int>> mst;

    // TRAVERSING OVER THE GRAPH:
    for (auto it : graph)
    {
        // IF u AND v BELONGS TO THE DIFERENT COMPONENTS, UNION THEM AND ADD THEM IN MST:
        if (findParent(it.second.first, parent) != findParent(it.second.second, parent))
        {
            mst.push_back({it.second.first, it.second.second});

            // ADD THE COST :
            cost += it.first;
            UnionByRank(it.second.first, it.second.second, parent, rank);
        }
    }
    cout << cost << "\n";
    for (auto it : mst)
        cout << it.first << " - " << it.second << "\n";
    return 0;
}