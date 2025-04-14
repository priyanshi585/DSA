#include<iostream>
#include<queue>
#include<stack>
using namespace std;

queue<int> interleaveTwoHalves(queue<int> q , int n)
{
    stack<int> s;
    
    for(int i=0; i<n/2 ; i++){
        int val = q.front();
        q.pop();
        s.push(val);
    }

    while(!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    for(int i = 0 ; i<n/2 ;i++){
        int val = q.front();
        q.pop();
        q.push(val);
    }

    for(int i = 0;i<n/2;i++){
        int val = q.front();
        q.pop();
        s.push(val);
    }

    while(!s.empty()){
        int val = s.top();
        s.pop();
        q.push(val);
        val = q.front();
        q.pop();
        q.push(val);
    }

    return q;
}

void print(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

int main()
{
  queue<int> q ;
  q.push(11);
  q.push(12);
  q.push(13);
  q.push(14);
  q.push(15);
  q.push(16);
  q.push(17);
  q.push(18);
  cout<<"Original Queue: ";
  print(q);
  queue<int> ans = interleaveTwoHalves(q,8);
  cout<<"Queue after interleaving two halves: ";
  print(ans);
  return 0;
}
