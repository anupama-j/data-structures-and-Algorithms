/*
A020
Prem Kakadia
45207210035
*/

// Write Program for DFS

#include <iostream>
#include <list>
using namespace std;

// Graph class for DFS travesal
class Graph
{
    int V;                                // No. of vertices
    list<int> adj[10];                    // Adjacency list  (Max no. of adjacent vertices)
    bool visited[10];                     // Visited array  (Max no. of vertices)
    void DFS_main(int v, bool visited[]); // Main function for DFS traversal

public:
    // initializing V with the no. of vertices
    Graph(int vertices)
    {
        V = vertices;
    }

    // Function to add an edge to graph
    // adding v1 to v2 & v2 to v1 as it is an undirected graph
    void addEdge(int v1, int v2)
    {
        adj[v1].push_back(v2); // Add v2 to v1's list.
        adj[v2].push_back(v1); // Add v1 to v2's list.
    }

    // DFS traversal function
    void DFS(int r);
};

// DFS function to initialize visited vertices as false & to pass starting node
void Graph::DFS(int r)
{
    // initializing value of visited vertices as false
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // explore the vertices one by one by recursively calling DFS_util
    for (int i = r; i < V; i++)
        if (visited[i] == false)
            DFS_main(i, visited); // passing the root node & visited array i.e initialized (flase)
}

// Function to print & mark visited nodes
void Graph::DFS_main(int v, bool visited[])
{
    visited[v] = true; // current node v is visited
    cout << v << " ";  // print the current node

    // recursively process all the adjacent vertices of the node
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS_main(*i, visited);
}

int main()
{
    /*
    The graph used here is unweighted & undirected.

    0 -- 3
    |\
    | 2
    |/ \
    1   4

    */

    Graph G(5); // 5 is the total number of vertices (0, 1, 2, 3, 4)
    G.addEdge(0, 1);
    G.addEdge(0, 2);
    G.addEdge(0, 3);
    G.addEdge(1, 2);
    G.addEdge(2, 4);

    // Enter the starting node ie. (0, 1, 2, 3, 4)
    int root;
    cout << "Enter the root node: ";
    cin >> root;

    cout << "\nDepth-first traversal for the given graph:" << endl;
    G.DFS(root);

    return 0;
}
