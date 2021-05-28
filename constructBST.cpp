//Build a BST from inorder
#include<iostream>
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

void printpreorder(Node* root)
{
    if(root==NULL)
    return;
    
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
Node* constructBST(int preorder[],int* preorderidx,int key,int min,int max,int n)//n is total no. of elements
{if(*preorderidx>=n)
{
    return NULL;
}
Node* root=NULL;//root is initialized with NULL value
if(key>min && key<max)//key will beconverted to the form of root only when thia condition is getting satisfied
{
root=new Node(key);//after this step we will update the value of preorder index variable to trace over the other values
*preorderidx=*preorderidx+1;

if(*preorderidx<n)
{
    root->left=constructBST(preorder,preorderidx,preorder[*preorderidx],min,key,n);
}
if(*preorderidx<n)
root->right=constructBST(preorder,preorderidx,preorder[*preorderidx],key,max,n);
}

return root;//this means that NULL will be returned if the above condition won't get satisfied
}
int main()
{
int preorder[]={10,2,1,13,11};
int n=5;
int preorderidx=0;
Node* constructBST(preorder,&preorderidx,preorder[0],INT_MIN,INT_MAX,n);
printpreorder(root);
return 0;
}