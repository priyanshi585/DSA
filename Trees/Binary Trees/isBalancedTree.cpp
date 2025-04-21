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

pair<bool,int> isBalancedFast(Node* root)
{
    if(root==NULL){
        pair<bool , int> p = make_pair(true,0);
        return p;
    }

    pair<int,int> left = isBalancedFast(root->left);
    pair<int,int> right = isBalancedFast(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool diff = abs(left.second - right.second)<=1 ;

    pair<bool,int> ans;
    ans.second = max(left.second , right.second)+1;

    if(leftAns && rightAns && diff){
        ans.first = true;
    }
    else{
        ans.first=false;
    }
}

bool isBalanced(Node* root){
    return isBalancedFast(root).first ;
}

int main()
{
   Node* root = NULL;
   root = buildTree(root);
   cout<<endl;

   if(isBalanced(root)){
    cout<<"Given Tree is Balanced."<<endl;
   }
   else{
    cout<<"Given Tree is Not Balanced."<<endl;
   }
   return 0;
}
