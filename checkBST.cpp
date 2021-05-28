//TO CHECK IF A TREE IS A BST OR NOT

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

bool isBST(Node* root,Node* min=NULL,Node* max=NULL)//we have taken min and max as the minimum allowed and maximum allowed values respectively
{
    if(root==NULL)
    {
        return true;
    }
if(min!=NULL && root->data<=min->data)
{
    return false;
}
if(max!=NULL && root->data>=max->data)
{
    return false;
}

     bool leftvalid=isBST(root->left,min,root);
     bool rightvalid=isBST(root->right,root,max);
     return leftvalid and rightvalid;
}
int main()
{
    Node* root1=new Node(1);
    root1->left=new Node(2);
    root->right=new Node(3);
    if(isBST(root1,NULL,NULL))
    cout<<"validBST";
    elsecout<<"InvalidBST";
    return 0;
}