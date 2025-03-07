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

    ~Node(){
        int value = this->data;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"Memory freed for node with data "<<value<<endl;
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


void deleteNode(Node* &tail ,Node* &head , int position)
{
    if(position==1){
        Node* temp =head ;
        temp->next->prev= NULL;
        head = temp->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt<position){
            prev = curr;
            curr= curr->next;
            cnt++;
        }
        
        curr->prev=NULL;
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
        if(prev->next==NULL){
            tail = prev;
        }
        
    }
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

    deleteNode(tail,head,1);
    print(head);
    cout<<"\ntail "<<tail->data<<endl;
    cout<<"head "<<head->data<<endl;
    return 0;
}
