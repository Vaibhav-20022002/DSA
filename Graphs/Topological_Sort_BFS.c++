#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void checkCyclic_Kahn_BFS(int V, vector<int> adj[])
{
    // CREATING A INDEGREE ARRAY FOR COUNTING THE INDEGREE OF EVERY VERTEX:
    vector<int> inDegree(V, 0);

    // CREATING A QUEUE FOR BFS TRAVERSAL:
    queue<int> q;

    // TRAVERSING OVER ALL THE VERTICES :
    for (int i = 0; i < V; ++i)
    {
        // IF A VERTEX HAS ADJACENT VERTICES THEN THEY HAVE AN INCOMING EDGE, THEIR INDEGREE WILL INCREASE BY 1 :
        for (auto it : adj[i])
            ++inDegree[it];
    }

    // PUSHING ALL THE VERTICES WITH INDEGREE 0 INTO THE QUEUE:
    for (int i = 0; i < V; ++i)
    {
        if (inDegree[i] == 0)
            q.emplace(i);
    }

    // TRAVERSING TILL THE QUEUE BECOMES EMPTY:
    while (!q.empty())
    {
        int node = q.front();
        // POPING OUT THE VERTEX AND PRINTING IT I.E; TAKING OUT 0 INDEGREE VERTICES:
        q.pop();
        cout << node << " ";

        // TRAVERSING OVER THE ADJACENTS OF A PARTICULAR VERTEX:
        for (auto it : adj[node])
        {
            // AS THE VERTEX IS TAKEN OUT, REDUCE THE INDEGREE OF ITS VERTICES BY 1:
            --inDegree[it];

            // IF THE INDEGREE OF ANY VERTEX BECOMES 0, PUSH IT INTO THE QUEUE:
            if (inDegree[it] == 0)
                q.emplace(it);
        }
    }
}

int main(void)
{
    // int V = 5;
    // vector<it> adj[] = {{1}, {2}, {3}, {4}, {2}};
    int V = 6;
    vector<int> adj[] = {{}, {}, {3}, {1}, {0, 1}, {2, 0}};
    checkCyclic_Kahn_BFS(V, adj);
    return 0;
}