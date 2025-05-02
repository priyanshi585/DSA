#include<iostream>
#include<queue>
#include<climits>
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

bool isBST(Node* root , int min , int max)
{
    if(root==NULL){
        return true;
    }

    if(root->data >=min && root->data<=max){
        bool left = isBST(root->left , min , root->data);
        bool right = isBST(root->right , root->data , max);
        return left && right;
    }
    else{
        return false;
    }
}

bool validateBST(Node* root)
{
    return isBST(root , INT_MIN , INT_MAX);
}

int main()
{
    Node* root = NULL;
    cout<<"Enter the data for inserting in BST: "<<endl;
    takeInput(root);
    cout<<endl;

    cout<<"Printing BST: "<<endl;
    levelOrderTraversal(root);
    cout<<endl;

    if(validateBST(root)){
        cout<<"Given BST is VALID."<<endl;
    }
    else{
        cout<<"Given BST is NOT VALID."<<endl;
    }
    return 0;
}
