#include<iostream>
using namespace std;

int main()
{
    int a , b ;
    char op ;
    cout<<"Enter the value of a and b: "<<endl;
    cin>>a>>b ;

    cout<<"Enter the operation you want to perform: "<<endl;
    cin>>op ;
    
    switch(op){
        case '+' :
            cout<<"Addition: "<<a+b <<endl;
            break;
        case '-' :
             cout<<"Subtraction:" <<a-b<<endl;
             break;
        case '*':
            cout<<"Multiplication: "<<a*b<<endl;
            break;
        case '/':
            cout<<"Division: "<<a/b<<endl;
            break;
        default:
            cout<<"Please enter a valid operation."<<endl;
    }
    return 0;

}