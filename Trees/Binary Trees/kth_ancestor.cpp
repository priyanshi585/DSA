#include<iostream>
#include<climits>
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

Node* solve(Node* root , int &k , int node){
    if(root==NULL){
        return NULL;
    }
    if(root->data == node){
        return root;
    }

    Node* leftAns = solve(root->left , k , node);
    Node* rightAns = solve(root->right , k , node);

    if(leftAns !=NULL && rightAns == NULL){
        k--;
        if(k<=0){
            k = INT_MAX;
            return root;
        }
        return leftAns ;
    }

    if(leftAns ==NULL && rightAns != NULL){
        k--;
        if(k<=0){
            k = INT_MAX;
            return root;
        }
        return rightAns ;
    }
    return NULL;
}

int kthAncestor(Node* root , int k , int node){
    Node* ans = solve(root , k , node);
    if(ans==NULL || ans->data==node){
        return -1;
    }
    else{
        return ans->data;
    }
}

int main()
{
   Node* root = NULL;
   root = buildTree(root);

   cout<<endl;
   cout<<"Enter the value of k: ";
   int k;
   cin>>k;
   cout<<endl;
   cout<<"Enter the value of n: ";
   int n;
   cin>>n;
   cout<<endl;

   int ans = kthAncestor(root, k , n);
   cout<<"The kth ancestor of given binary tree with n is: "<<ans<<endl;
   return 0;
}
