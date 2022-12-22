#include <iostream>
#include <vector>
using namespace std;

bool CheckCycle_DFS(int node, int parent, vector<int> adj[], vector<bool> &vis)
{
    // MARKING THAT PARTICULAR VERTEX TO BE VISITED:
    vis[node] = true;

    // TRAVERSING THE ADJACENT VERTICES:
    for (auto it : adj[node])
    {
        // IF THE PARTICULAR VERTEX IS NOT VISITED:
        if (!vis[it])
        {
            // IF THE PARTICULAR DFS CALL RETURNS TRUE, RETURN TRUE:
            if (CheckCycle_DFS(it, node, adj, vis))
                return true;
        }

        // IF THE PARTICULAR VERTEX IS VISITED, CHECK IF ITS PARENT IS ITS PREVIOUS VERTEX OR NOT:
        else if (it != parent)
            // RETURN TRUE IF PARENT DOESN'T MATCH WITH ITS PREVIOUS VERTEX OR PARENT VECRTEX:
            return true;
    }

    // RETURN FALSE IF NONE OF THE DFS GETS TRUE:
    return false;
}

int main(void)
{
    // ONE-BASED INDEXED GRAPH:
    int V = 8;
    vector<int> adj[] = {{}, {3}, {5}, {1, 4}, {3}, {6, 2, 8}, {5, 7}, {6, 8}, {7, 5}};
    vector<bool> vis(V + 1, 0);
    for (int i = 1; i <= V; ++i)
        if (!vis[i])
            if (CheckCycle_DFS(i, -1, adj, vis))
            {
                cout << "THERE IS A CYCLE IN THE GIVEN GRAPH !";
                return 0;
            }

    cout << "THERE IS NO CYCLE IN THE GIVEN GRAPH !";
    return 0;
}