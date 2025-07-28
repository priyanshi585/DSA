#include<iostream>
#include<vector>
using namespace std;


int main()
{
    int n ;
    cout<<"Enter the value of n: "<<endl;
    cin>>n;

    vector<int> dp(n+1) ;
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i<= n ;i++){
        dp[i] = dp[i-2] + dp[i-1] ;
    }
    cout<<"Nth Fibonacci Number: "<<dp[n]<<endl;
    return 0;
}
