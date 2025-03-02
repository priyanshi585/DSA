#include<iostream>
using namespace std;

int main()
{
    int num , factors=0 , onlyTwo = 2 ;
    cout<<"Enter a number: "<<endl;
    cin>>num ;

    for(int i=1;i<=num;i++){
        if(num%i==0){
            factors = factors + 1;
        }
    }

    if(factors == onlyTwo){
        cout<<"Prime"<<endl;
    }
    else{
        cout<<"Not Prime"<<endl;
    }

    return 0;

}
