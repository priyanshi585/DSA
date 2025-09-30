#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int>&s , int elem)
{
    //base case:
    if(s.empty()){
        s.push(elem);
        return ;
    }
  
    int num = s.top();  
    s.pop();

    //recursive call:
    insertAtBottom(s,elem);
    
    s.push(num);
}

void  reverseStack(stack<int>&s)
{
     //base case:
     if(s.empty()){
        return ;
     } 

     int num = s.top();
     s.pop();

     //recursive call:
     reverseStack(s);

     insertAtBottom(s , num);
}

void print(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

int main()
{

    stack<int> s;
    s.push(5);
    s.push(9);
    s.push(12);
    s.push(8);
    s.push(4) ;
    cout<<"Original Stack:"<<endl;
    print(s);
    reverseStack(s);
    cout<<"Reversed Stack: "<<endl;
    print(s);

    return 0;
}
