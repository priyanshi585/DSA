#include<iostream>
using namespace std;

int main(){
    int a ;
    cout<<"Enter the value of a number: "<<endl;
    cin>>a;
    if(a>0){
        cout<<"The given number is positive." <<endl;
    }
    else if(a<0){
        cout<<"The given number is negative." <<endl;
    }
    else{
        cout<<"The given number is zero."<<endl;
    }

    return 0;
}
