#include<iostream>
#include<vector>
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

Node* reverse(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    while(curr!=NULL){
        next = curr->next;
        curr->next= prev;
        prev = curr;
        curr= next;
    }
    return prev;
}

void insertIntoLL(Node* &head ,Node* &tail , int d){
    Node* temp = new Node(d);
    if(head==NULL){
       head = temp;
       tail = temp;
       return;
    }
    else{
        tail->next = temp;
        tail = temp;
    }
}

Node* add(Node* first , Node* second){
    int carry = 0;
    Node* ansHead = NULL ;
    Node* ansTail = NULL;

    while(first!=NULL || second!=NULL ||carry!=0){
        int val1 = 0;
        if(first!=NULL){
            val1 = first->data;
        }

        int val2 = 0;
        if(second!=NULL){
            val2 = second->data;
        }

        int sum = carry + val1 + val2 ;
        int digit = sum%10;
        insertIntoLL(ansHead , ansTail , digit);
        carry = sum/10;

        if(first!=NULL){
            first=first->next;
        }
        if(second!=NULL){
            second= second->next;
        }
    }
    return ansHead ;
}

Node* addTwoLL(Node* first , Node* second){
    first = reverse(first);
    second = reverse(second);

    Node* ans = add(first , second);
    ans = reverse(ans);

    return ans;
}


int main()
{
    Node* node1 = new Node(5);
    Node* head1 = node1;
    Node* tail1 = node1;
    insertAtPosition(head1,tail1,1,4);
    cout<<"\nLinkedList 1: "<<endl;
    print(head1);
    cout<<endl;
    
    Node* node2 = new Node(4);
    Node* head2 = node2;
    Node* tail2 = node2;
    insertAtPosition(head2,tail2,1,3);
    insertAtPosition(head2,tail2,3,5);
    cout<<"\nLinkedList 2: "<<endl;
    print(head2);
    cout<<endl;

    Node* ans = addTwoLL(head1 , head2);
    cout<<"\nAdded list: \n" ;
    print(ans);
    

    return 0;
}
