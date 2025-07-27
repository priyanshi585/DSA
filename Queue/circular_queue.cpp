#include <iostream>
#include <queue>
using namespace std;


class CircularQueue
{
    int *arr;
    int size;
    int front;
    int rear;

public:
    CircularQueue(int n)
    {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    void enqueue(int value)
    {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            cout << "Queue is Full" << endl;
        }

        else if (front == -1)
        {
            front = rear = 0;
            arr[rear] = value;
        }

        else if ((rear == size - 1) && front != 0)
        {
            rear = 0;
            arr[rear] = value;
        }

        else
        {
            rear++;
            arr[rear] = value;
        }
    }

    int dequeue()
    {
        if (front == -1)
        {
            cout << "Queue is Empty." << endl;
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;

        if (front == rear)
        {
            front = rear = -1;
        }

        else if (front == size - 1)
        {
            front = 0;
        }

        else
        {
            front++;
        }

        return ans;
    }
};

int main()
{
    CircularQueue q(5);
    q.enqueue(11) ;
    q.enqueue(13);
    q.enqueue(15);
    q.enqueue(17);
    q.enqueue(1);
    cout<<"Element deleted: "<<q.dequeue()<<endl;
    cout<<"Element deleted: "<<q.dequeue()<<endl;
    q.enqueue(21);
    q.enqueue(23);
    q.enqueue(25);
    return 0;
}
