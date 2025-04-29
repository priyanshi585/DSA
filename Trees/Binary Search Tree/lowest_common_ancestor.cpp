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

Node* lca(Node* root , int n1 , int n2)
{
    if(root==NULL){
        return NULL;
    }

    if(root->data < n1 && root->data < n2){
        return lca(root->right , n1 , n2);
    }

    if(root->data > n1 && root->data > n2){
        return lca(root->left , n1 , n2);
    }
    
    return root;
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
    int n1;
    cout<<"Enter the value of node1: "<<endl;
    cin>>n1;
    cout<<endl;

    int n2;
    cout<<"Enter the value of node2: "<<endl;
    cin>>n2;
    cout<<endl;

    Node* ans = lca(root , n1 , n2 );
    cout<<"Lowest Common Ancestor for given nodes is: "<<ans->data<<endl;

    return 0;
}
