// THIS ALGORIHTM WORKS FOR DIRECTED GRAPH:
#include <iostream>
#include <vector>
using namespace std;
void BellmanFord(int V, int src, vector<pair<pair<int, int>, int>> &edges, vector<int> &dist)
{
    dist[src] = 0;
    // RELAXING THE EDGES FOR V-1 TIMES:
    for (int i = 1; i <= V - 1; ++i) 
        for (auto it : edges)
            if (dist[it.first.first] + it.second < dist[it.first.second])
                dist[it.first.second] = dist[it.first.first] + it.second;

    // RELAXING Vth TIME TO DETECT THE NEGATIVE CYCLE:
    for (auto it : edges)
        if (dist[it.first.first] + it.second < dist[it.first.second])
        {
            cout << "NEGATIVE CYCLE !";
            return;
        }

    // PRINTING THE VERTICES WITH SHORTEST DISTANCE FROM THE SRC:
    for (int i = 0; i < V; i++)
    {
        cout << i << " " << dist[i] << "\n";
    }
}
int main(void)
{
    int V = 6;
    vector<pair<pair<int, int>, int>> edges = {{{3, 2}, 6}, {{5, 3}, 1}, {{0, 1}, 5}, {{1, 5}, -3}, {{1, 2}, -2}, {{3, 4}, -2}, {{2, 4}, 3}};
    vector<int> dist(V, INT8_MAX);
    int src = 0;
    BellmanFord(V, src, edges, dist);
    return 0;
}