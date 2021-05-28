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

Node* searchinBST(Node* root,int key)//return type is node here 
{if(root==NULL)//this condition can occur in two cases.First,when a NULL root is found and second when key is not found in the netire tree
return NULL;
if(root->data==key)
return root;
if(root->data>key)
return searchinBST(root->left,key);
if(root->data<key)
return searchinBST(root->right,key);
}
int main()
{
Node* root=new Node(4);
root->left=new Node(2);
root->right=new Node(5);
root->left->left=new Node(1);
root->left->right=new Node(3);
root->right->right=new Node(6);
if(searchinBST(root,5)==NULL)
{
cout<<"not exist";
}
else
cout<<"exist";
return 0;
}