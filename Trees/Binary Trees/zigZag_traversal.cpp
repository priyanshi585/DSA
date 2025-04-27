#include<iostream>
#include<vector>
#include<queue>
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

vector<int> zigZagTraversal(Node* root)
{
   vector<int> result;
   if(root==NULL){
    return result;
   }

   queue<Node*> q;
   q.push(root);

   bool leftToRight = true;

   while(!q.empty()){
    int size = q.size();
    vector<int> ans(size);

    for(int i =0;i<size;i++){
        Node* frontNode = q.front();
        q.pop();

        int index = leftToRight ? i : size-i-1;
        ans[index] = frontNode->data;

        if(frontNode->left){
            q.push(frontNode->left);
        }
        if(frontNode->right){
            q.push(frontNode->right);
        }
    }
        leftToRight = !leftToRight ;

        for(auto i : ans){
            result.push_back(i);
        }
    }
    return result;
}

int main()
{
   Node* root = NULL;
   root = buildTree(root);

   vector<int> result = zigZagTraversal(root);
   cout<<"Zig Zag Traversal of given Tree is : "<<endl;

   for(int i = 0 ; i<result.size() ; i++){
    cout<<result[i]<<" ";
   }
   cout<<endl;
   
   return 0;
}
