#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<unordered_map>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges , int v  , int e)
{
    unordered_map<int , list<int>> adj;
    for(int i = 0;i<e;i++)
    {
        int u = edges[i][0];
        int dist = edges[i][1];
        adj[u].push_back(dist);
    }

    vector<int> indegree(v+1);
    for(auto i: adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }

    queue<int> q;
    for(int i = 1 ;i<=v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    vector<int> ans;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        ans.push_back(front);
        for(auto neighbour : adj[front]){
            indegree[neighbour]-- ;
            if(indegree[neighbour]==0){
                q.push(neighbour);
            }
        }
    }
    return ans;
}


int main()
{
    int v = 6;
    int e = 7;
    vector<vector<int>> edges = { {1,2} ,{1,3} , {2,4} , {3,4} , {4,6} , {4,5} , {5,6}};
    vector<int> ans = topologicalSort(edges , v , e);
    cout << "Topological Sort: ";
    for (int node : ans) {
        cout << node << " ";
    }
    cout << endl;
    return 0;
}
