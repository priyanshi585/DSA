// remove duplicates from unsorted list using map method .... - O(n)

#include<iostream>
#include<map>
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
    // cout<<"\nMemory freed for node with data "<<value<<endl;
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
    map<int,bool> visited;

    Node* curr = head;
    Node* prev = NULL;
    while(curr!=NULL){
        if(visited[curr->data]==true){
            prev->next = curr->next;
            delete(curr);
            curr = prev->next;
            
        }
        visited[curr->data] = true;
        prev = curr;
        curr =curr->next;

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
    head= removeDuplicates(head);
    cout<<"\nList after removing dupicates: ";
    print(head); 
    return 0;
}
