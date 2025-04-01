#include<iostream>
#include<stack>
using namespace std;

void sortedInsert(stack<int>&s , int num){
    //base case:
    if(s.empty() || (!s.empty() && s.top()<num)){
        s.push(num);
        return ;
    }

    int n = s.top() ;
    s.pop();

    //recursion:
    sortedInsert(s , num);

    s.push(n);
}

void sortStack(stack<int>&s){
    //base case:
    if(s.empty()){
        return ;
    }

    int num = s.top();
    s.pop();

    //recursive call:
    sortStack(s);

    //sorted way me insert
    sortedInsert(s,num);
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
    s.push(-2);
    s.push(9);
    s.push(-7);
    s.push(3);

    cout<<"Original Stack: "<<endl;
    print(s);

    sortStack(s);

    cout<<"Sorted Stack: "<<endl;
    print(s);

    return 0;
}
