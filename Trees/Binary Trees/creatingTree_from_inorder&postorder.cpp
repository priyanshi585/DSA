#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;  
        this->left = NULL;
        this->right = NULL;
    }
};

int findPosition(int inorder[], int element, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (inorder[i] == element)
        {
            return i;
        }
    }
    return -1;
}

Node *solve(int inorder[], int postorder[], int &index, int inorderStart, int inorderEnd, int n)
{
    if (index < 0 || inorderStart > inorderEnd)
    {
        return NULL;
    }

    int element = postorder[index];
    index = index - 1;
    Node* root = new Node(element);
    int position = findPosition(inorder, element, n);

    root->right = solve(inorder, postorder, index, position + 1, inorderEnd, n);
    root->left = solve(inorder, postorder, index, inorderStart, position - 1, n);

    return root;
}

Node *buildTree(int inorder[], int postorder[], int n)
{
    int postorderIndex = n-1 ;

    Node* ans = solve(inorder, postorder, postorderIndex, 0, n - 1, n);
    return ans;
}

void preorder(Node* root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    Node* root = NULL;

    int inorder[100];
    int postorder[100];
    int size = 8;
    
    cout<<"Enter the elements of inorder traversal : "<<endl;
    for(int i=0;i<size;i++){
        cin>>inorder[i];
    }
    cout<<endl;

    cout<<"Enter the elements of postorder traversal : "<<endl;
    for(int i=0;i<size;i++){
        cin>>postorder[i];
    }
    cout<<endl;

    cout<<"Your InOrder Traversal array is: ";
    for(int i = 0;i<size;i++){
        cout<<inorder[i]<<" ";
    }
    cout<<endl;

    cout<<"Your PostOrder Traversal array is: ";
    for(int i = 0;i<size;i++){
        cout<<postorder[i]<<" ";
    }
    cout<<endl;


    root = buildTree(inorder, postorder, size);

    cout << endl;
    cout << "PostOrder  traversal of tree created from inorder and preorder is: ";
    preorder(root);
    cout<<endl;
    return 0;
}
