// HERE EVERY EDGE HAS UNIT WEIGHT
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void shortestPath_BFS(int src, int V, vector<int> adj[], vector<int> &dis)
{
    // DISTANCE OF SOURCE VERTEX IS ZERO FROM ITSELF:
    dis[src] = 0;

    // CREATING QUEUE FOR BFS:
    queue<int> q;

    // PUSHING THE SOURCE VERTEX INTO THE QUEUE:
    q.emplace(src);

    // TRAVERSING TILL QUEUE BECOMES EMPTY:
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        // TRAVERSING OVER THE ADJACENT VERTICES:
        for (auto it : adj[node])
        {
            // IF SOURCE VERTEX DISTANCE WITH THE EDGE WEIGHT IS LESS THAN THE PREVIOUS DISTANCE OF ADJACENT VERTEX:
            if (dis[node] + 1 < dis[it])
            {
                // UPDATE THE DISTANCE OF ADJACENT VERTEX:
                dis[it] = dis[node] + 1;

                // PUSH THE VERTEX INT THE QUEUE:
                q.emplace(it);
            }
        }
    }

    // PRINTING THE DISTANCE OF ALL VERTICES FROM SOURCE VERTEX:
    for (int it : dis)
        cout << it << " ";
}
int main(void)
{
    int V = 9;
    vector<int> adj[] = {{1, 3}, {0, 2, 3}, {1, 6}, {0, 4}, {3, 5}, {4, 6}, {2, 5, 7, 8}, {6, 8}, {6, 7}};

    // CREATING A DISTANCE ARRAY AND MARKING IT TO BE INFINTY INTIALLY:
    vector<int> dis(V, 1e9);
    
    shortestPath_BFS(0, V, adj, dis);
    return 0;
}