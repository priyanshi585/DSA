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

Node *solve(int inorder[], int preorder[], int &index, int inorderStart, int inorderEnd, int n)
{
    if (index >= n || inorderStart > inorderEnd)
    {
        return NULL;
    }

    int element = preorder[index];
    index = index + 1;
    Node *root = new Node(element);
    int position = findPosition(inorder, element, n);

    root->left = solve(inorder, preorder, index, inorderStart, position - 1, n);
    root->right = solve(inorder, preorder, index, position + 1, inorderEnd, n);

    return root;
}

Node *buildTree(int inorder[], int preorder[], int n)
{
    int preorderIndex = 0;

    Node *ans = solve(inorder, preorder, preorderIndex, 0, n - 1, n);
    return ans;
}

void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    Node *root = NULL;

    int inorder[100];
    int preorder[100];
    int size = 4;
    
    cout<<"Enter the elements of inorder traversal : "<<endl;
    for(int i=0;i<size;i++){
        cin>>inorder[i];
    }
    cout<<endl;

    cout<<"Enter the elements of preorder traversal : "<<endl;
    for(int i=0;i<size;i++){
        cin>>preorder[i];
    }
    cout<<endl;

    cout<<"Your InOrder Traversal array is: ";
    for(int i = 0;i<size;i++){
        cout<<inorder[i]<<" ";
    }
    cout<<endl;

    cout<<"Your PreOrder Traversal array is: ";
    for(int i = 0;i<size;i++){
        cout<<preorder[i]<<" ";
    }
    cout<<endl;


    root = buildTree(inorder, preorder, size);

    cout << endl;
    cout << "PostOrder  traversal of tree created from inorder and preorder is: ";
    postorder(root);
    cout<<endl;
    return 0;
}
