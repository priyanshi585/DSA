#include <iostream>
using namespace std;

class Stack
{
public:
    int *arr;
    int top;   
    int size;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element){
        if(size-top > 1){
            top++ ;
            arr[top]= element;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }
    }

    void pop(){
        if(top>=0){
            top-- ;
        }
        else{
            cout<<"Stack Underflow"<<endl;
        }
    }

    int peek(){
        if(top>=0 && top<size){
            return arr[top];
        }
        else{
            cout<<"Stack is empty."<<endl;
            return -1;
        }
    }

    bool isEmpty()
    {
        if(top== -1){
            return true;
        }
        else{
            return false;
        }
    }
};

int main()
{

    Stack s(5) ;
    s.push(22);
    s.push(44);
    s.push(66);
    cout<<"Top element: "<<s.peek()<<endl;
    s.pop();
    cout<<"Top element: "<<s.peek()<<endl;
    s.pop();
    cout<<"Top element: "<<s.peek()<<endl;
    s.pop();
    cout<<"Top element: "<<s.peek()<<endl;

    if(s.isEmpty()){
        cout<<"Stack is Empty."<<endl;
    }
    else{
        cout<<"Stack is not empty."<<endl;
    }
    return 0;
}
