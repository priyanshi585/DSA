#include <iostream>
using namespace std;

class Queue
{
    int *arr;
    int front;
    int rear;  
    int size;

public:
    Queue()
    {
        size = 100001;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    void enqueue(int data)
    {
        if (rear == size)
        {
            cout << "Queue is full." << endl;
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue()
    {
        if (front == rear)
        {
            cout << "Queue is empty..Can't do dequeue operation." << endl;
        }
        else
        {

            int ans = arr[front];
            arr[front] = -1;
            front++;
            if (front == rear)
            {
                front = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int getfront()
    {
        if (front == rear)
        {
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    bool isEmpty()
    {
        if (front == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{

    Queue q;
    q.enqueue(11);
    q.enqueue(13);
    q.enqueue(15);

    q.dequeue();
    q.dequeue();

    cout << "Element at front in queue is: " << q.getfront() << endl;

    if (q.isEmpty())
    {
        cout << "Queue is empty." << endl;
    }
    else
    {
        cout << "Queue is not empty." << endl;
    }
    return 0;
}
