#include<iostream>
#include<queue>
#include<stack>
using namespace std;

queue<int> modifyQueue(queue<int> &q , int k)
{
    stack<int> s;

    for(int i=0;i<k;i++){
        int val = q.front();  
        q.pop();
        s.push(val);
    }

    while(!s.empty()){
        int val = s.top();
        s.pop();
        q.push(val);
    }

    int t = q.size() - k;
    while(t--){
        int val = q.front();
        q.pop();
        q.push(val);
    }

    return q;
}

void print(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}


int main()
{
   queue<int> q ;
   q.push(1);
   q.push(2);
   q.push(3);
   q.push(4);
   q.push(5);
   cout<<"Original Queue: ";
   print(q);
   modifyQueue(q,3);
   cout<<"After Reversing till K elements: ";
   print(q);
   return 0;
}
