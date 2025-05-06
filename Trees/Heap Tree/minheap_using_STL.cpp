#include<iostream>
#include<queue>
using namespace std;

int main()
{
    priority_queue<int , vector<int> , greater<int> > p;

    p.push(4);
    p.push(3);
    p.push(2);
    p.push(5);

    cout<<"Element at top: "<<p.top()<<endl;

    p.pop();

    cout<<"Element at top: "<<p.top()<<endl;

    cout<<"Size of Heap: "<<p.size()<<endl;
    
    if(p.empty()){
        cout<<"Empty Heap."<<endl;
    }
    else{
        cout<<"Heap is not Empty."<<endl;
    }
    return 0;
}
