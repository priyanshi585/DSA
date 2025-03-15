#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        int val = this->data;
        if(this->next!=NULL){
           delete next;
           this->next = NULL;
        }
        cout<<"Memeory freed for node with data "<<val<<endl;
    }
};

void insertNode(Node* &tail , int element , int d)
{
    if(tail==NULL){
        Node* temp = new Node(d);
        tail = temp;
        temp->next = temp;
    }
    else{
        Node* curr = tail;
        while(curr->data!=element){
            curr = curr->next;
        }
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(Node* &tail)
{
    Node* temp = tail;
    if(tail==NULL){
        cout<<"List is empty."<<endl;
        return;
    }
    do{
        cout<<tail->data<<" ";
        tail= tail->next;
    }while(tail!=temp);
    cout<<endl;
}

void deleteNode(Node* &tail , int value)
{
    if(tail==NULL)
    {
        cout<<"List is empty."<<endl;
        return;
    }
    else{
        Node* prev = tail;
        Node* curr = prev->next;

        while(curr->data != value){
            prev= curr;
            curr= curr->next;
        }

        prev->next = curr->next;
        if(curr==prev){
            tail= NULL;
        }
        if(tail==curr){
            tail=prev;
        }
        curr->next = NULL;
        delete curr;
    }
}


int main()
{
    Node* tail = NULL;
    insertNode(tail, 5 ,3);
    insertNode(tail,3,5);
    insertNode(tail,5,7);
    insertNode(tail,7,9);
    print(tail);

    deleteNode(tail , 3);
    print(tail);
    return 0;
}
