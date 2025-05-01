#include<iostream>
#include<queue>
#include<vector>
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

Node* solve(vector<int> &preorder , int min , int max, int &i)
{
    if(i>=preorder.size()){
        return NULL;
    }

    if(preorder[i]<min || preorder[i]>max){
        return NULL;
    }

    Node* root = new Node(preorder[i++]);
    root->left = solve(preorder,min ,root->data , i);
    root->right = solve(preorder , root->data , max , i);
    return root;
}

Node* preorderToBST(vector<int> &preorder)
{
    int mini = INT_MIN;
    int maxi = INT_MAX ;
    int i =0;
    return solve(preorder , mini , maxi , i);

}

int main()
{
    vector<int> preorder = {20 , 10 , 5 , 15 , 13 , 35 , 30 , 42};
    Node* ans = preorderToBST(preorder);
    
    cout<<"Printing BST from preorder: "<<endl;
    levelOrderTraversal(ans);
    return 0;
}
