#include<iostream>
#include<queue>
using namespace std;


int circularTour(int p[] , int d[] , int n){
    int deficit = 0;
    int balance = 0;
    int start = 0;

    for(int i = 0 ;i<n;i++){
        balance = balance + p[i] - d[i] ;

        if(balance<0){
            deficit = deficit + balance ;
            start = i+1;
            balance = 0;
        }
    }

    if(deficit + balance >=0){
        return start;
    }
    else{
        return -1;
    }
}

int main()
{

    int p[] = {4,6,7,3};
    int d[] = {6,5,3,5};
    int n = 4;
    int ans = circularTour(p,d,n);
    if(ans == -1){
        cout<<"Circular Tour Not possible."<<endl;
    }
    else{
        cout<<"Circular Tour is possible with START = "<<ans<<endl;
    }

    return 0;

}
