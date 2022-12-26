#include <bits/stdc++.h>
using namespace std;

void Dijkstra(int source, vector<pair<int, int>> adj[], vector<int> &distTo, int V)
{
	// CREATING A PRIORITY QUEUE TO GET THE SHORTEST DISTANCE VERTEX FIRST TO AVOID UNECESSARY COMPUTATIONS:
	// pq <distance, vertex> :
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	// MARKING THE DISTANCE OF SOURCE VERTEX TO BE ZERO:
	distTo[source] = 0;

	// PUSHING IT INTO THE QUEUE:
	pq.push({0, source});

	// MAKING A PARENT ARRAY TO STORE THE SHORTEST PATH (FOR PRINTING THE PATH ONLY):
	vector<int> parent(V + 1, -1);
	parent[source] = source;

	// TRAVERSING TILL THE QUEUE BECOMES EMPTY:
	while (!pq.empty())
	{
		// TAKING OUT SHORTEST DISTANCE VERTEX OUT OF THE QUEUE:
		// TAKING OUT PREVIOUS DISTANCE OF THAT VERTEX:
		int prevDist = pq.top().first;

		// TAKING OUT THE VERTEX :
		int node = pq.top().second;
		pq.pop();

		// TRAVERSING OVER THE ADJACENTS OF THAT VERTEX:
		for (auto it : adj[node])
		{
			// IF THE PREVIOUS DISTANCE OF THE PREVIOUS VERTEX ADDING THE EDGE WEIGHT TO THE ADJACENT VERTEX IS LESS THAN
			// THE STORED DISTANCE, UPDATE THE DISTANCE ARRAY:
			if (prevDist + it.second < distTo[it.first])
			{
				distTo[it.first] = prevDist + it.second;

				// CHANGING THE PARENT :
				parent[it.first] = node;

				// PUSH THE NEW VERTEX AND DISTANCE INTO THE QUEUE:
				pq.push({distTo[it.first], it.first});
			}
		}
	}

	// PRINTING THE DISTANCE:
	cout << "The distances from source " << source << " are : \n";
	for (int i = 1; i <= V; i++)
		cout << distTo[i] << " ";
	cout << "\n";

	// PRINTING OUT THE PATH:
	vector<int> path;
	int x = V;

	// PUSHING THE DESTINATION FIRST INTO THE PATH ARRAY:
	path.emplace_back(x);

	// TRAVERSING TILL PARENT REACHES THE SOURCE:
	while (parent[x] != source)
	{
		// CHANGING TO ITS PARENT:
		x = parent[x];

		// PUSHING IT INTO THE PATH ARRAY:
		path.emplace_back(x);
	}

	// REVERSING THE PATH ARRAY AS THE PATH IS TRACED FROM SOURCE TO DESTINATION :
	reverse(path.begin(), path.end());

	// PRINTING THE PATH:
	for (int it : path)
		cout << it << " -> ";
}
int main(void)
{
	int V = 5;
	// pair<node, weight>
	vector<pair<int, int>> adj[] = {{}, {{2, 2}, {4, 1}}, {{1, 2}, {5, 5}, {3, 4}}, {{2, 4}, {4, 3}, {5, 1}}, {{1, 1}, {3, 3}}, {{2, 5}, {3, 1}}};

	// CREATING A DISTANCE ARRAY TO STORE THE DISTANCES OF ALL VERTICES, MARKED INFINITY INTIALLY:
	vector<int> distTo(V + 1, 1e9);

	Dijkstra(1, adj, distTo, V);
	return 0;
}