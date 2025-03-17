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

bool checkPalindrome(vector<int> arr){
    int n = arr.size();
    int s =0;
    int e = n-1 ;

    while(s<=e){
        if(arr[s]!=arr[e]){
            return 0;
        }
        else{
            s++;
            e--;
        }
        return 1;
    }
}

bool isPalindrome(Node* head){
    vector<int> arr ;

    Node* temp = head;
    while(temp!=NULL){
        arr.push_back(temp->data);
        temp=temp->next;
    }
    return checkPalindrome(arr);
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
