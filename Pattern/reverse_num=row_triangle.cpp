#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the value of n: "<<endl;
    cin>>n ;
    

    for(int i=1 ;i<=n ;i++){
        int value = i ;
        for(int j=1;j<=i ;j++){
            // cout<<value<<" " ;*
            // other method: ->
            cout<<i-j+1 <<" ";
            value-- ;
        }
        
        cout<<endl;
    }
    return 0;
}
