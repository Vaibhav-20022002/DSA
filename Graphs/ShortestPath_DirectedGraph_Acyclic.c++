#include <iostream>
#include <stack>
#include <vector>
using namespace std;
void topoSort(int node, vector<pair<int, int>> adj[], vector<bool> &vis, stack<int> &st)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it.first])
        {
            vis[it.first] = 1;
            topoSort(it.first, adj, vis, st);
        }
    }
    st.emplace(node);
}
void shortestPath(int src, int V, vector<pair<int, int>> adj[])
{
    vector<bool> vis(V, 0);
    stack<int> st;
    for (int i = 0; i < V; ++i)
    {
        if (!vis[i])
        {
            topoSort(i, adj, vis, st);
        }
    }
    vector<int> dist(V, INT8_MAX);
    dist[src] = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (dist[node] != INT8_MAX)
        {
            for (auto it : adj[node])
            {
                if (dist[node] + it.second < dist[it.first])
                {
                    dist[it.first] = dist[node] + it.second;
                }
            }
        }
    }
    for (auto it : dist)
        cout << it << " ";
}
int main(void)
{
    int V = 6;
    // pair<int,int> = <node,weight>
    vector<pair<int, int>> adj[] = {{{1, 2}, {4, 1}}, {{2, 3}}, {{3, 6}}, {}, {{2, 2}, {5, 4}}, {{3, 1}}};
    shortestPath(0, V, adj);
    return 0;
}