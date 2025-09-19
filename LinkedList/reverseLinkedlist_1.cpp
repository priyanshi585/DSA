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
 
 void print(Node* &head)
 {
     Node* temp = head;
     while(temp!= NULL){
         cout<<temp->data<<" ";
         temp = temp->next;
     }
 }

 Node* reverseLinkedlist(Node* &head){
    if(head==NULL || head->next == NULL){
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while(curr!=NULL){
        forward = curr->next;
        curr->next= prev;
        prev= curr;
        curr= forward;
    }

    return prev;
 }
 
 int main()
 {
     Node* node1 = new Node(10);
     Node* head = node1;
     Node* tail = node1;
     insertAtPosition(head,tail,1,9);
     insertAtPosition(head,tail,3,12);
     insertAtPosition(head,tail,4,11);
     print(head);

     cout<<"\nAfter reversing:"<<endl;
     Node* ans = reverseLinkedlist(head);
     print(ans);
     return 0;
 }
