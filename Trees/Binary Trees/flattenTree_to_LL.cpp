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

void flatten(Node* root)
{
    Node* curr = root;
    while(curr!=NULL){
        if(curr->left){
            Node* prev = curr->left;
            while(prev->right){
                prev= prev->right;
            }

            prev->right =  curr->right;
            curr->right= curr->left;
            curr->left = NULL;
        }
        curr= curr->right;
    }
}

void print(Node* root){
    Node* temp = root;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->right;
    }
    cout<<endl;
}

int main()
{
   Node* root = NULL;
   root = buildTree(root);
   cout<<endl;
   flatten(root);
   cout<<"Flatten linkedlist from given tree: ";
   print(root);
   cout<<endl;
   return 0;
}
