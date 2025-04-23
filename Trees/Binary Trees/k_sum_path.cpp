#include<iostream>
#include<vector>
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

void solve(Node* root , int k , int &count , vector<int> path)
{
    if(root==NULL){
        return;
    }

    path.push_back(root->data);

    solve(root->left , k , count , path);
    solve(root->right , k , count , path);

    int size = path.size();
    int sum =0;
    for(int i = size-1 ;i>=0;i--){
        sum = sum + path[i];
        if(sum == k){
            count++;
        }
    }
    path.pop_back();

}

int sumK(Node* root ,int k)
{
    int count = 0;
    vector<int> path;
    solve(root , k , count , path);
    return count;
}

int main()
{
   Node* root = NULL;
   root = buildTree(root);

   cout<<endl;
   int k;
   cout<<"Enter the value of K: ";
   cin>>k;
   cout<<endl;
   int sum = sumK(root , k);
   cout<<"K Sum path for given tree is: "<<sum<<endl;
   return 0;
}
