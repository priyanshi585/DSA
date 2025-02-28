#include<iostream>
using namespace std;

int nth_term(int n)
{
    int ans = (3*n)+7;
    return ans;
}

int main()
{
    int n ;
    cout<<"Enter the value of n :"<<endl;
    cin>>n;

    int ans = nth_term(n);
    cout<<"The nth term of given AP is: "<<ans<<endl;
    return 0;
    


}
