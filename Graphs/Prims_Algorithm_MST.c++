// WRONG OUTPUT:
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void PrimAlgoMST(int V, vector<pair<int, int>> adj[])
{
    vector<int> dist(V + 1, INT8_MAX);
    vector<bool> mst(V + 1, false);
    vector<int> parent(V + 1, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[0] = 0;
    pq.push({0, 0});
    while (!pq.empty())
    {
        int node = pq.top().second;
        pq.pop();
        mst[node] = true;
        for (auto it : adj[node])
        {
            int v = it.first;
            int weight = it.second;
            if (mst[v] == false && weight < dist[v])
            {
                parent[v] = node;
                dist[v] = weight;
                pq.push({dist[v], v});
            }
        }
    }
    for (int i = 1; i <= V; i++)
        cout << parent[i] << " -> " << i << " \n";
}
int main(void)
{
    int V = 6;
    vector<pair<int, int>> adj[] = {{}, {{5, 4}, {4, 1}, {2, 2}}, {{1, 2}, {4, 3}, {3, 3}, {6, 7}}, {{4, 5}, {6, 8}}, {{1, 1}, {5, 9}, {3, 4}}, {{1, 4}, {4, 9}}, {{2, 7}, {3, 8}}};
    PrimAlgoMST(V, adj);
    return 0;
}