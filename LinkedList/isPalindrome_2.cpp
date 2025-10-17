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

Node* getMid(Node* head){
    Node* slow = head;
    Node* fast = head->next;

    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
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

bool isPalindrome(Node* head){
    if(head->next==NULL){
        return true;
    }

    //fnding mid:
    Node* middle = getMid(head);

    //reverse mid ke baad vali list:
    Node* temp = middle->next;
    middle->next = reverse(temp);

    //compare both halves:
    Node* head1 = head;
    Node* head2 = middle->next;

    while(head2 != NULL)
    {
        if(head1->data != head2->data){
            return false;
        }
        else{
            head1 = head1->next;
            head2 = head2->next;
        }

        //repeat step 2 to get original LL :
        Node* temp = middle->next;
        middle->next = reverse(temp);

        return true;
    }
}

int main()
{
    Node* node1 = new Node(2);
    Node* head = node1;
    Node* tail = node1;
    insertAtPosition(head,tail,1,1);
    insertAtPosition(head,tail,3,1);
    insertAtPosition(head,tail,2,2);
    cout<<"Original LinkedList: "<<endl;
    print(head);
    if(isPalindrome(head)){
        cout<<"\nGiven Linkedlist is PALINDROME."<<endl;
    }
    else{
        cout<<"\nGiven linkedlist is NOT a palindrome."<<endl;
    }

    return 0;
}
