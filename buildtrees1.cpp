//Build a tree when inorder and preorder traversal sequences are given
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
int search(int inorder[],int start,int end,int curr)
{
    for(int i=start;i<=end;i++)
    {
        if(inorder[i]==curr)
        {
            return i;
        }
    }
    return -1;
}
Node* buildtree(int preorder[],int inorder[],int start,int end)//this function will return us node pointer and node pointer here represents every node of our given tree
{                                                              //start and end pointers here represent starting and ending of inorder
static int idx=0;
if(start>end)//this is the base condition here
{
    return NULL;
}
int curr=preorder[idx];
idx++;
Node* node=new Node(curr);
if(start==end)
{
    return node;//this is the special condition considered when there is only one element in inorder sequence given
}
int pos=search(inorder,start,end,curr);//this function is for assigning pos to element marked as curr
node->left=buildtree(preorder,inorder,start,pos-1);
node->right=buildtree(preorder,inorder,pos+1,end);
return node;
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
int preorder[]={1,2,4,3,5};
int inorder={4,2,1,5,3};
//buildtree
Node* root=buildtree(preorder,inorder,0,4);
inorderprint(root);
return 0;
}