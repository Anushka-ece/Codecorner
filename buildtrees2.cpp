//Build a tree when inorder and postorder traversal sequences are given
#include<bits/stdc++.h>
using namespace std;
struct Node*(int val)
{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};
int search(int inorder[],int start,int end,int val)
{
    for(int i=start;i<=end;i++)
    {
        if(inorder[i]==val)
        {
            return i;
        }
    }
    return -1;
}
Node* buildtree(int postorder[],int inorder[],int start,int end)//this function will return us node pointer and node pointer here represents every node of our given tree
{                                                              //start and end pointers here represent starting and ending of inorder
static int idx=4;/starting from the last index of the postorder sequence
if(start>end)//this is the base condition here
{
    return NULL;
}
int val=postorder[idx];
idx--;
Node* curr=new Node(curr);
if(start==end)
{
    return curr;//this is the special condition considered when there is only one element in inorder sequence given or there is no left subtree and no right subtree is present
}
int pos=search(postorder,start,end,val);//this function is for assigning pos to element marked as curr
curr->right=buildtree(preorder,inorder,pos+1,end);
curr->left=buildtree(preorder,inorder,start,pos-1);
return curr;
}

void inorderprint(Node* root)
{if(root==NULL)
{
    return;
}
    inorderprint(root->left);
    cout<<root->data<<" ";
    inorderprint(root->right);
}

int main()
{
int postorder[]={4,2,5,3,1};
int inorder={4,2,1,5,3};
//buildtree
Node* root=buildtree(postorder,inorder,0,4);
inorderprint(root);
return 0;
}