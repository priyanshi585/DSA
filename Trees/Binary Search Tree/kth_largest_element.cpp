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


int solve(Node* root , int &i , int k)
{

    if(root==NULL){
        return -1;
    }

    //R:
    int right = solve(root->right , i , k);
    if(right!=-1){
        return right;
    }

    //N:
    i++;
    if(i==k){
        return root->data;
    }

    //L:
    return solve(root->left, i ,k);
}



int kthLargest(Node* root , int  k){

    int i = 0;
    int ans = solve(root , i , k);
    return ans;
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
    
    int k = 3;
    int ans = kthLargest(root , k);
    cout<<"K-th largest element in BST is: "<<ans<<endl;
    return 0;
}
