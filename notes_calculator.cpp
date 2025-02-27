#include<iostream>
using namespace std;

int main()
{
    int amount ;
    cout<<"Enter the amount:"<<endl;
    cin>>amount ;
    int hundred = amount / 100 ;
    amount = amount%100;
    int fifty = amount /50 ;
    amount = amount %50 ;
    int twenty = amount /20 ;
    amount = amount%20;
    int ones = amount/1;
    amount= amount%1;

    cout<<"Following Amount requires: "<<hundred<<" notes of hundred ruppes "<<fifty<<" notes of fifty ruppes "<<twenty<<" notes of twenty ruppes "<<ones<<" notes of one ruppe."<<endl;

    return 0;

}
