#include<iostream>
using namespace std;

int setBitsA(int a )
{
    int count = 0;
    while(a!=0){
        if(a&1==1){
          count++ ;
        }
        a= a>>1;
    }
    return count;
}

int setBitsB(int b )
{
    int count = 0;
    while(b!=0){
        if(b&1==1){
          count++ ;
        }
        b= b>>1;
    }
    return count;
}

int main()
{
    int a , b;
    cout<<"Enter the value of a and b:" <<endl;
    cin>>a>>b;

    int set_bits_A = setBitsA(a);
    int set_bits_B= setBitsB(b);
    cout<<"Set bits of A = "<<set_bits_A<<endl;
    cout<<"Set bits of B = "<<set_bits_B<<endl;
    int total_bits = set_bits_A + set_bits_B ;
    cout<<"Total number of set bits in a and b are: "<<total_bits<<endl;
    return 0;

}
