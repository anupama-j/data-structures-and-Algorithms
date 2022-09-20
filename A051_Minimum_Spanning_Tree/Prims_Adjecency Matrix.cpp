// A simple C++ implementation to find minimum spanning tree for adjacency matrix representation.
#include <bits/stdc++.h>
using namespace std;
#define V 5
#define MAX 9999  //to initialize as infinity

bool isValidEdge(int u, int v, vector<bool> inMST);
void primMST(int cost[][V]);

int main()
{
	int cost[][V] = {
		{ MAX, 12, MAX, 16, MAX },
		{ 12, MAX, 13, 10, 15 },
		{ MAX, 13, MAX, MAX, 17 },
		{ 12, 18, MAX, MAX, 19 },
		{ MAX, 15, 17, 19, MAX },
	};
	primMST(cost);
	return 0;
}

bool isValidEdge(int u, int v, vector<bool> inMST)
{
if (u == v)
	return false;
if (inMST[u] == false && inMST[v] == false)
		return false;
else if (inMST[u] == true && inMST[v] == true)
		return false;
return true;
}

void primMST(int cost[][V])
{
	vector<bool> inMST(V, false);

	// Include first vertex in MST
	inMST[0] = true;

	// Keep adding edges while number of included edges does not become V-1.
	int edge_count = 0, mincost = 0;
	while (edge_count < V - 1) {


		int min = MAX, a = -1, b = -1;
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {			
				if (cost[i][j] < min) {
					if (isValidEdge(i, j, inMST)) {
						min = cost[i][j];
						a = i;
						b = j;
					}
				}
			}
		}
		if (a != -1 && b != -1) {
			printf("Edge %d:(%d, %d) cost: %d \n",
						edge_count++, a, b, min);
			mincost = mincost + min;
			inMST[b] = inMST[a] = true;
		}
	}
	printf("\n Minimum cost= %d \n", mincost);
}

