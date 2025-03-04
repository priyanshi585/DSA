#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the value of n: "<<endl;
    cin>>n;
    int sum = 0;
    int i = 2;
    while(i<=n){
        sum = sum + i ;
        i =i+2 ;
    }
    cout<<"Sum of even numbers is "<<sum<<endl;
    return 0;
}
