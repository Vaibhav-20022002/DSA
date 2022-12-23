#include <iostream>
#include <vector>
using namespace std;

bool checkCycle(int node, vector<int> adj[], vector<bool> &vis, vector<bool> &DFS_vis)
{
    // MARK THE PARTICULAR VERTEX TO BE VISITED:
    vis[node] = 1;

    // ALSO MARK THE PATH VISITED BY THE DFS CALL TO BE VISITED:
    DFS_vis[node] = true;

    // TRAVERSING THE ADJACENT VERTICES OF THAT PARTICULAR VERTEX:
    for (auto it : adj[node])
    {
        // IF THE PARTICULAR VERTEX IS NOT VISITED :
        if (!vis[it])
        {
            // MARK IT AS VISITED:
            vis[it] = 1;

            // ALSO MARK THE DFS PATH TO BE VISITED:
            DFS_vis[it] = 1;

            // IF ANY DFS CALL RETURNS TRUE, RETURN TRUE:
            if (checkCycle(it, adj, vis, DFS_vis))
                return true;
        }

        // ELSE IF PARTICULAR VERTEX IS VISITED AND THE VERTEX TRACED BY THE DFS CALL IS ALSO VISITED, THERE IS A CYCLE:
        else if (DFS_vis[it])
            // RETURN TRUE:
            return true;
    }

    // BACKTRACK ALL THE DFS CALL FOR ADJACENTS:
    DFS_vis[node] = false;

    // IF ANY OF THE DFS CALL DOESN'T RETURN TRUE, RETURN FALSE:
    return false;
}

int main(void)
{
    int V = 9;
    vector<int> adj[] = {{}, {2}, {3}, {4, 6}, {5}, {}, {5}, {2, 8}, {9}, {7}};
    vector<bool> vis(V + 1, 0);
    vector<bool> DFS_vis(V + 1, 0);
    for (int i = 1; i <= V; ++i)
    {
        if (!vis[i])
        {
            if (checkCycle(i, adj, vis, DFS_vis))
            {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}