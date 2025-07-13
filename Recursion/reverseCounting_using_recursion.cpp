#include<iostream>
using namespace std;

void printReverseCounting(int n)
{
    if(n==0){
        return;
    }
    cout<<n<<endl;
    printReverseCounting(n-1);
}

int main() 
{
    int n;
    cout<<"Enter value of n till where you want to print the counting: "<<endl;
    cin>>n;
    printReverseCounting(n);
    return 0;
}
