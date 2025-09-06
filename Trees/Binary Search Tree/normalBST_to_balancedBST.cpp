#include<iostream>
#include<queue>
using namespace std;

class Node
{
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

Node* insertIntoBST(Node* root , int data)
{
    if(root==NULL)
    {
        root = new Node(data);
        return root;
    }

    if(data > root->data){
        root->right = insertIntoBST(root->right , data);
    }
    else{
        root->left = insertIntoBST(root->left , data);
    }

    return root;
}

void takeInput(Node* &root)
{
    int data ;
    cin>>data;

    while(data != -1){
        root = insertIntoBST(root , data);
        cin>>data;
    }
}

Node* levelOrderTraversal(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }

        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

void inorder(Node* root , vector<int> &in)
{
    if(root==NULL){
        return;
    }
    inorder(root->left  , in);
    in.push_back(root->data);
    inorder(root->right , in);
}

Node* inorderToBST(int s , int e , vector<int> &in)
{
    if(s>e){
        return NULL;
    }

    int mid = (s+e)/2 ;
    Node* root = new Node(in[mid]);
    root->left = inorderToBST(s , mid-1 , in);
    root->right = inorderToBST(mid+1 , e , in);
    return root ;
}

Node* balancedBST(Node* root)
{
    vector<int> inorderVal;
    inorder(root , inorderVal);
    return inorderToBST(0 , inorderVal.size()-1 , inorderVal);
}

int main()
{
    Node* root = NULL;
    cout<<"Enter the data for inserting in BST: "<<endl;
    takeInput(root);
    cout<<endl;

    cout<<"Printing Normal BST: "<<endl;
    levelOrderTraversal(root);

    cout<<endl;
    Node*  ans = balancedBST(root );
    cout<<"Printing Balanced BST: "<<endl;
    levelOrderTraversal(ans);
    cout<<endl;
    return 0;
}
