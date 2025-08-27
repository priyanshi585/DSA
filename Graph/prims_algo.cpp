#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
#include<limits.h>
using namespace std;

vector<pair<pair<int , int> , int>> calculatePrimsMST(int n, int m ,vector<pair<pair<int , int> , int>> &g)
{
    unordered_map<int , list<pair<int , int>>> adj ;
    for(int i = 0;i<g.size();i++){
        int u = g[i].first.first;
        int v =g[i].first.second ;
        int w = g[i].second ;  

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    vector<int> key(n+1);
    vector<bool> mst(n+1);
    vector<int> parent(n+1);

    for(int i = 1 ;i<=n ;i++){
        key[i] = INT_MAX ;
        parent[i] = -1;
        mst[i] = false;
    }

    key[1] = 0;
    parent[1] = -1;

    for(int i = 1 ;i<=n ;i++){
        int mini = INT_MAX;
        int u ;

        for(int v = 1 ;v<=n ;v++){
            if(mst[v] == false && key[v] < mini ){
                u = v;
                mini = key[v] ;
            }
        }

        mst[u] = true;

        for(auto it : adj[u])
        {
            int v = it.first ;
            int w = it.second ;

            if(mst[v] == false && w < key[v]){
                parent[v] = u;
                key[v] = w ;
            }
        }
    }

    vector<pair<pair<int , int> , int>> result ;

    for(int i = 2 ;i<=n;i++){
        result.push_back({{parent[i] , i} , key[i]});
    }
    return result ;
}

int main()
{
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<pair<pair<int , int> , int>> edges;

    cout << "Enter edges in the format: node1 node2 weight\n";
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({{u, v}, w});
    }

    vector<pair<pair<int , int> , int>> mst = calculatePrimsMST(n, m, edges);

    cout << "Minimum Spanning Tree Edges:\n";
    for(auto edge : mst){
        cout << edge.first.first << " - " << edge.first.second << " with weight " << edge.second << endl;
    }

    return 0;
}
