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

void inorder(Node* root , vector<int> &in){
    if(root == NULL){
        return ;
    }

    inorder(root->left , in);
    in.push_back(root->data);
    inorder(root->right , in);
}

Node* flatten(Node* root){
    vector<int> inorderVal;
    inorder(root , inorderVal);
    int n = inorderVal.size();

    Node* newRoot = new Node(inorderVal[0]);
    Node* curr = newRoot ;

    for(int i = 1;i<n;i++){
        Node* temp = new Node(inorderVal[i]);
        curr->left = NULL;
        curr->right = temp;
        curr= temp;
    }
    curr->left = NULL;
    curr->right = NULL;

    return newRoot ;
}

void print(Node* root){
    Node* temp = root ;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp = temp->right;
    }
    cout<<endl;

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

    Node* ans = flatten(root);
    cout<<"Flatten Sorted List: "<<endl;
    print(ans);
    cout<<endl;
    return 0;
}
