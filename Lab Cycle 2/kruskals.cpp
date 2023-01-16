#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int MAX = 99999;
int parent[MAX];
int find(int a)
{
    while (parent[a] != a)
    {
        parent[a] = parent[parent[a]];
        a = parent[a];
    }
    return a;
}

void add(int a, int b)
{

    int d = find(a);
    int e = find(b);
    parent[d] = parent[e];
}

int main()
{
    int V, E;
    cout << "Enter the no: of vertices : "
         << " ";
    cin >> V;
    cout << "Enter the no: of edges : "
         << " ";
    cin >> E;
    vector<pair<int, pair<int, int>>> adj;
    cout << "Enter the weight,source and destination one by one in correct order : " << endl;
    for (int i = 0; i < E; i++)
    {
        int weight;
        int src, destination;
        cin >> weight >> src >> destination;
        adj.push_back({weight, {src, destination}});
    }
    sort(adj.begin(), adj.end());
    for (int i = 0; i < MAX; i++)
    {
        parent[i] = i;
    }
    vector<pair<int, int>> tree_edges; // Storing the edges of MST
    int totalweight = 0;
    for (auto x : adj)
    {
        int a = x.second.first;
        int b = x.second.second;
        int cost = x.first;
        if (find(a) != find(b)) // checking whether it forms a cycle
        {                       // if the two vertices are in different subsets, merge them into one
            totalweight += cost;
            add(a, b);
            tree_edges.push_back({a, b});
        }
    }
    cout << "Edges are : " << endl;
    for (auto x : tree_edges) // MST edges
    {
        cout << x.first << " " << x.second << endl;
    }
    cout << "Total weight of MST = ";
    cout << totalweight << endl;

    return (0);
}