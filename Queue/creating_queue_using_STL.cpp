#include<iostream>
#include<queue>
using namespace std;

int main()
{
    queue<int> q;
    q.push(11) ;
    q.push(13);
    q.push(15);
  
    cout<<"Size of queue is: "<<q.size()<<endl;

    q.pop();
    q.pop();

    cout<<"Element at front in queue is: "<<q.front()<<endl;

    if(q.empty()){
        cout<<"Queue is empty."<<endl;
    }
    else{
        cout<<"Queue is not empty."<<endl;
    }
    return 0;
}
