#include<iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* prev;
  Node* next;

  Node(int data){
    this->data = data;
    this->next = NULL;
  }
};

int getLength(Node* &head ){
    Node* temp = head;
    int len=0;
    while(temp!=NULL){
        len++;
        temp = temp->next;
    }
    return len;

}

void insertAtHead(Node* &head , int d)
{
    Node* temp = new Node(d);
    temp->next = head;
    head = temp; 
}

void insertAtTail(Node* &tail , int d)
{
    Node* temp = new Node(d);
    tail->next = temp;
    tail = tail->next; //tail = temp;
    
}

void insertAtPosition(Node* &head , Node* &tail , int position , int d)
{
    if(position==1){
        insertAtHead(head,d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while(cnt<position-1){
        temp = temp->next;
        cnt++;
    }

    if(temp->next==NULL){
        insertAtTail(tail,d);
        return ;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

Node* findMiddle(Node* head){
    int len = getLength(head);
    int ans = (len/2);
    Node* temp = head;
    int cnt = 0;
    while(cnt<ans){
        temp = temp->next;
        cnt++ ;
    }
    return temp;
}

int main()
{
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;
    insertAtPosition(head,tail,2,2);
    insertAtPosition(head,tail,3,3);
    insertAtPosition(head,tail,4,4);
    insertAtPosition(head,tail,5,5);
    Node* ans = findMiddle(head);
    
    cout<<"\nMiddle Of linkedlist:"<<ans->data;
    return 0;
}
