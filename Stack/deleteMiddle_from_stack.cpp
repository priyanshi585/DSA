#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int>&inputStack , int count , int size){
    //base case:
    if(count == size/2){
        inputStack.pop() ;
        return ;
    }

    int num = inputStack.top() ;
    inputStack.pop() ;

    //recursive call:
    solve(inputStack , count+1 , size);

    inputStack.push(num) ;
}

void deleteMiddle(stack<int>&inputStack , int N){
    int count = 0 ;
    solve(inputStack , count , N);
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
    deleteMiddle(s,5);
    cout<<"Stack After deleting middle element: "<<endl;
    print(s);

    return 0;
}
