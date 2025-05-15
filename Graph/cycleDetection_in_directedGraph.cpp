#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

bool checkCycleDFS(int node , unordered_map<int , bool> &visited , unordered_map<int , bool> &dfsVisited , 
                    unordered_map<int ,list<int>> &adj)
{
    visited[node] = true;
    dfsVisited[node] = true;

    for(auto neighbour : adj[node]){
        if(!visited[neighbour]){
            bool cycleDetected = checkCycleDFS(neighbour , visited , dfsVisited , adj);

            if(cycleDetected){
                return true;
            }
        }
        else if(dfsVisited[neighbour]){
            return true;
        }
    }

    dfsVisited[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n , vector<pair<int,int>> &edges)
{
    unordered_map<int , list<int>> adj;
    for(int i = 0 ;i<edges.size() ;i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    unordered_map<int , bool> visited ;
    unordered_map<int , bool> dfsVisited ;

    for(int i = 1 ;i<=n ;i++){
        if(!visited[i]){
            bool cycleDetected = checkCycleDFS(i , visited , dfsVisited , adj);

            if(cycleDetected){
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n =8;
    vector<pair<int , int>> edges = {{1,2} , {2,3} , {3, 7} , {2,4} ,{4,5} , {5,6} , {6,4} , {3,8} , {8,7}};
    int ans = detectCycleInDirectedGraph(n , edges);

    if(ans == 1){
        cout<<"Cycle is Present in given Directed Graph."<<endl;
    }
    else{
        cout<<"Cycle Not Present in given directed graph."<<endl;
    }
    return 0;
}
