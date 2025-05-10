#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n ;
    cout<<"Enter the value of n: "<<endl;
    cin>>n;

    int prev1 = 1;
    int prev2 = 0;
    int curr;

    for(int i = 2; i<= n ;i++){
        curr = prev1 + prev2 ;
        prev2 = prev1;
        prev1 = curr;
    }
    cout<<"Nth Fibonacci Number: "<<prev1<<endl;
    return 0;
}
