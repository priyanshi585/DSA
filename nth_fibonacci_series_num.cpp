#include<iostream>
using namespace std;

void printFibonacciSeries(int n){
    int prpr = 0;
    int pr = 1;
    int next ;
    int arr[n] ;
    int pos;
    cout<<prpr<<" "<<pr<<" ";
    arr[0] = 0;
    arr[1]=1;
    for(int i=2;i<n;i++){
        next = prpr+pr;
        cout<<next<<" ";
        arr[i] = next;
        prpr= pr;
        pr =next ;
    }

    cout<<"\nEnter the position of nth number:"<<endl;
    cin>>pos ;
    cout<<arr[pos];
}

int main()
{
    int n ;
    cout<<"Enter value of n till where you want to print series:"<<endl;
    cin>>n;

    printFibonacciSeries(n) ;
    
}
