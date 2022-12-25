#include <iostream>
#include <queue>
#include <vector>
using namespace std;
bool checkCyclic_Kahn_BFS(int V, vector<int> adj[])
{
    vector<int> inDegree(V, 0);
    queue<int> q;
    for (int i = 0; i < V; ++i)
    {
        for (auto it : adj[i])
        {
            ++inDegree[it];
        }
    }
    for (int i = 0; i < V; ++i)
    {
        if (inDegree[i] == 0)
        {
            q.emplace(i);
        }
    }
    int cnt = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ++cnt;
        for (auto it : adj[node])
        {
            --inDegree[it];
            if (inDegree[it] == 0)
                q.emplace(it);
        }
    }
    if (cnt == V)
        return false;
    return true;
}
int main(void)
{
    int V = 5;
    vector<int> adj[] = {{1}, {2}, {3}, {4}, {2}};
    // int V=6;
    // vector<int> adj[]={{},{},{3},{1},{0,1},{2,0}};
    bool ans = checkCyclic_Kahn_BFS(V, adj);
    if (ans)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}