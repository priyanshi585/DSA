#include<iostream>
using namespace std;

bool isPrime(int n)
{
    int factor_count = 0;
    for(int i = 1;i<=n;i++)
    {
        if(n%i==0){
            factor_count++ ;
        }
    }

    if(factor_count==2){
        return 1;
    }
    else{

        return 0;
    }


}

int main()
{
    int num ;
    cout<<"Enter value of num: "<<endl;
    cin>>num ;

   int ans = isPrime(num);
   if(ans == 1){
    cout<<"Prime Number."<<endl;
   }
   else{
    cout<<"Not a prime Number."<<endl;
   }
   return 0;
}
