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

vector<int> morrisTraversal(Node* root)
{
    vector<int> ans ;
    Node* curr = root;
    while(curr!=NULL){
        if(curr->left==NULL){
            ans.push_back(curr->data);
            curr = curr->right;
        }
        else{
            Node* prev = curr->left;
            while(prev->right!=NULL && prev->right!=curr){
                 prev = prev->right;
            } 

            if(prev->right==NULL){
                prev->right = curr;
                curr= curr->left;
            }
            else{
                prev->right = NULL;
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }

    return ans;
}

int main()
{
   Node* root = NULL;
   root = buildTree(root);
   cout<<endl;

   vector<int> traversedTree = morrisTraversal(root);

   cout<<"Morris Traversal for the given tree is: ";
   for(int i =0;i<traversedTree.size();i++){
    cout<<traversedTree[i]<<" ";
   }
   
   cout<<endl;

   return 0;
}
