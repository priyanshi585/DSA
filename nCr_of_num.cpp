#include<iostream>
using namespace std;


int factorial(int n)
{
    int fac = 1 ;
    for(int i=1;i<=n;i++){
        fac = fac*i ;
    }
    return fac ;
}

int nCr(int n , int r)
{
int numerator = factorial(n);
    int denominator = factorial(r) * factorial(n-r) ;

    int answer = numerator/denominator ;
    return answer ;
}

int main()
{
    int n , r ;
    cout<<"Enter te value of n and r: "<<endl;
    cin>>n>>r ;

    int ans = nCr(n ,r);
    cout<<"nCr of given number is : "<<ans <<endl;
    return 0;

    

}
