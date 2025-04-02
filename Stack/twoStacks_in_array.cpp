#include <iostream>
using namespace std;

class twoStack
{
public:
    int *arr;
    int top1;
    int top2;
    int size;

    twoStack(int size)
    {
        this->size = size;
        top1 = -1;
        top2 = size;
        arr = new int[size];
    }

    void push1(int elem)
    {
        if (top2 - top1 > 1)
        {
            top1++;
            arr[top1] = elem;
        }
    }

    void push2(int elem){
        if(top2-top1 >1 ){
            top2-- ;
            arr[top2] = elem;
        }
    }


    int pop1()
    {
        if(top1>=0){
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else{
            return -1;
        }
    }

    int pop2(){
        if(top2>=0){
            int ans = arr[top2];
            top2++ ;
            return ans;
        }
        else{
            return -1;
        }
    }
};

int main()
{
    twoStack s(7);
    s.push1(1);
    s.push2(7);
    s.push1(2);
    s.push2(6);
    s.push1(3);
    s.push2(5);
    s.push1(4);

    cout<<"Top element of stack 1: "<< s.pop1()<<endl;
    cout<<"Top element of stack 1: "<< s.pop1()<<endl;
    cout<<"Top element of stack 1: "<< s.pop1()<<endl;
    cout<<"Top element of stack 1: "<< s.pop1()<<endl;
    cout<<"Top element of stack 2: "<< s.pop2()<<endl;
    cout<<"Top element of stack 2: "<< s.pop2()<<endl;
    cout<<"Top element of stack 2: "<< s.pop2()<<endl;

    return  0;
    
}
