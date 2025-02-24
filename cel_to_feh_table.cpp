#include<iostream>
using namespace std ;

int main()
{
    float feh , cel ;
    cel = -50 ;
    while(cel <=1000){
       feh = ((1.8)*cel) + 32  ;
       cout<<cel <<"C" << "\t" << feh<<"F" <<endl;
       cel = cel +10 ;
    }
    return 0;

}