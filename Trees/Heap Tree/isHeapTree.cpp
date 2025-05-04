#include<iostream>
using namespace std ;

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

int countNodes(Node* root){
    if(root==NULL){
        return 0;
    }

    int ans = 1 + countNodes(root->left) + countNodes(root->right);
    return ans;
}

bool isCBT(Node* root , int index , int cnt){
    if(root==NULL){
        return true;
    }
    if(index>=cnt){
        return false;
    }
    else{
        bool left = isCBT(root->left , 2*index+1 , cnt);
        bool right = isCBT(root->right , 2*index+2 , cnt);
        return (left && right);
    }
}

bool isMaxOrder(Node* root){
    if(root->left == NULL && root->right == NULL){
        return true;
    }

    if(root->right == NULL){
        return (root->data > root->left->data);
    }
    else{
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);

        if(left && right && (root->data > root->left->data && root->data > root->right->data)){
            return true;
        }
        else{
            return false;
        }
    }
}

bool isHeap(Node* tree){
    int index = 0 ;
    int totalCount = countNodes(tree);
    if(isCBT(tree , index , totalCount) && isMaxOrder(tree)){
        return true;
    }
    else{
        return false;
    }
}

int main()
{
   Node* root = NULL;
   root = buildTree(root);
   if(isHeap(root)){
    cout<<"Given Binary Tree is HEAP tree."<<endl;
   }
   else{
    cout<<"Given Binary Tree is NOT a Heap tree."<<endl;
   }
   return 0;
} 
