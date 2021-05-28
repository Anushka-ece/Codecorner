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

Node* inordersuccessor(Node* root)
{
    Node* curr=root;
    while(curr && curr->left!=NULL)
    {
        curr=curr->left;
    }
    return curr;
}
//Case 1: Node is a leaf-Simply remove the node
//Case 2 : Node has 1 child- In this case we will replace the node with child and delete the node
//Case 3: Node has two children-1)Find the inorder successor first and we know that in BST,these are sorted nodes
                                //2)Replace the node with inorder successor
                                //3)Delete the node
Node* deleteinBST(Node* root,int key)
{
    if(key<root->data)
    {
        root->left=deleteinBST(root->left,key);
    }
    else if(key>root->data)
    {
        root->right=deleteinBST(root->right,key);
    }
    else if(key==root)
    {
if(root->left==NULL)
{
    Node* temp=root->right;
    free(root);
    return temp;
}
else if(root->right==NULL)
{
    Node* temp=root->left;
    free(root);
    return temp;
}//case 3 from here
Node* temp=inordersuccessor(root->right);
root->data=temp->data;
root->right=deleteinBST(root->right,temp->key);
}
return root;
}
void inorder(Node* root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
Node* root=new Node(4);
root->left=new Node(2);
root->right=new Node(5);
root->left->left=new Node(1);
root->left->right=new Node(3);
root->right->right=new Node(6);
inorder(root);
root=deleteinBST(root,5);
inorder(root);
return 0;
}