// USED TO DETECT THE ODD LENGTH CYCLE IN A GRAPH !!!
// A BIPARTITE GRAPH IS THE ONE IN WHICH NO TWO ADJACENT VERTEX CAN HAVE THE SAME COLOR !!!
// IT IS NOT POSSIBLE TO COLOR A ODD LENGTH CYCLE GRAPH TO COLOR WITH TWO COLOR FOLLOWING THE BIPARTITE PROPERTY:

#include <iostream>
#include <vector>
using namespace std;

// FUNCTION TO CHECK FOR BIPARTITINESS :
bool checkBipartite(int vertex, int col, vector<int> adj[], vector<int> &color)
{
    // COLOR THE PARTICULAR VERTEX WITH THE COLOR OPPOSITE OF ITS PREVIOUS DFS CALL VERTEX:
    color[vertex] = col;

    // TRAVERSE OVER THE ADJACENTS :
    for (auto it : adj[vertex])
    {
        // IF THE VERTEX IS NOT COLORED YET:
        if (color[it] == -1)
        {
            // IF ANY OF THE DFS CALL FOR ANY VERTEX RETURNS FASLE, RETURN FALSE:
            // COLOR THE ADJACENTS WITH THE OPPOSITE COLOR:
            if (!checkBipartite(it, !col, adj, color))
                return false;
        }

        // IF THE VERTEX IS COLORED AND IT IS SAME AS ITS ADJACENT, RETURN FASLE:
        else if (color[it] == col)
            return false;
    }

    // IF ANY OF THE DFS CALL FOR ANY VERTEX DOESN'T RETURNS FALSE, RETURN TRUE
    return true;
}
bool isBipartite(int V, vector<int> adj[], vector<int> &color)
{
    // TRAVERSE OVER ALL THE COMPONENTS:
    for (int i = 1; i <= V; ++i)
        // IF THE VERTEX IS NOT COLORED I.E; NOT YET VISITED:
        if (color[i] == -1)
            // IF DFS CALL FOR ANY VERTEX RETURNS FALSE, GRAPH IS NOT BIPARTITE:
            if (!checkBipartite(i, 0, adj, color))
                return false;
    // IF ANY CALL DOESN'T RETURNS FALSE,GIVEN GRAPH IS A BIPARTITE:
    return true;
}
int main(void)
{
    int V = 10;
    vector<int> adj[] = {{}, {2}, {3}, {4, 8}, {3, 5}, {4, 6}, {5, 7, 9}, {6, 8}, {3, 7}, {6, 10}, {9}};

    // CREATING A COLOR ARRAY FOR COLORING THE GRAPH WITH THE COLORS - 0 AND 1 :
    vector<int> color(V + 1, -1);
    if (isBipartite(V, adj, color))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}