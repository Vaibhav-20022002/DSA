#include <iostream>
#include <vector>
using namespace std;

void dfs_Graph(int node, vector<int> adj[], vector<bool> &visited)
{
    // MARKING THE PARTICULAR VERTEX AS VISITED:
    visited[node] = true;

    // PRINTING THAT NODE:
    cout << node << " ";

    // TRAVERSING THE ADJACENTS OF THAT PARTICULAR VERTEX:
    for (auto it : adj[node])
    {
        // IF THE VERTEX IS NOT VISITED, GO FOR ITS DFS:
        if (!visited[it])
            dfs_Graph(it, adj, visited);
    }
}

int main(void)
{
    // ONE-BASED INDEXED GRAPH:
    int V = 7;
    
    // ADJACENCY LIST FOR STORING GRAPH !
    // adj IS ARRAY OF VECTORS:
    vector<int> adj[] = {{}, {2}, {1, 4, 7}, {5}, {2, 6}, {3}, {4, 7}, {2, 6}};

    // TAKING A VISITED ARRAY FOR MARKING VERTICES VISITED AND MARKING ALL VERTICES AS UNVISITED:
    vector<bool> visited(V + 1, false);

    // RUNNING A LOOP FOR ALL VERTICES, AS GRAPH CAN BE DIVIDED INTO MULTIPLE COMPONENTS:
    for (int i = 1; i <= V; ++i)
    {
        // IF THE VERTEX IS NOT VISITED THEN GO FOR ITS DFS:
        if (!visited[i])
            dfs_Graph(i, adj, visited);
    }
    return 0;
}