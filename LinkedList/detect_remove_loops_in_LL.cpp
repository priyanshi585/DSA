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

Node* detectLoop(Node* &head){
    if(head==NULL){
        return NULL ;
    }
    Node* slow = head;
    Node* fast = head;

    while(slow!=NULL && fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
          fast = fast->next;
        }
        slow = slow->next;
        if(slow==fast){
            return slow;
        }
    }
    return NULL;
}

Node* getStartingNode(Node* &head){
    if(head==NULL){
        return NULL;
    }
    Node* intersection = detectLoop(head);
    Node* slow = head;
    while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;
}


void removeLoop(Node* head){
    if(head==NULL){
        return;
    }
    Node* startingPoint = getStartingNode(head);
    Node* temp = startingPoint;
    while(temp->next != startingPoint){
        temp = temp->next;
    }
    temp->next = NULL;
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
    tail->next = head->next;
    if(detectLoop(head)!=NULL){
        cout<<"\nLoop is present."<<endl;
    }
    else{
        cout<<"\nLoop is not present."<<endl;
    }

    Node* startingPoint = getStartingNode(head);
    cout<<"Loop starts from "<<startingPoint->data<<endl;

    removeLoop(head);
    cout<<"List after removing loop: ";
    print(head);

    if(detectLoop(head)!=NULL){
        cout<<"\nLoop is present."<<endl;
    }
    else{
        cout<<"\nLoop is not present."<<endl;
    }

    return 0;
}
