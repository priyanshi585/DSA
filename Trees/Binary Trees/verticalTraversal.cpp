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

vector<int> verticalOrder(Node* root){
   map<int , map<int , vector<int>>> nodes;
   queue<pair<Node* , pair<int , int>>> q;
   vector<int> ans;

   if(root==NULL){
    return ans;
   }

   q.push(make_pair(root , make_pair(0,0)));

   while(!q.empty()){
    pair<Node* , pair<int,int>> temp = q.front();
    q.pop();

    Node* frontNode = temp.first;
    int hd = temp.second.first;
    int lvl = temp.second.second ;

    nodes[hd][lvl].push_back(frontNode->data);

    if(frontNode->left){
        q.push(make_pair(frontNode->left , make_pair(hd-1 ,lvl+1)));
    }
    if(frontNode->right){
        q.push(make_pair(frontNode->right , make_pair(hd+1 ,lvl+1)));
    }
   }

   for(auto  i  : nodes){
    for(auto j : i.second){
        for(auto k :j.second){
            ans.push_back(k);
        }
    }
   }

   return ans;
}

int main()
{
   Node* root = NULL;
   root = buildTree(root);
   cout<<endl;

   vector<int> result = verticalOrder(root);
   cout<<"Vertical Traversal of given Tree is: "<<endl;

   for(int i = 0; i<result.size();i++){
    cout<<result[i]<<" ";
   }
   cout<<endl;
   return 0;
}
