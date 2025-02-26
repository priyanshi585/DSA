#include<iostream>
using namespace std ;

int main()
{
    float feh , cel ;
    feh = -50 ;
    while(feh <=1000){
       cel = (feh-32)/(1.8) ;
       cout<<feh <<"F" << "\t" << cel<<"C" <<endl;
       feh = feh +10 ;
    }
    return 0;

}