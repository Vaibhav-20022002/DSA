// TOPOLOGICAL SORT: IT IS THE LINEAR ORDERING OF THE VERTICES SUCH THAT u APPEARS BEFORE v IF WE HAVE A DIRECT EDGE FROM
//   u -> v !
// TOPOLOGICAL SORT ARE NOT APPLICABLE IF THE GRAPH IS CYCLIC AND UNDIRECTED !!!
// TOPOLOGICAL SORT ARE APPLICABLE OVER DAG (DIRECTED ACYCLIC GRAPH) ONLY !!!

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void TopoSort_DFS(int node, vector<int> adj[], vector<bool> &vis, stack<int> &st)
{
    // MARKING THE PARTICULAR VERTEX TO BE VISITED
    vis[node] = true;

    // TRAVERSING OVER THE ADJACENTS OF THAT VERTEX:
    for (auto it : adj[node])
        // IF THE ADJACENT VETEX IS NOT VISITED:
        if (!vis[it])
            // CALL ITS DFS :
            TopoSort_DFS(it, adj, vis, st);
    // IF THE DFS CALL FOR A PARTICULAR VERTEX IS OVER, PLACE IT INTO THE STACK:
    st.emplace(node);
}

int main(void)
{
    int V = 6;
    vector<int> adj[] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
    vector<bool> vis(V, 0);

    // CREATING A STACK TO STORE VERTEX WHOSE DFS CALL GETS OVER:
    stack<int> st;

    // TRAVERSING OVER ALL THE COMPONENTS OF THE GRAPH:
    for (int i = 0; i < V; ++i)
        // IF THE VERTEX IS NOT VISITED CALL ITS DFS:
        if (!vis[i])
            TopoSort_DFS(i, adj, vis, st);

    // PRINTING THE STACK :
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}