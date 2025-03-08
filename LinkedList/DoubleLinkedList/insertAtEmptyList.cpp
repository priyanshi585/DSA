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
      this->prev = NULL;
    }
};
  
  void print(Node* &head ){
      Node* temp = head;
      while(temp!=NULL){
          cout<<temp->data<<" ";
          temp = temp->next;
      }
  
}

void insertAtHead(Node* &head, Node* &tail , int d){
    if(head==NULL){
       Node* temp = new Node(d);
       head= temp;
       tail = temp;
    }else{
        Node* temp = new Node(d);
        temp->next= head;
        head->prev = temp;
        head = temp;
    }
    
}


void insertAtTail(Node* &head, Node* &tail , int d){
    if(tail==NULL){
        Node* temp = new Node(d);
        head= temp;
        tail = temp;
    }else{
        Node* temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    
}

void insertAtPosition(Node* &head, Node* &tail , int position , int d){
    if(position==1){
        insertAtHead(head,tail,d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while(cnt<position-1){
        temp = temp->next ;
        cnt++ ;
    }

    if(temp->next==NULL){
        insertAtTail(head,tail,d);
        return;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

int main()
{
    Node* head = NULL;
    Node* tail =  NULL;
    insertAtPosition(head,tail,1,9);
    insertAtPosition(head,tail,2,11);
    insertAtPosition(head,tail,3,12);
    print(head);
    return 0;
}
