#include<iostream>
#include<vector>
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

void traverseLeft(Node* root , vector<int> &ans){
    //base case:
    if((root==NULL) || (root->left == NULL && root->right==NULL)){
        return;
    }

    ans.push_back(root->data);
    if(root->left){
        traverseLeft(root->left , ans);
    }
    else{
        traverseLeft(root->right , ans);
    }
}

void traverseLeaf(Node* root , vector<int> &ans){
    if(root==NULL){
        return;
    }

    if(root->left == NULL && root->right==NULL){
        ans.push_back(root->data);
    }

    traverseLeaf(root->left , ans);
    traverseLeaf(root->right , ans);
}

void traverseRight(Node* root , vector<int> &ans){
    //base case:
    if((root==NULL) || (root->left == NULL && root->right==NULL)){
        return;
    }

    if(root->right){
        traverseRight(root->right , ans);
    }
    else{
        traverseRight(root->left , ans);
    }

    ans.push_back(root->data);
}

vector<int> boundary(Node* root)
{
    vector<int> ans ;
    if(root==NULL){
        return ans;
    }
    ans.push_back(root->data);

    //left part print:
    traverseLeft(root->left , ans);

    //leaf node print;
    traverseLeaf(root->left , ans);
    traverseLeaf(root->right , ans);

    //right part print;
    traverseRight(root->right , ans);

    return ans;
}

int main()
{
   Node* root = NULL;
   root = buildTree(root);

   vector<int> result = boundary(root);
   cout<<"Boundary Traversal of given Tree is: "<<endl;

   for(int i =0 ; i<result.size() ; i++){
       cout<<result[i]<<" ";
   }
   cout<<endl;
   return 0;
}
