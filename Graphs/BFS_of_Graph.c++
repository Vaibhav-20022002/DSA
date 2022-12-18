#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(void)
{
    // ONE-BASED INDEXED GRAPH:
    int V = 7;

    // ADJACENCY LIST FOR STORING GRAPH !
    // adj IS ARRAY OF VECTORS:
    vector<int> adj[] = {{}, {2}, {3, 7}, {2, 5}, {6}, {3, 7}, {4}, {2, 5}};
    
    // TAKING A VISITED ARRAY FOR MARKING VERTICES VISITED AND MARKING ALL VERTICES AS UNVISITED:
    vector<bool> visited(V + 1, false);

    // TRAVERSING ALL VERTICES AS GRAPH CAN BE DIVIDED INTO MULTIPLE COMPONENTS:
    for (int i = 1; i <= V; ++i) 
        // IF THE VERTEX IS NOT VISITED, GO FOR ITS BFS:
        if (!visited[i])
        {
            // CREATING A QUEUE TO STORE ADJACENTS VERTEX FOR PARTICULAR VERTEX AND ACCESING IT ONE BY ONE IN FIFO ORDER:
            queue<int> q;

            // PUSHING THE STARTING VERTEX INTO THE QUEUE:
            q.emplace(i);

            // TRAVERSING TILL QUEUE BECOMES EMPTY:
            while (!q.empty())
            {
                // TAKING THE FIRST ELEMENT (OR VERTEX) OUT OF THE QUEUE:
                int node = q.front();

                // POPING THAT ELEMENT OUT:
                q.pop();

                // MARKING THAT VERTEX TO BE VISITED:
                visited[node] = true;

                // PRINTING THAT ELEMENT (OR VERTEX):
                cout << node << " ";

                // TRAVERSING ON THE ADJACENTS OF THAT ELEMENT (OR VERTEX) :
                for (auto it : adj[node])
                {
                    // IF THE ELEMENT (OR VERTEX) IS NOT VISITED:
                    if (!visited[it])
                    {
                        // MARK IT AS VISITED:
                        visited[it] = true;

                        // PUSH IT INTO THE QUEUE:
                        q.emplace(it);
                    }
                }
            }
        }
    return 0;
}