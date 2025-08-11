#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {  
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        if (this->next == NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};

class Queue
{
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = rear = NULL;
    }

    void enqueue(int data)
    {
        Node *temp = new Node(data);

        if (rear == NULL)
        {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    void dequeue()
    {
        if (front == NULL)
        {
            cout << "Queue is empty." << endl;
            return;
        }
        Node *temp = front;
        front = front->next;

        if (front == NULL)
        {
            rear = NULL;
        }
        temp->next = NULL;
        delete temp;
    }

    int getFront()
    {
        if (front == NULL)
        {
            cout << "Queue is empty." << endl;
            return -1;
        }
        else
        {
            return front->data;
        }
    }

    void print()
    {
        Node *temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Queue elements: ";
    q.print();

    cout << "Front element: " << q.getFront() << endl;

    q.dequeue();
    cout << "Queue after dequeue: ";
    q.print();

    return 0;
}
