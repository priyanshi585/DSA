#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>> &edges)
{
    vector<int> ans[n];
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1]; 
        ans[u].push_back(v);
        ans[v].push_back(u);
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++)
    {
        adj[i].push_back(i);
        for (int j = 0; j < ans[i].size(); j++)
        {
            adj[i].push_back(ans[i][j]);
        }
    }
    return adj;
}

int main()
{
    int n;
    cout << "Enter the number of nodes: " << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges: " << endl;
    cin >> m;

    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 1}, {3, 4}, {0, 4}};
    vector<vector<int>> ans = printAdjacency(n, m, edges);
    
    cout << "\nAdjacency List:" << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i][0] << " -> ";
        for (int j = 1; j < ans[i].size(); j++)
        {
            cout << ans[i][j];
            if (j != ans[i].size() - 1)
                cout << ", ";
        }
        cout << endl;
    }

    return 0;
}
