#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> &cost  , int n)
{
    vector<int> dp(n+1) ;
    dp[0] = cost[0] ;
    dp[1] = cost[1];

    for(int i = 2 ;i<n ;i++){
        dp[i] = cost[i] + min(dp[i-1] , dp[i-2]);
    }

    return min(dp[n-1] , dp[n-2]) ;
}

int main()
{
    vector<int> cost = {10 , 15, 20} ;;
    int n = cost.size() ;
    int ans = solve(cost , n);
    cout<<"Minimum Cost Climbing Stairs: "<<ans<<endl;
    return 0;
}
