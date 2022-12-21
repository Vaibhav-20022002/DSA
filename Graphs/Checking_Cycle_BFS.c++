#include <iostream>
#include <queue>
#include <vector>
using namespace std;
bool CheckCycle_BFS(int node, vector<int> adj[], vector<bool> &vis)
{
    // queue<node, parent> :
    queue<pair<int, int>> q;

    // PUSHING THE STARTING VERTEX INTO THE QUEUE:
    q.push({node, -1});

    // MARKING THE PARTICULAR VERTEX TO BE VISITED:
    vis[node] = 1;

    // TRAVERSING TILL THE QUEUE BECOMES EMPTY:
    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        // TRAVERSING OVER THE ADJACENTS OF THE PARTICULAR VERTEX:
        for (auto it : adj[node])
        {
            // IF THE PARTICULAR VERTEX IS VISITED:
            if (!vis[it])
            {
                // PUSH IT INTO THE QUEUE:
                q.push({it, node});
                // MARK IT AS VISITED:
                vis[it] = 1;
            }

            // IF IT IS VISITED AND ITS PARENT IT NOT SAME AS ITS PREVIOUS, THERE IS A CYCLE:
            else if (parent != it)
                return true;
        } 
    }

    // IF NONE OF THE VERTEX GETS A CYCLE, THERE IS NO CYCLE:
    return false;
}
int main(void)
{
    // ONE-BASED INDEXED GRAPH:
    int V = 11;
    vector<int> adj[] = {{}, {2}, {1, 4}, {5}, {2}, {3, 10, 16}, {5, 7}, {6, 8}, {7, 9, 11}, {10, 8}, {5, 9}, {8}};
    vector<bool> vis(V + 1, 0);
    for (int i = 1; i <= V; ++i)
        if (!vis[i])
            if (CheckCycle_BFS(i, adj, vis))
            {
                cout << "THERE IS A CYCLE IN THE GIVEN GRAPH !";
                return 0;
            }
    
    cout << "THERE IS NO CYCLE IN THE GIVEN GRAPH !";
    return 0;
}