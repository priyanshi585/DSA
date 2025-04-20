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

pair<int , int> diameterFast(Node* root)
{
    if(root==NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int , int> left = diameterFast(root->left);
    pair<int,int> right = diameterFast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int,int> ans ;
    ans.first = max(op1,max(op2,op3));
    ans.second = max(left.second , right.second)+1;
    return ans ;
}

int diameter(Node* root)
{
    return diameterFast(root).first;
}

int main()
{
   Node* root = NULL;
   root = buildTree(root);

   int ans = diameter(root);
   cout<<"\nDiameter of given binary tree is: "<<ans<<endl;
   return 0;
}
