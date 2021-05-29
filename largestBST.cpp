//Return the size of largest BST in a binary tree
#include<iostream>
#include<climits>
struct Node
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
struct info
{
    int max;
    int min;
    int size;
    int ans;
    bool isBST;
};
info islargestBST(Node* root)
{
    if(root==NULL)
    return {0,INT_MIN,INT_MAX,0,true};
    if(root->left==NULL && root->right==NULL)//case of the leaf node
    {
        return{1,root->data,root->data,1,true};
    }
    info leftinfo=islargestBST(root->left);
    info rightinfo=islargestBST(root->right);
info current;
current.size()=(1+leftinfo.size()+rightinfo.size());//this is for calaculating the current root
if(leftinfo.isBST && rightinfo.isBST && leftinfo.max<root->data && rightinfo.min>root->data)
{
    curr.min=min(leftinfo.min,min(rightinfo.min,root->data));
    curr.max=max(rightinfo.max,max(leftinfo.max,root->data));

    curr.ans=curr.size;
    curr.isBST=true;
    return curr;
}
curr.ans=max(leftinfo.ans,rightinfo.ans);
curr.isBST=false;
return curr;
}
int main()
{
    Node* root=new Node(15);
root->left=new Node(20);
root->right=new Node(30);
root->left->left=new Node(5);


cout<<"largest BST in BT : "<islargestBST(root).ans<<endl;
return 0;
}