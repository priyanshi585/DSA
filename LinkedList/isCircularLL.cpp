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


bool isCircular(Node* head)
{
    if(head==NULL){
        return true;
    }
    Node* temp = head->next;
    while(temp!=NULL && temp!=head){
        temp = temp->next;
    }

    if(temp == head){
        return true;
    }

    return false;
}

int main()
{
    Node* tail = NULL;
    print(tail);
    insertNode(tail, 5 ,3);
    print(tail);
    insertNode(tail,3,5);
    print(tail);
    insertNode(tail,5,7);
    print(tail);
    insertNode(tail,7,9);
    print(tail);

    if(isCircular(tail)){
        cout<<"\nLinkedlist is CIRCULAR in nature."<<endl;
    }
    else{
        cout<<"\nLinkedlist is NOT CIRCULAR in nature."<<endl;   
    }
    return 0;
}
