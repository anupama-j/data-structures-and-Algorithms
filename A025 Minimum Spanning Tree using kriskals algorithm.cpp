#include <iostream>
#include <bits/stdc++.h>
using namespace std;
'''Example-    Source  Destination   Weight
                 0         1            2
                 1         3            1
                 0         2            4
                 2         4            9
                 4         5            5
                 3         5            7
                 4         3            11
                 2         5            10
                 0         3            3
                 2         1            8
                 2         3            6
  V=6, E=11'''
class Edge
{
public:
  int source;
  int dest;
  int weight;
};

bool compare(Edge e1, Edge e2)
{ // To compare two objects to sort
  return e1.weight < e2.weight;
}

int findParent(int v, int *parent)
{
  if (parent[v] == v)
  {
    return v;
  }
  return findParent(parent[v], parent);
}
void kruskals(Edge *input, int n, int E)
{
  // Sort the input array in ascending order based on weights
  sort(input, input + E, compare); // points  to the first and last element of the array

  Edge *output = new Edge[n - 1];

  int *parent = new int[n];

  for (int i = 0; i < n; i++)
  {
    parent[i] = i;
  }
  int count = 0;
  int i = 0;
  while (count != n - 1)
  {
    Edge currentEdge = input[i];

    // Check if we can add the current edge in MST or not
    int sourceParent = findParent(currentEdge.source, parent);
    int destParent = findParent(currentEdge.dest, parent);

    if (sourceParent != destParent)
    {
      output[count] = currentEdge;
      count++;
      parent[sourceParent] = destParent;
    }
    i++;
  }
  cout<<"Minimum Spanning Tree-"<<endl;
  for (int i = 0; i < n - 1; i++)
  {
    if (output[i].source < output[i].dest)
    {
      cout << output[i].source << "  " << output[i].dest << "  " << output[i].weight << endl;
    }
    else
    {
      cout << output[i].dest << "  " << output[i].source << "  " << output[i].weight << endl;
    }
  }
}
int main()
{
  int n, E;
  cout << "Enter the total number of vertices:\n"
       << endl;
  cin >> n;
  cout << "Enter the total number of edges:\n"
       << endl;
  cin >> E;
  Edge *input = new Edge[E]; // Array of edge type with size E
  for (int i = 0; i < E; i++)
  {
    int s, d, w;
    cout << "Enter Source:\n";
    cin >> s;
    cout << "Enter Destination:\n";
    cin >> d;
    cout << "Enter Weight:\n";
    cin >> w;
    input[i].source = s;
    input[i].dest = d;
    input[i].weight = w;
  }
  kruskals(input, n, E);
}