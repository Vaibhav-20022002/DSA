#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// FUNCTION TO CHECK FOR BIPARTITINESS:
bool checkBipartite(int s, vector<int> adj[], vector<int> &color)
{
    // CREATING A QUEUE FOR BFS TRAVERSAL:
    queue<int> q;

    // PUSHHING THE STARTING VERTEX INTO THE QUEUE:
    q.emplace(s);

    // COLOR THE FIRST VERTEX WITH COLOR 1:
    color[s] = 1;

    // TRAVERSING TILL QUEUE BECOMES EMPTY:
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        // TRAVERSING OVER THE ADJACENTS:
        for (auto it : adj[node])
        {
            // IF THE VERTEX IS NOT COLORED YET:
            if (color[it] == -1)
            {
                // COLOR IT WITH THE OPPOSITE COLOR OF ITS PARENT OR ADJACENTS:
                color[it] = 1 - color[node];

                // PUSH IT INTO THE QUEUE:
                q.emplace(it);
            }

            // IF THE VERTEX IS COLORED AND HAVE THE SAME COLOR AS ITS ADJACENT, RETURNS FALSE:
            else if (color[it] == color[node])
                return false;
        }
    }

    // IF ANY OF THE VERTEX DOESN'T RETURNS FALSE, IT MEANS GRAPH IS A BIPARTITE:
    return true;
}

bool isBipartite(int V, vector<int> adj[], vector<int> &color)
{
    // TRAVESING ALL THE COMPONENTS OF THE GRAPH:
    for (int i = 1; i <= V; ++i)
        // IF THE VERTEX IS NOT COLORED I.E; YET NOT VISITED:
        if (color[i] == -1)
            // IF ANY OF THE VERTEX RETURNS FALSE, RETURN FALSE:
            if (!checkBipartite(i, adj, color))
                return false;
    // RETURN TRUE IF ANY VERTEX DOESN'T RETURNS FALSE:
    return true;
}
int main(void)
{
    int V = 10;
    vector<int> adj[] = {{}, {2}, {3}, {4, 8}, {3, 5}, {4, 6}, {5, 7, 9}, {6, 8}, {3, 7}, {6, 10}, {9}};
    vector<int> color(V + 1, -1);
    if (isBipartite(V, adj, color))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}