// USED FOR FINDING STRONGLY CONNECTED COMPONENTS (SCC):
// REVERSE DFS IS THE TRICK !
#include <iostream>
#include <vector>
using namespace std;
void dfs(int node, vector<int> adj[], vector<bool> &vis)
{
    vis[node] = 1;
    cout << node << " ";
    for (int it : adj[node])
        if (!vis[it])
            dfs(it, adj, vis);
}
void Kosaraju(int V, vector<int> adj[], vector<bool> &vis)
{
    for (int i = V; i > 0; --i)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            cout << i << " ";
            for (int it : adj[i])
                if (!vis[it])
                    dfs(it, adj, vis);
        }
        cout << "\n";
    }
}
int main(void)
{
    int V = 6;
    vector<int> adj[] = {{}, {3}, {1}, {2, 5}, {6}, {4}, {5}};
    vector<bool> vis(V + 1, 0);
    Kosaraju(V, adj, vis);
    return 0;
}