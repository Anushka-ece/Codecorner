//Sum of nodes in a binary tree
#include<iostream>
using namespace std;

int sumnodes(Node* root)
{
    if(root==NULL)
    return 0;
return (sumnodes(root->left)+sumnodes(root->right)+root->data);
}

int main()
{
 Node* root=new Node(1);
    root->left =new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left =new Node(6);
    root->right->right =new Node(7);
    cout<<sumnodes(root)<<endl;
    return 0;
}