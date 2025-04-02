#include<iostream>
using namespace std;

class Node{
   public:
   int data;
   Node* next;

  Node(int data){
    this->data = data;
    this-> next = NULL;
  }

  ~Node(){
    if(this->next !=NULL){
        delete next;
        this->next = NULL;
    }
  }
};

class Stack{
   public:
   Node* top ;

   Stack(){
    top = NULL ;
   }

   void push(int data ){
    Node* temp = new Node(data);
    temp->next = top;
    top= temp;
   }

   void pop(){
    if(isEmpty()){
        cout<<"Stack is already empty."<<endl;
        return ;
    }
    else{
        Node* temp = top;
        top = top->next;
        temp->next = NULL;
        delete temp;
    }
   }

   int peek(){
    if(isEmpty()){
        cout<<"Stack is  empty."<<endl;
        return -1;
    }
    else{
        return top->data;
    }
   }

   bool isEmpty(){
    if(top==NULL){
        return true;
    }
    else{
        return false;
    }
   }

   void print(){
      if(isEmpty()){
        cout<<"Stack is empty."<<endl;
      }
      else{
        Node* temp = top;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
      }
   }
};


int main()
{
    Stack s;
    s.push(20);
    s.push(40);
    s.push(60);

    s.print();  //60 40 20

    cout<<"Top Element: "<<s.peek()<<endl;  //60
    s.pop();
    s.print();  //40 20

    cout<<"Top Element: "<<s.peek()<<endl;  //40
    s.pop();
    s.print();   //20

    s.pop();
    cout<<"Top Element: "<<s.peek()<<endl;  //already empty
    s.print();  //empty

    if(s.isEmpty()){
        cout<<"Stack is Empty."<<endl;  //this line...
    }
    else{
        cout<<"Stack is not empty."<<endl;
    }

    return 0;

}
