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

void insertNode(Node* &tail , Node* curr){
    tail->next = curr;
    tail=curr;
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
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head;

    while(curr!=NULL){
        int value = curr->data ;

        if(value==0){
            insertNode(zeroTail,curr);
        }
        else if(value==1){
            insertNode(oneTail,curr);
        }
        else if(value==2){
            insertNode(twoTail,curr);
        }
        curr = curr->next;
    }

    if(oneHead->next!=NULL){
        zeroTail->next = oneHead->next;
    }else{
        zeroTail->next = twoHead->next;
    }

    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    head = zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead ;

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
    print(ans);
    return 0;
}
