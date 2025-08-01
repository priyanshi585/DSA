#include<iostream>
#include<queue>
using namespace std;

int main()
{
    deque<int> d;
    d.push_front(11);
    d.push_back(21);
    d.push_front(13);
    d.push_back(19);
    d.push_front(15);
    d.push_back(17);
  
    cout<<"Element at front: "<<d.front()<<endl;
    cout<<"Element at back: "<<d.back()<<endl;

    d.pop_back();
    d.pop_front();
    d.pop_back();
    d.pop_front();

    cout<<"Element at front: "<<d.front()<<endl;
    cout<<"Element at back: "<<d.back()<<endl;

    if(d.empty()){
        cout<<"Deque is empty."<<endl;
    }
    else{
        cout<<"Deque is not empty."<<endl;
    }

    return 0;
}
