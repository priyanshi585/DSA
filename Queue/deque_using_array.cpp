#include <iostream>
using namespace std;

class Deque
{
    int *arr;
    int size;
    int front;
    int rear;

public:
    Deque(int n)
    {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push_front(int value)
    {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            cout << "Deque is Full" << endl;
        }

        else if (front == -1)
        {
            front = rear = 0;
        }

        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
        }

        else
        {
            front--;
        }

        arr[front] = value;
    }

    void push_back(int value)
    {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            cout << "Queue is Full" << endl;
        }

        else if (front == -1)
        {
            front = rear = 0;
        }

        else if ((rear == size - 1) && front != 0)
        {
            rear = 0;
        }

        else
        {
            rear++;
        }

        arr[rear] = value;
    }

    int pop_front()
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

    int pop_back()
    {
        if (front == -1)
        {
            cout << "Queue is Empty." << endl;
            return -1;
        }

        int ans = arr[rear];
        arr[rear] = -1;

        if (front == rear)
        {
            front = rear = -1;
        }

        else if (rear == 0)
        {
            rear = size - 1;
        }

        else
        {
            rear--;
        }

        return ans;
    }

    int getFront()
    {
        if (isEmpty())
        {
            return true;
        }
        else
        {
            return arr[front];
        }
    }

    int getRear()
    {
        if (isEmpty())
        {
            return true;
        }
        else
        {
            return arr[rear];
        }
    }

    bool isEmpty()
    {
        if (front == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isFull()
    {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
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
    Deque d(7);
    d.push_front(11);
    d.push_back(21);
    d.push_front(13);
    d.push_back(19);
    d.push_front(15);
    d.push_back(17);

    cout<<"Element at front: "<<d.getFront()<<endl;
    cout<<"Element at back: "<<d.getRear()<<endl;

    d.pop_back();
    d.pop_front();
    d.pop_back();
    d.pop_front();

    cout<<"Element at front: "<<d.getFront()<<endl;
    cout<<"Element at back: "<<d.getRear()<<endl;

    if(d.isEmpty()){
        cout<<"Deque is empty."<<endl;
    }
    else{
        cout<<"Deque is not empty."<<endl;
    }

    return 0;
}
