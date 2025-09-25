#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<unordered_map>
using namespace std;

int cycleDetectionInDirectedGraph( int n , vector<vector<int>> &edges )
{
    unordered_map<int , list<int>> adj;
    for(int i = 0;i<edges.size();i++)
    {
        int u = edges[i][0];  
        int v = edges[i][1]; 
        adj[u].push_back(v);
    }

    vector<int> indegree(n+1);
    for(auto i: adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }

    queue<int> q;
    for(int i = 1 ;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    int cnt= 0;
    while(!q.empty()){
        int front = q.front();
        q.pop();

        cnt++ ;

        for(auto neighbour : adj[front]){
            indegree[neighbour]-- ;
            if(indegree[neighbour]==0){
                q.push(neighbour);
            }
        }
    }
    if(cnt==n){
        return false;
    }
    else{
        return true;
    }
}


int main()
{
    int n = 6;
    vector<vector<int>> edges = { {1,2} ,{1,3} , {2,4} , {3,4} , {4,6} , {4,5} , {5,6}};
    int ans = cycleDetectionInDirectedGraph( n , edges);
    if(ans == 1){
        cout<<"Cycle Detected."<<endl;
    }
    else{
        cout<<"No Cycle Detected."<<endl;
    }
    return 0;
}
