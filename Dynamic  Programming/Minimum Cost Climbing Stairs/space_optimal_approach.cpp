#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> &cost  , int n)
{
    int prev1 = cost[1] ;
    int prev2 = cost[0] ;

    for(int i = 2; i<n ;i++){
        int curr= cost[i] + min(prev1 , prev2) ;
        prev2 = prev1 ;
        prev1 = curr;
    }
    return min(prev1 , prev2) ;
}

int main()
{
    vector<int> cost = {10 , 15, 20} ;;
    int n = cost.size() ;
    int ans = solve(cost , n);
    cout<<"Minimum Cost Climbing Stairs: "<<ans<<endl;
    return 0;
}
