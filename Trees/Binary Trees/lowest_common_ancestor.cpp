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

Node* lca(Node* root , int n1 , int n2)
{
    if(root==NULL){
        return NULL;
    }

    if(root->data == n1 || root->data == n2){
        return root;
    }

    Node* leftAns = lca(root->left , n1 , n2);
    Node* rightAns = lca(root->right , n1 , n2);

    if(leftAns != NULL && rightAns!=NULL){
        return root;
    }
    else if(leftAns != NULL && rightAns==NULL){
        return leftAns;
    }
    else if(leftAns == NULL && rightAns!=NULL){
        return rightAns;
    }
    else{
        return NULL;
    }
}

int main()
{
   Node* root = NULL;
   root = buildTree(root);
   cout<<endl;
   int n1 ,n2;
   cout<<"Enter the value of n1: ";
   cin>>n1;
   cout<<"Enter the value of n2: ";
   cin>>n2;

   Node* ans = lca(root , n1 ,n2);
   cout<<"Lowest Common Ancestor of given binary tree with n1 and n2 is: "<<ans->data<<endl;
   return 0;
}
