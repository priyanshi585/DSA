#include<iostream>
using namespace std;

int main()
{
    int n ;
    cout<<"Enter the value of n :"<<endl;
    cin>>n ;
    int pr , prpr , next ;

    pr = 1;
    prpr = 0;
    cout<<prpr<<" " << pr<<" " ;
    for(int i = 2 ;i<n;i++){
       next = pr + prpr ;
       cout<<next<<" " ;
       prpr =pr ;
       pr = next ;
    }
    return 0;
}