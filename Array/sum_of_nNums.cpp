
#include<iostream>
using namespace std;

int main()
{
    int n ;
    cout<<"Enter the value of n : "<<endl;
    cin>>n ;

    int sum = 0 , i = 1;
    while(i<=n){
      sum = sum + i ;
      i = i+1 ;
    }

    cout<<"Sum of n numbers is : "<<sum ;
    return 0;
}
