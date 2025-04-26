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

pair<bool , int> isSumTreeFast(Node* root){
    if(root==NULL){
        pair<bool , int> p = make_pair(true,0);
        return p;
    }
    if(root->left == NULL && root->right==NULL){
        pair<bool,int> p = make_pair(true,root->data);
        return p;
    }

    pair<bool , int> leftAns = isSumTreeFast(root->left);
    pair<bool,int> rightAns = isSumTreeFast(root->right);

    bool left = leftAns.first;
    bool right =  rightAns.first;

    bool condition = root->data == leftAns.second + rightAns.second ;

    pair<bool , int> ans;
    if(left && right && condition){
        ans.first = true;
        ans.second = 2*root->data;
    }
    else{
        ans.first=false;
    }
    return ans;
}

bool isSumTree(Node* root){
    return isSumTreeFast(root).first;
}

int main()
{
   Node* root = NULL;
   root = buildTree(root);
   cout<<endl;
   cout<<endl;

   if(isSumTree(root)){
    cout<<"Given Tree is SUM TREE."<<endl;
   }
   else{
    cout<<"Given Tree is NOT a Sum Tree."<<endl;
   }
   return 0;
}
