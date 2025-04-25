#include<iostream>
#include<vector>
#include<map>
#include<queue>
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

void solve(Node* root , vector<int> &ans , int level)
{
    if(root==NULL){
        return;
    }

    if(level == ans.size()){
        ans.push_back(root->data);
    }

    solve(root->right , ans, level+1);
    solve(root->left , ans , level+1);
}

vector<int> rightView(Node* root)
{
    vector<int> ans;
    solve(root,ans,0);
    return ans;
}


int main()
{
   Node* root = NULL;
   root = buildTree(root);
   cout<<endl;

   vector<int> result = rightView(root);
   cout<<"Right View of given Tree is: "<<endl;

   for(int i = 0; i<result.size();i++){
    cout<<result[i]<<" ";
   }
   cout<<endl;
   return 0;
}
