#include <iostream>
#include <queue>
#include <stack>
using namespace std;

queue<int> reverseQueue(queue<int> &q)
{
    stack<int> s;
    while (!q.empty())
    {
        int element = q.front();
        q.pop();
        s.push(element);
    }  

    while (!s.empty())
    {
        int element = s.top();
        s.pop();
        q.push(element);
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
    queue<int> q;
    q.push(11);
    q.push(13);
    q.push(15);
    q.push(17);
    q.push(19);
    cout << "Original Queue: ";
    print(q);
    reverseQueue(q);
    cout << "Reversed Queue : ";
    print(q);
    return 0;
}
