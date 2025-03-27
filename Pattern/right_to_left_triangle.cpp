#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the value of n: "<<endl;
    cin>>n ;

    for(int i=1 ;i<=n ;i++){
        int space = n-i ;
        while(space>0){
            cout<<" ";
            space = space - 1; 
        }
        for(int j=1;j<=i ;j++){
            cout<<"*" ;
        }
        cout<<endl;
    }
    return 0;
}
