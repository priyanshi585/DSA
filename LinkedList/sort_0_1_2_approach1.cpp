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


Node* sortList(Node* head){
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    Node* temp = head;
    while(temp!=NULL){
        if(temp->data==0){
            zeroCount++;
        }
        else if(temp->data==1){
            oneCount++;
        }
        else if(temp->data==2){
            twoCount++ ;
        }

        temp = temp->next;
    }

    temp = head;

    while(temp!=NULL){
        if(zeroCount!=0){
            temp->data = 0;
            zeroCount--;
        }
        else if(oneCount!=0){
            temp->data = 1;
            oneCount--;
        }
        else if(twoCount != 0){
            temp->data = 2;
            twoCount-- ;
        }
        temp = temp->next ;
    }
    return head;
}



int main()
{
    Node* node1 = new Node(0);
    Node* head = node1;
    Node* tail = node1;
    insertAtPosition(head,tail,1,1);
    insertAtPosition(head,tail,2,1);
    insertAtPosition(head,tail,4,2);
    insertAtPosition(head,tail,4,0);
    cout<<"Original Linkedlist: \n";
    print(head);
    cout<<endl;
    Node* ans = sortList(head);
    cout<<"LinkedList after sorting 0s 1s and 2s:\n";
    print(head);
    return 0;
}
