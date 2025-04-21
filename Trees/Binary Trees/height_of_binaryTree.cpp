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

int getHeight(Node* root)
{
    if(root==NULL){
        return 0;
    }

    int left = getHeight(root->left);
    int right = getHeight(root->right);

    int ans = max(left,right) + 1;
    return ans;
}

int main()
{
   Node* root = NULL;
   root = buildTree(root);

   int height = getHeight(root);
   cout<<"Height of given Binary tree is: "<<height<<endl;
   return 0;
}
