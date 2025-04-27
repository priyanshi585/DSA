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

Node* minValue(Node* root)
{
    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

Node* deleteFromBST(Node* root , int val)
{
    if(root == NULL){
        return root;
    }

    if(root->data == val){

       //0 child:
       if(root->left == NULL && root->right == NULL){
        delete root ;
        return NULL;
       }

       //1 child:
       //left child:
       if(root->left != NULL  && root->right == NULL){
        Node* temp = root->left;
        delete  root;
        return temp;
       }

       //right child:
       if(root->left == NULL  && root->right != NULL){
        Node* temp = root->right;
        delete  root;
        return temp;
       }

       //2child: 
       if(root->left != NULL && root->right != NULL){
        int min = minValue(root->right)->data ;
        root->data = min; 
        root->right = deleteFromBST(root->right, min);
        return root;
       }
    }

    else if(root->data > val){
        root->left = deleteFromBST(root->left , val);
        return root;
    }
    else{
        root->right = deleteFromBST(root->right , val);
        return root;
    }
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
    deleteFromBST(root , 50);
    cout<<"Printing BST after deleting a node: "<<endl;
    levelOrderTraversal(root);
    return 0;
}
