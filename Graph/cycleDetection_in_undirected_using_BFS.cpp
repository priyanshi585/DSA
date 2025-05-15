#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<list>
using namespace std;

bool isCyclicBFS(int src , unordered_map<int , bool> &visited , unordered_map<int , list<int>> &adj )
{
    unordered_map<int , int> parent;
    parent[src] = -1;
    visited[src] = true;
    queue<int> q;
    q.push(src);

    while(!q.empty())
    {
        int front = q.front();
        q.pop();

        for(auto neighbour : adj[front]){
            if(visited[neighbour]==true && neighbour!=parent[front]){
               return true;
            }

            else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = front;
            }
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges , int n ,int m)
{
    unordered_map<int ,list<int>> adj;
    for(int i = 0; i<m ;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int , bool> visited;
    for(int i = 1;i<=n;i++){
        if(!visited[i]){
            bool ans = isCyclicBFS(i , visited, adj);

            if(ans == 1){
                return "YES" ;
            }
        }
    }
    return "NO" ;
}

int main()
{
    int n = 9;
    int m = 8;
    vector<vector<int>> edges = {{1,2} , {2,3} , {4,5} ,{5 , 6}  , {5,7} ,{6,8} , {7,8} , {8,9}};

    string ans = cycleDetection(edges , n , m);
    if(ans == "YES"){
        cout<<"Cycle is Present in given undirected graph."<<endl;
    }
    else{
        cout<<"No Cycle Present in given graph."<<endl;
    }
    return 0;
}
