#include<iostream>
using namespace std;

int count(int nStairs)
{
    if(nStairs<=0){
        return 0;
    }
    if(nStairs==0){
        return 1;
    }

    int ans = count(nStairs-1) + count(nStairs-2);
    return ans;
}

int main()
{
    int nStairs;
    cout<<"Enter the value of n: "<<endl;
    cin>>nStairs;
    int ans = count(nStairs);
    cout<<"Number of Ways to reach the nth stairs: "<<ans<<endl;
    return 0;
}