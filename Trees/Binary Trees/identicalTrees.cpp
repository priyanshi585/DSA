#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;  
        this->right = NULL;
    }
};

Node* buildTree(Node* root){
    cout<<"Enter data: "<<endl;
    int data;
    cin>>data;
    
    if(data == -1){
        return NULL;
    }

    root = new Node(data);

    cout<<"Enter data to insert in left of "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter data to insert in right of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

bool isIdentical(Node* r1 , Node* r2){
     if(r1==NULL && r2==NULL){
        return true;
     }
     if(r1==NULL && r2!=NULL){
        return false;
     }
     if(r1!=NULL && r2==NULL){
        return false;
     }

     bool left = isIdentical(r1->left , r2->left);
     bool right = isIdentical(r1->right , r2->right);

     bool value = r1->data == r2->data;

     if(left && right && value){
        return true;
     }
     else{
        return false;
     }
}

int main()
{
   Node* r1 = NULL;
   cout<<"Building Tree 1: "<<endl;
   r1 = buildTree(r1);

   cout<<endl;
   cout<<endl;

   cout<<"Building Tree 2: "<<endl;
   Node* r2 = NULL;
   r2 = buildTree(r2);

   cout<<endl;
   cout<<endl;

   if(isIdentical(r1,r2)){
    cout<<"Given Two Trees are IDENTICAL."<<endl;
   }
   else{
    cout<<"Given Two trees are NOT Identical."<<endl;
   }
   return 0;
}
