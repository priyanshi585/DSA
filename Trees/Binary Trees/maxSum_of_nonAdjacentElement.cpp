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

pair<int , int> solve(Node* root){
    if(root==NULL){
        pair<int , int> p = make_pair(0,0);
        return p;
    }

    pair<int , int > left = solve(root->left);
    pair<int , int> right = solve(root->right);

    pair<int , int> ans;

    ans.first = root->data + left.second + right.second ;

    ans.second = max(left.first , left.second) + max(right.first, right.second);

    return ans;
}

int getMaxSum(Node* root){
    pair<int , int> ans = solve(root);
    return max(ans.first ,ans.second);
}

int main()
{
   Node* root = NULL;
   root = buildTree(root);
   cout<<endl;

   int maxSum = getMaxSum(root);
   cout<<"Maximum Sum of non adjacent Nodes in the given tree is: "<<maxSum<<endl;
   return 0;
}
