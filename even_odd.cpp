#include<iostream>
using namespace std;

//1->even
//0-> odd
bool isEven(int num)
{
   if(num%2==0){
    return 1;
   }
   else{
    return 0;
   }
}

int main()
{
    int num ;
    cout<<"Enter the value of num: "<<endl;
    cin>>num ;

    int answer = isEven(num) ;
    if(answer==1){
cout<<"The given number is Even"<<endl;
    }
    else{
        cout<<"The given number is odd"<<endl;
    }
    
    return 0;
    
}