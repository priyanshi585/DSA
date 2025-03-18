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

   ~Node(){
    int value = this->data;
    if(this->next!=NULL){
        delete next;
        this->next= NULL;
    }
    cout<<"\nMemory freed for node with data "<<value<<endl;
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


Node* removeDuplicates(Node* head){
    if(head==NULL){
        return NULL;
    }

    Node* curr = head;

    while(curr!=NULL){

        if((curr->next != NULL) && curr->data == curr->next->data){
           // lagataar 2 elements = aa rhe hai mtlb duplicate elements hai...
           Node* nextToNext = curr->next->next;
           Node* nodeToDelete = curr->next;
           delete(nodeToDelete);
           curr->next = nextToNext ;
        }
        else{ //not equal mtlb simple aage badao
          curr = curr->next;
        }
    }
    return head;
}


int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    insertAtPosition(head,tail,1,9);
    insertAtPosition(head,tail,2,10);
    insertAtPosition(head,tail,4,11);
    insertAtPosition(head,tail,4,11);
    print(head);
    Node* ans = removeDuplicates(head);
    cout<<"\nList after removing dupicates: ";
    print(ans); 
    return 0;
}
