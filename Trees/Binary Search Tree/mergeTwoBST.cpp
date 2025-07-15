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

void inorder(Node* root , vector<int> &in)
{
    if(root==NULL){
        return;
    }
    inorder(root->left , in);
    in.push_back(root->data);
    inorder(root->right , in);
}

vector<int> mergeArrays(vector<int> &a , vector<int> &b)
{
    vector<int> ans(a.size()+b.size());
    int i =0 , j= 0 , k= 0;

    while(i<a.size() && j<b.size()){
        if(a[i] < b[j]){
            ans[k++] = a[i];
            i++;
        }
        else{
            ans[k++] = b[j];
            j++;
        }
    }

    while(i<a.size()){
        ans[k++] = a[i];
        i++ ;
    }

    while(j<b.size()){
        ans[k++] = b[j];
        j++ ;
    }

    return ans;
}

Node* inorderToBST(int s , int e , vector<int> &in)
{
    if(s>e){
        return NULL;
    }

    int mid = (s+e)/2 ;
    Node* root = new Node(in[mid]);
    root->left = inorderToBST(s , mid-1 , in);
    root->right = inorderToBST(mid+1 , e , in);
    return root ;
}

Node* mergeBST(Node* root1 , Node* root2)
{
    vector<int> bst1 , bst2;
    inorder(root1 , bst1);
    inorder(root2 , bst2);

    vector<int> mergeArray = mergeArrays(bst1 , bst2);

    int s = 0;
    int e = mergeArray.size() - 1;

    return inorderToBST(s , e , mergeArray);
}

int main()
{
    Node* root1 = NULL;
    cout<<"Enter the data for inserting in BST: "<<endl;
    takeInput(root1);
    cout<<endl;
    cout<<"Printing BST: "<<endl;
    levelOrderTraversal(root1);
    cout<<endl;

    Node* root2 = NULL;
    cout<<"Enter the data for inserting in BST: "<<endl;
    takeInput(root2);
    cout<<endl;
    cout<<"Printing BST: "<<endl;
    levelOrderTraversal(root2);
    cout<<endl;

    Node* ans = mergeBST(root1 , root2);
    cout<<"Merged BST: "<<endl;
    levelOrderTraversal(ans);
    cout<<endl;
    return 0;
}
