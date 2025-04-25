#include<iostream>
#include<climits>
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

void solve(Node* root , int sum , int &maxSum , int len , int &maxLen)
{
    if(root==NULL){
        if(len>maxLen){
            maxLen = len;
            maxSum = sum;
        }
        else if(len == maxLen){
            maxSum = max(sum , maxSum);
        }
        return ;
    }

    sum = sum + root->data;

    solve(root->left , sum , maxSum , len+1 ,maxLen);
    solve(root->right , sum , maxSum , len+1 ,maxLen);

}

int sumOfLongestBloodLine(Node* root)
{
    int len = 0;
    int sum  = 0;
    int maxSum = INT_MIN;
    int maxLen = 0;

    solve(root, sum , maxSum , len , maxLen);
    return maxSum;
}

int main()
{
   Node* root = NULL;
   root = buildTree(root);

   cout<<endl;
   int sum = sumOfLongestBloodLine(root);
   cout<<"Sum of Longest Bloodline of given tree is: "<<sum<<endl;
   return 0;
}
