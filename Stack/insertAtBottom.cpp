#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int>&s , int elem)
{
    //base case:
    if(s.empty()){
        s.push(elem);
        return ;  
    }

    int num = s.top();  
    s.pop();   

    //recursive call:
    solve(s,elem);
    
    s.push(num);
}

stack<int> pushAtBottom(stack<int>&myStack , int element)
{
    solve(myStack,element);
    return myStack;
}

void print(stack<int> inputStack){
    while(!inputStack.empty()){
        cout<<inputStack.top()<<" ";
        inputStack.pop();
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

    pushAtBottom(s , 100);
    cout<<"Stack after inserting element at the bottom: "<<endl;
    print(s);
    return 0;
}
