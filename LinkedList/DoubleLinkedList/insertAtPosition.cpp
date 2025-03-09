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

void insertAtHead(Node* &head , int d){
    Node* temp = new Node(d);
    temp->next= head;
    head->prev = temp;
    head = temp;
}


void insertAtTail(Node* &tail , int d){
    Node* temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtPosition(Node* &head, Node* &tail , int position , int d){
    if(position==1){
        insertAtHead(head,d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while(cnt<position-1){
        temp = temp->next ;
        cnt++ ;
    }

    if(temp->next==NULL){
        insertAtTail(tail,d);
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
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail =  node1;
    insertAtPosition(head,tail,1,9);
    insertAtPosition(head,tail,3,12);
    insertAtPosition(head,tail,3,11);
    print(head);
    return 0;
}
