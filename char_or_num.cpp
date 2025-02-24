#include<iostream>
using namespace std;

int main()
{
    char ch ;
    cout<<"Enter any character: "<<endl;
    cin>>ch ;

    if(ch>='a' && ch<='z'){
        cout<<"Lowercase Alphabet"<<endl;
    }
    else if(ch>'A' && ch<='Z'){
        cout<<"Uppercase alphabet"<<endl;
    }
    else{
        cout<<"Numeric Character."<<endl;
    }
    return 0;
}