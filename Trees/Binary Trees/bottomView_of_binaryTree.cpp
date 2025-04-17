#include<iostream>
#include<vector>
#include<map>
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

vector<int> bottomView(Node* root)
{
    vector<int> ans;

    if(root==NULL){
        return ans;
    }

    map<int , int> topNode;
    queue<pair<Node* , int>> q;

    q.push(make_pair(root , 0));

    while(!q.empty())
    {
        pair<Node* , int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        topNode[hd] = frontNode->data;

        if(frontNode->left){
            q.push(make_pair(frontNode->left , hd-1));
        }

        if(frontNode->right){
            q.push(make_pair(frontNode->right , hd+1));
        }
    }

    for(auto i: topNode){
        ans.push_back(i.second);
    }
    return ans;
}


int main()
{
   Node* root = NULL;
   root = buildTree(root);
   cout<<endl;

   vector<int> result = bottomView(root);
   cout<<"Top View of given Tree is: "<<endl;

   for(int i = 0; i<result.size();i++){
    cout<<result[i]<<" ";
   }
   cout<<endl;
   return 0;
}
