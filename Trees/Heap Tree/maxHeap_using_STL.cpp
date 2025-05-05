#include<iostream>
#include<queue>
using namespace std;

int main()
{
    priority_queue<int> pq;

    pq.push(4);
    pq.push(2);
    pq.push(3);
    pq.push(5);

    cout<<"Element At top: "<<pq.top()<<endl;
    pq.pop() ;
    cout<<"Element At top: "<<pq.top()<<endl;

    cout<<"Size of Heap is: "<<pq.size()<<endl;
    return 0;
}
