#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<algorithm>
using namespace std;

bool cmp(vector<int> &a , vector<int> &b)
{
    return a[2]<b[2];
}

void makeSet(vector<int> &parent , vector<int> &rank , int n)
{
    for(int i = 0 ;i<n ;i++){
        parent[i] = i;
        rank[i]= 0;
    }
}  

int findParent(vector<int> &parent , int node)
{
    if(parent[node] == node){
        return node;
    }
    return parent[node] = findParent(parent , parent[node]);
}

void unionSet(int u , int v , vector<int> &parent , vector<int> &rank)
{
    u = findParent(parent ,u);
    v = findParent(parent , v);

    if(rank[u]<rank[v])
    {
        parent[u] = v ;
    }
    else if (rank[v]<rank[u])
    {
        parent[v] = u ;
    }
    else{
        parent[v] = u;
        rank[u]++ ;
    }
}

int minimumspanningTree(vector<vector<int>> &edges , int n)
{
    sort(edges.begin() , edges.end() , cmp);

    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent , rank ,n);

    int minWeight = 0;

    for(int i = 0 ;i<edges.size();i++){
        int u = findParent(parent , edges[i][0]);
        int v = findParent(parent , edges[i][1]);
        int wt = edges[i][2];

        if(u!=v){
            minWeight += wt ;
            unionSet(u , v , parent , rank) ;
        }
    }
    return minWeight;
}

int main()
{
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> edges;
    cout << "Enter edges in the format: node1 node2 weight\n";

    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    int mstWeight = minimumspanningTree(edges, n);

    cout << "Total weight of Minimum Spanning Tree is: " << mstWeight << endl;

    return 0;
}
